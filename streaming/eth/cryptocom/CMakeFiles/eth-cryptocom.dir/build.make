# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming

# Include any dependencies generated for this target.
include eth/cryptocom/CMakeFiles/eth-cryptocom.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include eth/cryptocom/CMakeFiles/eth-cryptocom.dir/compiler_depend.make

# Include the progress variables for this target.
include eth/cryptocom/CMakeFiles/eth-cryptocom.dir/progress.make

# Include the compile flags for this target's objects.
include eth/cryptocom/CMakeFiles/eth-cryptocom.dir/flags.make

eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o: eth/cryptocom/CMakeFiles/eth-cryptocom.dir/flags.make
eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o: eth/cryptocom/main.cpp
eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o: eth/cryptocom/CMakeFiles/eth-cryptocom.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o -MF CMakeFiles/eth-cryptocom.dir/main.cpp.o.d -o CMakeFiles/eth-cryptocom.dir/main.cpp.o -c /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom/main.cpp

eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eth-cryptocom.dir/main.cpp.i"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom/main.cpp > CMakeFiles/eth-cryptocom.dir/main.cpp.i

eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eth-cryptocom.dir/main.cpp.s"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom/main.cpp -o CMakeFiles/eth-cryptocom.dir/main.cpp.s

# Object files for target eth-cryptocom
eth__cryptocom_OBJECTS = \
"CMakeFiles/eth-cryptocom.dir/main.cpp.o"

# External object files for target eth-cryptocom
eth__cryptocom_EXTERNAL_OBJECTS =

eth/cryptocom/eth-cryptocom: eth/cryptocom/CMakeFiles/eth-cryptocom.dir/main.cpp.o
eth/cryptocom/eth-cryptocom: eth/cryptocom/CMakeFiles/eth-cryptocom.dir/build.make
eth/cryptocom/eth-cryptocom: /usr/local/opt/openssl/lib/libcrypto.dylib
eth/cryptocom/eth-cryptocom: /usr/local/opt/openssl/lib/libssl.dylib
eth/cryptocom/eth-cryptocom: /usr/local/opt/openssl/lib/libcrypto.dylib
eth/cryptocom/eth-cryptocom: eth/cryptocom/CMakeFiles/eth-cryptocom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable eth-cryptocom"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eth-cryptocom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
eth/cryptocom/CMakeFiles/eth-cryptocom.dir/build: eth/cryptocom/eth-cryptocom
.PHONY : eth/cryptocom/CMakeFiles/eth-cryptocom.dir/build

eth/cryptocom/CMakeFiles/eth-cryptocom.dir/clean:
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom && $(CMAKE_COMMAND) -P CMakeFiles/eth-cryptocom.dir/cmake_clean.cmake
.PHONY : eth/cryptocom/CMakeFiles/eth-cryptocom.dir/clean

eth/cryptocom/CMakeFiles/eth-cryptocom.dir/depend:
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/eth/cryptocom/CMakeFiles/eth-cryptocom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : eth/cryptocom/CMakeFiles/eth-cryptocom.dir/depend
