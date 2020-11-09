// Queueing spin lock algorithm based on:
// Algorithms for Scalable Synchronization on
// Shared Memory Multiprocessors
// John M. Mellor-Crummey, Michael L. Scott
// http://www.cs.rice.edu/~johnmc/papers/tocs91.pdf

#ifndef QUEUEINGSPINLOCK_H_
#define QUEUEINGSPINLOCK_H_

#include <atomic>

namespace queueing_spinlock {

class SpinLock;

class SpinLockNode
{
	SpinLockNode (const SpinLockNode&) = delete;
	SpinLockNode& operator = (const SpinLockNode&) = delete;
public:
	SpinLockNode () noexcept :
		sn_locked_ (0)
	{}

private:
	friend class SpinLock;
	volatile int sn_locked_;
	SpinLockNode* volatile sn_next_;
};

class SpinLock
{
	SpinLock (const SpinLock&) = delete;
	SpinLock& operator = (const SpinLock&) = delete;
public:
	SpinLock () noexcept :
		last_ (nullptr)
	{}

	void acquire (SpinLockNode& node) noexcept;
	void release (SpinLockNode& node) noexcept;

private:
	std::atomic <SpinLockNode*> last_;
};

}

#endif
