# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /apps/sylar/bin/cmake

# The command to remove a file.
RM = /apps/sylar/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/log4cpp_Prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/log4cpp_Prj/bulid

# Include any dependencies generated for this target.
include myprj/process/CMakeFiles/process.dir/depend.make

# Include the progress variables for this target.
include myprj/process/CMakeFiles/process.dir/progress.make

# Include the compile flags for this target's objects.
include myprj/process/CMakeFiles/process.dir/flags.make

myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.o: myprj/process/CMakeFiles/process.dir/flags.make
myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.o: ../myprj/process/source/fork_fortest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/log4cpp_Prj/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.o"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/process.dir/source/fork_fortest.c.o   -c /home/log4cpp_Prj/myprj/process/source/fork_fortest.c

myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/process.dir/source/fork_fortest.c.i"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/log4cpp_Prj/myprj/process/source/fork_fortest.c > CMakeFiles/process.dir/source/fork_fortest.c.i

myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/process.dir/source/fork_fortest.c.s"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/log4cpp_Prj/myprj/process/source/fork_fortest.c -o CMakeFiles/process.dir/source/fork_fortest.c.s

myprj/process/CMakeFiles/process.dir/source/myfun.c.o: myprj/process/CMakeFiles/process.dir/flags.make
myprj/process/CMakeFiles/process.dir/source/myfun.c.o: ../myprj/process/source/myfun.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/log4cpp_Prj/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object myprj/process/CMakeFiles/process.dir/source/myfun.c.o"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/process.dir/source/myfun.c.o   -c /home/log4cpp_Prj/myprj/process/source/myfun.c

myprj/process/CMakeFiles/process.dir/source/myfun.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/process.dir/source/myfun.c.i"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/log4cpp_Prj/myprj/process/source/myfun.c > CMakeFiles/process.dir/source/myfun.c.i

myprj/process/CMakeFiles/process.dir/source/myfun.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/process.dir/source/myfun.c.s"
	cd /home/log4cpp_Prj/bulid/myprj/process && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/log4cpp_Prj/myprj/process/source/myfun.c -o CMakeFiles/process.dir/source/myfun.c.s

# Object files for target process
process_OBJECTS = \
"CMakeFiles/process.dir/source/fork_fortest.c.o" \
"CMakeFiles/process.dir/source/myfun.c.o"

# External object files for target process
process_EXTERNAL_OBJECTS =

../deploy/process: myprj/process/CMakeFiles/process.dir/source/fork_fortest.c.o
../deploy/process: myprj/process/CMakeFiles/process.dir/source/myfun.c.o
../deploy/process: myprj/process/CMakeFiles/process.dir/build.make
../deploy/process: myprj/process/CMakeFiles/process.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/log4cpp_Prj/bulid/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../../../deploy/process"
	cd /home/log4cpp_Prj/bulid/myprj/process && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/process.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
myprj/process/CMakeFiles/process.dir/build: ../deploy/process

.PHONY : myprj/process/CMakeFiles/process.dir/build

myprj/process/CMakeFiles/process.dir/clean:
	cd /home/log4cpp_Prj/bulid/myprj/process && $(CMAKE_COMMAND) -P CMakeFiles/process.dir/cmake_clean.cmake
.PHONY : myprj/process/CMakeFiles/process.dir/clean

myprj/process/CMakeFiles/process.dir/depend:
	cd /home/log4cpp_Prj/bulid && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/log4cpp_Prj /home/log4cpp_Prj/myprj/process /home/log4cpp_Prj/bulid /home/log4cpp_Prj/bulid/myprj/process /home/log4cpp_Prj/bulid/myprj/process/CMakeFiles/process.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : myprj/process/CMakeFiles/process.dir/depend

