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
include coinbase-btc/CMakeFiles/coinbase-btc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include coinbase-btc/CMakeFiles/coinbase-btc.dir/compiler_depend.make

# Include the progress variables for this target.
include coinbase-btc/CMakeFiles/coinbase-btc.dir/progress.make

# Include the compile flags for this target's objects.
include coinbase-btc/CMakeFiles/coinbase-btc.dir/flags.make

coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o: coinbase-btc/CMakeFiles/coinbase-btc.dir/flags.make
coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o: coinbase-btc/main.cpp
coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o: coinbase-btc/CMakeFiles/coinbase-btc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o -MF CMakeFiles/coinbase-btc.dir/main.cpp.o.d -o CMakeFiles/coinbase-btc.dir/main.cpp.o -c /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc/main.cpp

coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coinbase-btc.dir/main.cpp.i"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc/main.cpp > CMakeFiles/coinbase-btc.dir/main.cpp.i

coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coinbase-btc.dir/main.cpp.s"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc/main.cpp -o CMakeFiles/coinbase-btc.dir/main.cpp.s

# Object files for target coinbase-btc
coinbase__btc_OBJECTS = \
"CMakeFiles/coinbase-btc.dir/main.cpp.o"

# External object files for target coinbase-btc
coinbase__btc_EXTERNAL_OBJECTS =

coinbase-btc/coinbase-btc: coinbase-btc/CMakeFiles/coinbase-btc.dir/main.cpp.o
coinbase-btc/coinbase-btc: coinbase-btc/CMakeFiles/coinbase-btc.dir/build.make
coinbase-btc/coinbase-btc: /usr/local/opt/openssl/lib/libcrypto.dylib
coinbase-btc/coinbase-btc: /usr/local/opt/openssl/lib/libssl.dylib
coinbase-btc/coinbase-btc: /usr/local/opt/openssl/lib/libcrypto.dylib
coinbase-btc/coinbase-btc: coinbase-btc/CMakeFiles/coinbase-btc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable coinbase-btc"
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coinbase-btc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
coinbase-btc/CMakeFiles/coinbase-btc.dir/build: coinbase-btc/coinbase-btc
.PHONY : coinbase-btc/CMakeFiles/coinbase-btc.dir/build

coinbase-btc/CMakeFiles/coinbase-btc.dir/clean:
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc && $(CMAKE_COMMAND) -P CMakeFiles/coinbase-btc.dir/cmake_clean.cmake
.PHONY : coinbase-btc/CMakeFiles/coinbase-btc.dir/clean

coinbase-btc/CMakeFiles/coinbase-btc.dir/depend:
	cd /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc /Users/riccardosantoni/Documents/CMU/15418/hft-crypto-streaming/streaming/coinbase-btc/CMakeFiles/coinbase-btc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : coinbase-btc/CMakeFiles/coinbase-btc.dir/depend

