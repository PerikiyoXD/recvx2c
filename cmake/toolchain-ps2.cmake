# toolchain-ps2.cmake

# Set the system name
set(CMAKE_SYSTEM_NAME Generic)

# Specify the compiler and linker executables
set(PS2_COMPILER_DIR "C:/Users/pxd/Desktop/compilers/mwcps2-2.3.3-000906")
set(CMAKE_C_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")
set(CMAKE_CXX_COMPILER "${PS2_COMPILER_DIR}/mwccps2.exe")  # If you need C++ support

# Prevent CMake from checking the compiler
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Include directories from environment variable
if(DEFINED ENV{MWCIncludes})
    file(TO_CMAKE_PATH "$ENV{MWCIncludes}" MWCIncludes_STR)
    string(REPLACE ";" "|" MWCIncludes_STR "${MWCIncludes_STR}")
    string(REPLACE "|" ";" MWCIncludes_LIST "${MWCIncludes_STR}")
    foreach(include_dir ${MWCIncludes_LIST})
        include_directories("${include_dir}")
    endforeach()
endif()

# Library directories from environment variable
if(DEFINED ENV{MWLibraries})
    file(TO_CMAKE_PATH "$ENV{MWLibraries}" MWLibraries_STR)
    string(REPLACE ";" "|" MWLibraries_STR "${MWLibraries_STR}")
    string(REPLACE "|" ";" MWLibraries_LIST "${MWLibraries_STR}")
    foreach(library_dir ${MWLibraries_LIST})
        link_directories("${library_dir}")
    endforeach()
endif()

# Additional linker flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lcf linker.lcf")

# Set the standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
