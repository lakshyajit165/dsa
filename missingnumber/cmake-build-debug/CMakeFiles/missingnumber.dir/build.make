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
CMAKE_SOURCE_DIR = /home/lakshyajit/workspace/C++/DSA5/missingnumber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/missingnumber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/missingnumber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/missingnumber.dir/flags.make

CMakeFiles/missingnumber.dir/main.cpp.o: CMakeFiles/missingnumber.dir/flags.make
CMakeFiles/missingnumber.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/missingnumber.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/missingnumber.dir/main.cpp.o -c /home/lakshyajit/workspace/C++/DSA5/missingnumber/main.cpp

CMakeFiles/missingnumber.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/missingnumber.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lakshyajit/workspace/C++/DSA5/missingnumber/main.cpp > CMakeFiles/missingnumber.dir/main.cpp.i

CMakeFiles/missingnumber.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/missingnumber.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lakshyajit/workspace/C++/DSA5/missingnumber/main.cpp -o CMakeFiles/missingnumber.dir/main.cpp.s

# Object files for target missingnumber
missingnumber_OBJECTS = \
"CMakeFiles/missingnumber.dir/main.cpp.o"

# External object files for target missingnumber
missingnumber_EXTERNAL_OBJECTS =

missingnumber: CMakeFiles/missingnumber.dir/main.cpp.o
missingnumber: CMakeFiles/missingnumber.dir/build.make
missingnumber: CMakeFiles/missingnumber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable missingnumber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/missingnumber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/missingnumber.dir/build: missingnumber

.PHONY : CMakeFiles/missingnumber.dir/build

CMakeFiles/missingnumber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/missingnumber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/missingnumber.dir/clean

CMakeFiles/missingnumber.dir/depend:
	cd /home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lakshyajit/workspace/C++/DSA5/missingnumber /home/lakshyajit/workspace/C++/DSA5/missingnumber /home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug /home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug /home/lakshyajit/workspace/C++/DSA5/missingnumber/cmake-build-debug/CMakeFiles/missingnumber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/missingnumber.dir/depend

