# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zouyi/Desktop/slam14/code/ch3/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zouyi/Desktop/slam14/code/ch3/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/coordinate_transform.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/coordinate_transform.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/coordinate_transform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coordinate_transform.dir/flags.make

CMakeFiles/coordinate_transform.dir/coordinate_transform.o: CMakeFiles/coordinate_transform.dir/flags.make
CMakeFiles/coordinate_transform.dir/coordinate_transform.o: ../coordinate_transform.cpp
CMakeFiles/coordinate_transform.dir/coordinate_transform.o: CMakeFiles/coordinate_transform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zouyi/Desktop/slam14/code/ch3/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coordinate_transform.dir/coordinate_transform.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/coordinate_transform.dir/coordinate_transform.o -MF CMakeFiles/coordinate_transform.dir/coordinate_transform.o.d -o CMakeFiles/coordinate_transform.dir/coordinate_transform.o -c /home/zouyi/Desktop/slam14/code/ch3/examples/coordinate_transform.cpp

CMakeFiles/coordinate_transform.dir/coordinate_transform.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coordinate_transform.dir/coordinate_transform.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zouyi/Desktop/slam14/code/ch3/examples/coordinate_transform.cpp > CMakeFiles/coordinate_transform.dir/coordinate_transform.i

CMakeFiles/coordinate_transform.dir/coordinate_transform.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coordinate_transform.dir/coordinate_transform.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zouyi/Desktop/slam14/code/ch3/examples/coordinate_transform.cpp -o CMakeFiles/coordinate_transform.dir/coordinate_transform.s

# Object files for target coordinate_transform
coordinate_transform_OBJECTS = \
"CMakeFiles/coordinate_transform.dir/coordinate_transform.o"

# External object files for target coordinate_transform
coordinate_transform_EXTERNAL_OBJECTS =

coordinate_transform: CMakeFiles/coordinate_transform.dir/coordinate_transform.o
coordinate_transform: CMakeFiles/coordinate_transform.dir/build.make
coordinate_transform: CMakeFiles/coordinate_transform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zouyi/Desktop/slam14/code/ch3/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable coordinate_transform"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coordinate_transform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coordinate_transform.dir/build: coordinate_transform
.PHONY : CMakeFiles/coordinate_transform.dir/build

CMakeFiles/coordinate_transform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coordinate_transform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coordinate_transform.dir/clean

CMakeFiles/coordinate_transform.dir/depend:
	cd /home/zouyi/Desktop/slam14/code/ch3/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zouyi/Desktop/slam14/code/ch3/examples /home/zouyi/Desktop/slam14/code/ch3/examples /home/zouyi/Desktop/slam14/code/ch3/examples/build /home/zouyi/Desktop/slam14/code/ch3/examples/build /home/zouyi/Desktop/slam14/code/ch3/examples/build/CMakeFiles/coordinate_transform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coordinate_transform.dir/depend

