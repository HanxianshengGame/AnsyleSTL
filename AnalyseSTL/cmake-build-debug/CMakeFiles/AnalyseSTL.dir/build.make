# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:\AnalyseSTL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:\AnalyseSTL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AnalyseSTL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AnalyseSTL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AnalyseSTL.dir/flags.make

CMakeFiles/AnalyseSTL.dir/main.cpp.obj: CMakeFiles/AnalyseSTL.dir/flags.make
CMakeFiles/AnalyseSTL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\AnalyseSTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AnalyseSTL.dir/main.cpp.obj"
	G:\MINGW64-8.1\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AnalyseSTL.dir\main.cpp.obj -c H:\AnalyseSTL\main.cpp

CMakeFiles/AnalyseSTL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnalyseSTL.dir/main.cpp.i"
	G:\MINGW64-8.1\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\AnalyseSTL\main.cpp > CMakeFiles\AnalyseSTL.dir\main.cpp.i

CMakeFiles/AnalyseSTL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnalyseSTL.dir/main.cpp.s"
	G:\MINGW64-8.1\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\AnalyseSTL\main.cpp -o CMakeFiles\AnalyseSTL.dir\main.cpp.s

CMakeFiles/AnalyseSTL.dir/MyVector.cpp.obj: CMakeFiles/AnalyseSTL.dir/flags.make
CMakeFiles/AnalyseSTL.dir/MyVector.cpp.obj: ../MyVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=H:\AnalyseSTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AnalyseSTL.dir/MyVector.cpp.obj"
	G:\MINGW64-8.1\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AnalyseSTL.dir\MyVector.cpp.obj -c H:\AnalyseSTL\MyVector.cpp

CMakeFiles/AnalyseSTL.dir/MyVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnalyseSTL.dir/MyVector.cpp.i"
	G:\MINGW64-8.1\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:\AnalyseSTL\MyVector.cpp > CMakeFiles\AnalyseSTL.dir\MyVector.cpp.i

CMakeFiles/AnalyseSTL.dir/MyVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnalyseSTL.dir/MyVector.cpp.s"
	G:\MINGW64-8.1\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:\AnalyseSTL\MyVector.cpp -o CMakeFiles\AnalyseSTL.dir\MyVector.cpp.s

# Object files for target AnalyseSTL
AnalyseSTL_OBJECTS = \
"CMakeFiles/AnalyseSTL.dir/main.cpp.obj" \
"CMakeFiles/AnalyseSTL.dir/MyVector.cpp.obj"

# External object files for target AnalyseSTL
AnalyseSTL_EXTERNAL_OBJECTS =

AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/main.cpp.obj
AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/MyVector.cpp.obj
AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/build.make
AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/linklibs.rsp
AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/objects1.rsp
AnalyseSTL.exe: CMakeFiles/AnalyseSTL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=H:\AnalyseSTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AnalyseSTL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AnalyseSTL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AnalyseSTL.dir/build: AnalyseSTL.exe

.PHONY : CMakeFiles/AnalyseSTL.dir/build

CMakeFiles/AnalyseSTL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AnalyseSTL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AnalyseSTL.dir/clean

CMakeFiles/AnalyseSTL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" H:\AnalyseSTL H:\AnalyseSTL H:\AnalyseSTL\cmake-build-debug H:\AnalyseSTL\cmake-build-debug H:\AnalyseSTL\cmake-build-debug\CMakeFiles\AnalyseSTL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AnalyseSTL.dir/depend
