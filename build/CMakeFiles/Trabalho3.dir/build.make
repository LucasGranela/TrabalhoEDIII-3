# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/logranela/ED3/TrabalhoEDIII-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/logranela/ED3/TrabalhoEDIII-3/build

# Include any dependencies generated for this target.
include CMakeFiles/Trabalho3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Trabalho3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trabalho3.dir/flags.make

CMakeFiles/Trabalho3.dir/main.c.o: CMakeFiles/Trabalho3.dir/flags.make
CMakeFiles/Trabalho3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Trabalho3.dir/main.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Trabalho3.dir/main.c.o   -c /home/logranela/ED3/TrabalhoEDIII-3/main.c

CMakeFiles/Trabalho3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Trabalho3.dir/main.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/TrabalhoEDIII-3/main.c > CMakeFiles/Trabalho3.dir/main.c.i

CMakeFiles/Trabalho3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Trabalho3.dir/main.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/TrabalhoEDIII-3/main.c -o CMakeFiles/Trabalho3.dir/main.c.s

CMakeFiles/Trabalho3.dir/fornecido.c.o: CMakeFiles/Trabalho3.dir/flags.make
CMakeFiles/Trabalho3.dir/fornecido.c.o: ../fornecido.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Trabalho3.dir/fornecido.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Trabalho3.dir/fornecido.c.o   -c /home/logranela/ED3/TrabalhoEDIII-3/fornecido.c

CMakeFiles/Trabalho3.dir/fornecido.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Trabalho3.dir/fornecido.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/TrabalhoEDIII-3/fornecido.c > CMakeFiles/Trabalho3.dir/fornecido.c.i

CMakeFiles/Trabalho3.dir/fornecido.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Trabalho3.dir/fornecido.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/TrabalhoEDIII-3/fornecido.c -o CMakeFiles/Trabalho3.dir/fornecido.c.s

CMakeFiles/Trabalho3.dir/queue.c.o: CMakeFiles/Trabalho3.dir/flags.make
CMakeFiles/Trabalho3.dir/queue.c.o: ../queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Trabalho3.dir/queue.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Trabalho3.dir/queue.c.o   -c /home/logranela/ED3/TrabalhoEDIII-3/queue.c

CMakeFiles/Trabalho3.dir/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Trabalho3.dir/queue.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/TrabalhoEDIII-3/queue.c > CMakeFiles/Trabalho3.dir/queue.c.i

CMakeFiles/Trabalho3.dir/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Trabalho3.dir/queue.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/TrabalhoEDIII-3/queue.c -o CMakeFiles/Trabalho3.dir/queue.c.s

CMakeFiles/Trabalho3.dir/stack.c.o: CMakeFiles/Trabalho3.dir/flags.make
CMakeFiles/Trabalho3.dir/stack.c.o: ../stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Trabalho3.dir/stack.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Trabalho3.dir/stack.c.o   -c /home/logranela/ED3/TrabalhoEDIII-3/stack.c

CMakeFiles/Trabalho3.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Trabalho3.dir/stack.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/TrabalhoEDIII-3/stack.c > CMakeFiles/Trabalho3.dir/stack.c.i

CMakeFiles/Trabalho3.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Trabalho3.dir/stack.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/TrabalhoEDIII-3/stack.c -o CMakeFiles/Trabalho3.dir/stack.c.s

CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o: CMakeFiles/Trabalho3.dir/flags.make
CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o: ../grafoListaAdjacencia.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o   -c /home/logranela/ED3/TrabalhoEDIII-3/grafoListaAdjacencia.c

CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.i"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/logranela/ED3/TrabalhoEDIII-3/grafoListaAdjacencia.c > CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.i

CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.s"
	/bin/c99-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/logranela/ED3/TrabalhoEDIII-3/grafoListaAdjacencia.c -o CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.s

# Object files for target Trabalho3
Trabalho3_OBJECTS = \
"CMakeFiles/Trabalho3.dir/main.c.o" \
"CMakeFiles/Trabalho3.dir/fornecido.c.o" \
"CMakeFiles/Trabalho3.dir/queue.c.o" \
"CMakeFiles/Trabalho3.dir/stack.c.o" \
"CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o"

# External object files for target Trabalho3
Trabalho3_EXTERNAL_OBJECTS =

Trabalho3: CMakeFiles/Trabalho3.dir/main.c.o
Trabalho3: CMakeFiles/Trabalho3.dir/fornecido.c.o
Trabalho3: CMakeFiles/Trabalho3.dir/queue.c.o
Trabalho3: CMakeFiles/Trabalho3.dir/stack.c.o
Trabalho3: CMakeFiles/Trabalho3.dir/grafoListaAdjacencia.c.o
Trabalho3: CMakeFiles/Trabalho3.dir/build.make
Trabalho3: CMakeFiles/Trabalho3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Trabalho3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Trabalho3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trabalho3.dir/build: Trabalho3

.PHONY : CMakeFiles/Trabalho3.dir/build

CMakeFiles/Trabalho3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Trabalho3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Trabalho3.dir/clean

CMakeFiles/Trabalho3.dir/depend:
	cd /home/logranela/ED3/TrabalhoEDIII-3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/logranela/ED3/TrabalhoEDIII-3 /home/logranela/ED3/TrabalhoEDIII-3 /home/logranela/ED3/TrabalhoEDIII-3/build /home/logranela/ED3/TrabalhoEDIII-3/build /home/logranela/ED3/TrabalhoEDIII-3/build/CMakeFiles/Trabalho3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Trabalho3.dir/depend

