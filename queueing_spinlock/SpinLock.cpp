// Queued spin lock algorithm based on:
// Algorithms for Scalable Synchronization on
// Shared Memory Multiprocessors
// John M. Mellor-Crummey, Michael L. Scott
// http://www.cs.rice.edu/~johnmc/papers/tocs91.pdf

#include "SpinLock.h"

namespace queueing_spinlock {

using namespace std;

void SpinLock::acquire (SpinLockNode& node) noexcept
{
	node.sn_next_ = nullptr;
	SpinLockNode* predecessor = last_.exchange (&node);
	if (predecessor) {
		// Queue was non-empty
		node.sn_locked_ = 1;
		predecessor->sn_next_ = &node;
		while (node.sn_locked_)
			;
	}
}

void SpinLock::release (SpinLockNode& node) noexcept
{
	if (!node.sn_next_) {
		// No known successor
		for (;;) {

			// If this node is last, clear and return
			SpinLockNode* pnode = &node;
			if (last_.compare_exchange_weak (pnode, nullptr))
				return;

			// Wait for a successor
			if (node.sn_next_)
				break;
		}
	}
	node.sn_next_->sn_locked_ = 0; // Unlock the successor
}

}
