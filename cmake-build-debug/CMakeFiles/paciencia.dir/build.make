# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/paciencia.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/paciencia.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paciencia.dir/flags.make

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj: CMakeFiles/paciencia.dir/flags.make
CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj: ../SpiderSolitaire.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\paciencia.dir\SpiderSolitaire.cpp.obj -c C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\SpiderSolitaire.cpp

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\SpiderSolitaire.cpp > CMakeFiles\paciencia.dir\SpiderSolitaire.cpp.i

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\SpiderSolitaire.cpp -o CMakeFiles\paciencia.dir\SpiderSolitaire.cpp.s

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.requires:

.PHONY : CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.requires

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.provides: CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.requires
	$(MAKE) -f CMakeFiles\paciencia.dir\build.make CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.provides.build
.PHONY : CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.provides

CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.provides.build: CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj


# Object files for target paciencia
paciencia_OBJECTS = \
"CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj"

# External object files for target paciencia
paciencia_EXTERNAL_OBJECTS =

paciencia.exe: CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj
paciencia.exe: CMakeFiles/paciencia.dir/build.make
paciencia.exe: CMakeFiles/paciencia.dir/linklibs.rsp
paciencia.exe: CMakeFiles/paciencia.dir/objects1.rsp
paciencia.exe: CMakeFiles/paciencia.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable paciencia.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\paciencia.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paciencia.dir/build: paciencia.exe

.PHONY : CMakeFiles/paciencia.dir/build

CMakeFiles/paciencia.dir/requires: CMakeFiles/paciencia.dir/SpiderSolitaire.cpp.obj.requires

.PHONY : CMakeFiles/paciencia.dir/requires

CMakeFiles/paciencia.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\paciencia.dir\cmake_clean.cmake
.PHONY : CMakeFiles/paciencia.dir/clean

CMakeFiles/paciencia.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug C:\Users\Robson\workspace18.1\PLP\paciencia_spider_plp\cmake-build-debug\CMakeFiles\paciencia.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paciencia.dir/depend
