# toolchain-ps2.cmake

# Set the system name to Generic since PS2 is not recognized by CMake
set(CMAKE_SYSTEM_NAME Generic)

# Specify the path to your Metrowerks PS2 compiler directory
set(PS2_COMPILER_DIR "C:/Users/pxd/Desktop/compilers/mwcps2-2.3.3-000906")

# Specify the compiler and linker executables
set(CMAKE_C_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")
set(CMAKE_LINKER     "${PS2_COMPILER_DIR}/mwldps2.exe")

# Prevent CMake from trying to use a C++ compiler
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_C_COMPILER_WORKS 1)

# Set the assembler to avoid CMake errors (even if not used)
set(CMAKE_ASM_COMPILER "${CMAKE_C_COMPILER}")

# Define include and library directories
set(MWCIncludes "C:/usr/local/sce/ee/gcc/ee/include;C:/usr/local/sce/ee/include;C:/Program Files (x86)/Metrowerks/CodeWarrior for PS2 v3.9/PS2 Support")
set(MWLibraries "C:/usr/local/sce/ee/gcc/ee/lib;C:/usr/local/sce/ee/lib;C:/usr/local/sce/ee/gcc/lib;C:/usr/local/sce/ee/gcc/lib/gcc-lib/ee/2.9-ee-991111-01")

# Convert paths to CMake format
file(TO_CMAKE_PATH "${MWCIncludes}" MWCIncludes)
file(TO_CMAKE_PATH "${MWLibraries}" MWLibraries)

# Set compiler and linker flags
set(CMAKE_C_FLAGS "-I${MWCIncludes}")
set(CMAKE_EXE_LINKER_FLAGS "-L${MWLibraries} -lcf linker.lcf -entry __start")

# Suppress CMake warnings about missing standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
