# toolchain-ps2.cmake

# Enable compile commands for IDEs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the system name
set(CMAKE_SYSTEM_NAME Generic)

# Specify the compiler and linker executables
set(PS2_COMPILER_DIR "C:/Users/pxd/Desktop/compilers/mwcps2-2.3.3-000906")
set(CMAKE_C_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")
set(CMAKE_CXX_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")
set(CMAKE_LINKER "${PS2_COMPILER_DIR}/mwldps2.exe")

# Ensure --gcc-compat is the first flag for the compiler and use -c to compile only
set(CMAKE_C_FLAGS_INIT "--gcc-compat -c")
set(CMAKE_CXX_FLAGS_INIT "--gcc-compat -c")

# Prevent CMake from checking the compiler
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Handle include directories
if(DEFINED ENV{MWCIncludes})
    set(MWCIncludes_LIST $ENV{MWCIncludes})
    foreach(include_dir IN LISTS MWCIncludes_LIST)
        string(REPLACE "\\" "/" include_dir "${include_dir}")  # Normalize slashes
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I\"${include_dir}\"")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I\"${include_dir}\"")
    endforeach()
endif()

# Handle library directories
if(DEFINED ENV{MWLibraries})
    set(MWLibraries_LIST $ENV{MWLibraries})
    foreach(library_dir IN LISTS MWLibraries_LIST)
        string(REPLACE "\\" "/" library_dir "${library_dir}")  # Normalize slashes
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L\"${library_dir}\"")
    endforeach()
endif()

# Set linker flags for mwldps2
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lcf \"${CMAKE_SOURCE_DIR}/linker.lcf\"")

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
