﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("queueing_spinlock")

# Include sub-projects.
add_subdirectory ("queueing_spinlock")
add_subdirectory ("test")
