import os
import subprocess
import sys
import json

# Function to load environment variables from a JSON file
def load_env_json(filename):
    with open(filename, 'r') as f:
        return json.load(f)

# Function to run a command and print the result to a log file
def run_command(command, env_vars):
    print(f"Running: {' '.join(command)}")
    
    # Pass the current environment variables and add custom ones
    env = os.environ.copy()
    env.update(env_vars)
    
    # Run the command and capture output
    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, env=env)
    
    # Write output to build.log
    with open('build.log', 'a') as log_file:
        log_file.write(result.stdout.decode('utf-8'))
        log_file.write(result.stderr.decode('utf-8'))
    
    # Print error if the command failed
    if result.returncode != 0:
        print(f"Error: {result.stderr.decode('utf-8')}")
        sys.exit(result.returncode)
    
    print(result.stdout.decode('utf-8'))

# Load environment variables from the .env.json file
env_vars = load_env_json('.env.json')

# Compiler and linker from the JSON file
compiler = env_vars["compiler"]
linker = env_vars["linker"]

# Include directories and library directories from the JSON file
include_dirs = env_vars["includes"]
library_dirs = env_vars["libraries"]

# Compiler and linker flags
compiler_flags = env_vars["compiler_flags"]
linker_flags = env_vars["linker_flags"]

# Libraries to link against
libraries = env_vars["libs"]

# Source files and object files
sources = ["main.c"]
objects = []

# Compilation phase: Compile each source file into an object file
for source in sources:
    object_file = source.replace(".c", ".o")
    objects.append(object_file)
    
    # Build the compile command
    compile_command = [compiler] + compiler_flags + ['-c', source, '-o', object_file]
    for inc_dir in include_dirs:
        compile_command.append(f'-I{inc_dir}')
    
    # Set up environment for compiler
    compiler_env = {
        "MWLibraries": ";".join(env_vars["libraries"]),
        "MWLibraryFiles": ""
    }
    
    # Run the compile command
    run_command(compile_command, compiler_env)

# Linking phase: Link object files into the final executable
output_elf = "main.elf"
link_command = [linker] + linker_flags + objects + ['-o', output_elf]
for lib_dir in library_dirs:
    link_command.append(f'-L{lib_dir}')
link_command += libraries

# Set up environment for linker
linker_env = {
    "MWLibraries": ";".join(env_vars["libraries"]),
    "MWLibraryFiles": ""
}

# Run the link command
run_command(link_command, linker_env)

print(f"Build completed successfully: {output_elf}")
