import argparse
import os

def validate_file_exists(file_path, file_description):
    """Validates that a file exists and is accessible."""
    if not os.path.isfile(file_path):
        raise FileNotFoundError(f"Error: {file_description} '{file_path}' does not exist or is not accessible.")
    return file_path

def parse_hex_address(address):
    """Parses the target address from a hex string to an integer."""
    try:
        return int(address, 16)
    except ValueError:
        raise ValueError(f"Error: Invalid target address '{address}', it should be a valid hexadecimal value.")

def read_blob_data(blob_file):
    """Reads the binary data from the provided blob file."""
    with open(blob_file, "rb") as bf:
        return bf.read()

def write_blob_to_binary(target_binary, blob_data, target_address):
    """Writes the binary data to the target binary at the specified address."""
    with open(target_binary, "r+b") as tb:
        tb.seek(0, os.SEEK_END)
        target_binary_size = tb.tell()

        if target_address > target_binary_size:
            raise ValueError(f"Error: Target address 0x{target_address:x} is beyond the size of the target binary (0x{target_binary_size:x}).")

        tb.seek(target_address)
        tb.write(blob_data)

def put_blob_in_binary(target_binary, blob_file, target_address):
    """Main function to put the blob data into the target binary at a specific address."""
    # Ensure the target binary and blob file exist
    validate_file_exists(target_binary, "Target binary")
    validate_file_exists(blob_file, "Blob file")

    # Read the blob data
    blob_data = read_blob_data(blob_file)

    # Write the blob data into the target binary at the given address
    write_blob_to_binary(target_binary, blob_data, target_address)

    print(f"Successfully wrote {len(blob_data)} bytes of blob data into '{target_binary}' at address 0x{target_address:x}.")

def main():
    # Argument parser configuration
    parser = argparse.ArgumentParser(description="Write binary data (blob) into a target binary file at a specified address.")
    parser.add_argument("target_binary", help="The target binary file to modify.")
    parser.add_argument("blob_file", help="The blob file containing binary data to be written into the target.")
    parser.add_argument("target_address", help="The address in the target binary to write the blob (in hexadecimal).")

    # Parse arguments
    args = parser.parse_args()

    # Validate and execute
    try:
        # Parse the hexadecimal target address
        target_address = parse_hex_address(args.target_address)

        # Insert the blob into the target binary
        put_blob_in_binary(args.target_binary, args.blob_file, target_address)

    except (FileNotFoundError, ValueError) as error:
        print(error)

    except Exception as error:
        print(f"An unexpected error occurred: {error}")

if __name__ == "__main__":
    main()
