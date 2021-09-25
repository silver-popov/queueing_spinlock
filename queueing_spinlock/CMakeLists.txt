# CMakeList.txt : CMake project for queueing_spinlock, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("queueing_spinlock")

# Add source to this project's executable.
add_library ("queueing_spinlock" STATIC "SpinLock.cpp")

# TODO: Add tests and install targets if needed.
