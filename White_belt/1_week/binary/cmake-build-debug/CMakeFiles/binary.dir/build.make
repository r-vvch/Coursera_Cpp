# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roman/My/Coursera/Coursera_Cpp/1_week/binary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/binary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary.dir/flags.make

CMakeFiles/binary.dir/main.cpp.o: CMakeFiles/binary.dir/flags.make
CMakeFiles/binary.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary.dir/main.cpp.o -c /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/main.cpp

CMakeFiles/binary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/main.cpp > CMakeFiles/binary.dir/main.cpp.i

CMakeFiles/binary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/main.cpp -o CMakeFiles/binary.dir/main.cpp.s

# Object files for target binary
binary_OBJECTS = \
"CMakeFiles/binary.dir/main.cpp.o"

# External object files for target binary
binary_EXTERNAL_OBJECTS =

binary: CMakeFiles/binary.dir/main.cpp.o
binary: CMakeFiles/binary.dir/build.make
binary: CMakeFiles/binary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary.dir/build: binary

.PHONY : CMakeFiles/binary.dir/build

CMakeFiles/binary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary.dir/clean

CMakeFiles/binary.dir/depend:
	cd /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/My/Coursera/Coursera_Cpp/1_week/binary /home/roman/My/Coursera/Coursera_Cpp/1_week/binary /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug /home/roman/My/Coursera/Coursera_Cpp/1_week/binary/cmake-build-debug/CMakeFiles/binary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary.dir/depend

