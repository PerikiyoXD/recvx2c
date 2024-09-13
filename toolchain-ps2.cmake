# toolchain-ps2.cmake

# Set the system name
set(CMAKE_SYSTEM_NAME Generic)

# Specify the compiler and linker executables
set(PS2_COMPILER_DIR "C:/Users/pxd/Desktop/compilers/mwcps2-2.3.3-000906")
set(CMAKE_C_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")
set(CMAKE_CXX_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")

# Ensure --gcc-compat is the first flag for the compiler
set(CMAKE_C_FLAGS_INIT "--gcc-compat")
set(CMAKE_CXX_FLAGS_INIT "--gcc-compat")

# Prevent CMake from checking the compiler
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Handle include directories
if(DEFINED ENV{MWCIncludes})
    # Retrieve the include paths from the environment variable
    set(MWCIncludes_LIST $ENV{MWCIncludes})

    # Iterate over each include directory and append -I"<path>"
    foreach(include_dir IN LISTS MWCIncludes_LIST)
        # Escape backslashes and quotes if necessary
        string(REPLACE "\\" "/" include_dir "${include_dir}")  # Replace backslashes with forward slashes
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I\"${include_dir}\"")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I\"${include_dir}\"")
    endforeach()
endif()

# Handle library directories
if(DEFINED ENV{MWLibraries})
    # Retrieve the library paths from the environment variable
    set(MWLibraries_LIST $ENV{MWLibraries})

    # Iterate over each library directory and append -L"<path>"
    foreach(library_dir IN LISTS MWLibraries_LIST)
        # Escape backslashes and quotes if necessary
        string(REPLACE "\\" "/" library_dir "${library_dir}")  # Replace backslashes with forward slashes
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L\"${library_dir}\"")
    endforeach()
endif()

# Set additional linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lcf \"${CMAKE_SOURCE_DIR}/linker.lcf\"")

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
