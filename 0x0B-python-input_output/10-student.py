#!/usr/bin/env python3

import sys

def print_statistics(total_size, status_counts):
    print("File size:", total_size)
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")

def main():
    total_size = 0
    status_counts = {}

    try:
        for i, line in enumerate(sys.stdin, start=1):
            # Parse the line
            parts = line.split()
            status_code = parts[-2]
            file_size = int(parts[-1])

            # Update total file size
            total_size += file_size

            # Update status code count
            status_counts[status_code] = status_counts.get(status_code, 0) + 1

            # Print statistics every 10 lines
            if i % 10 == 0:
                print_statistics(total_size, status_counts)

    except KeyboardInterrupt:
        print_statistics(total_size, status_counts)
        sys.exit(0)

if __name__ == "__main__":
    main()
