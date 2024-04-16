#!/usr/bin/python3

def inherits_from(obj, a_class):
    """Check if an object is an instance of a class that inherited from a_class.

    Args:
        obj (object): The object to check.
        a_class (class): The class to check inheritance from.

    Returns:
        bool: True if obj is an instance of a subclass of a_class, False otherwise.
    """
    return issubclass(type(obj), a_class) and type(obj) != a_class
