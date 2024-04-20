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
        """Return JSON representation of the Student instance."""
        if attrs is not None and isinstance(attrs, list) and \
                all(isinstance(attr, str) for attr in attrs):
            return {attr: getattr(self, attr) for attr in attrs if hasattr(self, attr)}
        return self.__dict__
