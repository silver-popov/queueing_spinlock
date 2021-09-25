cmake_minimum_required (VERSION 3.8)

project ("TestSpinLock")

add_executable ("TestSpinLock" "TestSpinLock.cpp")
include_directories ("googletest/googletest/include" "..")
add_subdirectory ("googletest")
target_link_libraries ("TestSpinLock" PUBLIC "queueing_spinlock" "gtest_main")
