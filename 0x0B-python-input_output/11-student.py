#!/usr/bin/python3
"""Defines a class Student."""


class Student:
    """Represent a student."""

    def __init__(self, first_name, last_name, age):
        """Initialize student props."""
        self.first_name = first_name
        self.last_name = last_name
        self.age = age

    def to_json(self, attrs=None):
        """Converts object attributes to a JSON-compatible dictionary."""
        if attrs is not None and isinstance(attrs, list) \
                and all(isinstance(ele, str) for ele in attrs):
            return {k: getattr(self, k) for k in attrs if hasattr(self, k)}
        return self.__dict__

    def reload_from_json(self, json):
        """Reloads object attributes from a JSON dictionary."""
        for k, v in json.items():
            setattr(self, k, v)


# Pycodestyle validation
if __name__ == "__main__":
    # This ensures that the code is only executed when the script is run directly
    pass
