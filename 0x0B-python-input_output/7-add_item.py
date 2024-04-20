#!/usr/bin/python3
"""Save arguments to and load from a JSON file."""
import sys
import json


def save_to_json_file(my_obj, filename):
    """Write an Object to a file using JSON representation."""
    with open(filename, 'w') as file:
        json.dump(my_obj, file)


def load_from_json_file(filename):
    """Create an Object from a JSON file."""
    with open(filename, 'r') as file:
        return json.load(file)


if __name__ == "__main__":
    try:
        items = load_from_json_file("add_item.json")
    except FileNotFoundError:
        items = []
    # Extend items list with command-line arguments
    items.extend(sys.argv[1:])
    # Save the updated items list back to "add_item.json"
    save_to_json_file(items, "add_item.json")
