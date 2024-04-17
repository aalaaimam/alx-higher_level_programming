#!/usr/bin/python3
import sys

def print_statistics(total_size, status_codes):
    """
    Print statistics including total file size and number of lines by status code.
    """
    print("File size: {}".format(total_size))
    sorted_status_codes = sorted(status_codes.keys())
    for code in sorted_status_codes:
        print("{}: {}".format(code, status_codes[code]))

def parse_line(line):
    """
    Parse a line of input and return the IP address, status code, and file size.
    """
    parts = line.split()
    ip_address = parts[0]
    status_code = parts[-2]
    file_size = int(parts[-1])
    return ip_address, status_code, file_size

def main():
    total_size = 0
    status_codes = {}
    try:
        for i, line in enumerate(sys.stdin, 1):
            ip_address, status_code, file_size = parse_line(line)
            total_size += file_size
            status_codes[status_code] = status_codes.get(status_code, 0) + 1
            if i % 10 == 0:
                print_statistics(total_size, status_codes)
    except KeyboardInterrupt:
        print_statistics(total_size, status_codes)

if __name__ == "__main__":
    main()
