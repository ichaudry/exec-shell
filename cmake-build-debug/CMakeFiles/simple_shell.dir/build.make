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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/abechaudry/Github/simple-shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/abechaudry/Github/simple-shell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/simple_shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_shell.dir/flags.make

CMakeFiles/simple_shell.dir/main.c.o: CMakeFiles/simple_shell.dir/flags.make
CMakeFiles/simple_shell.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/abechaudry/Github/simple-shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/simple_shell.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/simple_shell.dir/main.c.o   -c /Users/abechaudry/Github/simple-shell/main.c

CMakeFiles/simple_shell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simple_shell.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/abechaudry/Github/simple-shell/main.c > CMakeFiles/simple_shell.dir/main.c.i

CMakeFiles/simple_shell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simple_shell.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/abechaudry/Github/simple-shell/main.c -o CMakeFiles/simple_shell.dir/main.c.s

# Object files for target simple_shell
simple_shell_OBJECTS = \
"CMakeFiles/simple_shell.dir/main.c.o"

# External object files for target simple_shell
simple_shell_EXTERNAL_OBJECTS =

simple_shell: CMakeFiles/simple_shell.dir/main.c.o
simple_shell: CMakeFiles/simple_shell.dir/build.make
simple_shell: CMakeFiles/simple_shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/abechaudry/Github/simple-shell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable simple_shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_shell.dir/build: simple_shell

.PHONY : CMakeFiles/simple_shell.dir/build

CMakeFiles/simple_shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_shell.dir/clean

CMakeFiles/simple_shell.dir/depend:
	cd /Users/abechaudry/Github/simple-shell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/abechaudry/Github/simple-shell /Users/abechaudry/Github/simple-shell /Users/abechaudry/Github/simple-shell/cmake-build-debug /Users/abechaudry/Github/simple-shell/cmake-build-debug /Users/abechaudry/Github/simple-shell/cmake-build-debug/CMakeFiles/simple_shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_shell.dir/depend

