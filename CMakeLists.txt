cmake_minimum_required(VERSION 3.8)
project(PS2Project C)

# Include directories
include_directories(${MWCIncludes})

# Add the executable target
add_executable(main.elf main.c)

# Specify the output format and extension
set_target_properties(main.elf PROPERTIES OUTPUT_NAME "main" SUFFIX ".elf")

# Link libraries
target_link_libraries(main.elf gcc graph dma dev pkt pad vu0 kernl c)

# Add library directories
link_directories(${MWLibraries})
