# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lakshyajit/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lakshyajit/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/longestconsecutiveones.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/longestconsecutiveones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/longestconsecutiveones.dir/flags.make

CMakeFiles/longestconsecutiveones.dir/main.cpp.o: CMakeFiles/longestconsecutiveones.dir/flags.make
CMakeFiles/longestconsecutiveones.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/longestconsecutiveones.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/longestconsecutiveones.dir/main.cpp.o -c /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/main.cpp

CMakeFiles/longestconsecutiveones.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/longestconsecutiveones.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/main.cpp > CMakeFiles/longestconsecutiveones.dir/main.cpp.i

CMakeFiles/longestconsecutiveones.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/longestconsecutiveones.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/main.cpp -o CMakeFiles/longestconsecutiveones.dir/main.cpp.s

# Object files for target longestconsecutiveones
longestconsecutiveones_OBJECTS = \
"CMakeFiles/longestconsecutiveones.dir/main.cpp.o"

# External object files for target longestconsecutiveones
longestconsecutiveones_EXTERNAL_OBJECTS =

longestconsecutiveones: CMakeFiles/longestconsecutiveones.dir/main.cpp.o
longestconsecutiveones: CMakeFiles/longestconsecutiveones.dir/build.make
longestconsecutiveones: CMakeFiles/longestconsecutiveones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable longestconsecutiveones"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/longestconsecutiveones.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/longestconsecutiveones.dir/build: longestconsecutiveones

.PHONY : CMakeFiles/longestconsecutiveones.dir/build

CMakeFiles/longestconsecutiveones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/longestconsecutiveones.dir/cmake_clean.cmake
.PHONY : CMakeFiles/longestconsecutiveones.dir/clean

CMakeFiles/longestconsecutiveones.dir/depend:
	cd /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug /home/lakshyajit/workspace/C++/DSA5/longestconsecutiveones/cmake-build-debug/CMakeFiles/longestconsecutiveones.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/longestconsecutiveones.dir/depend

