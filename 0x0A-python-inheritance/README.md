0x0A. Python - Inheritance
Overview
This project explores the concept of inheritance in Python, a powerful feature of object-oriented programming. Through a series of tasks, we'll delve into creating classes, inheriting attributes and methods from parent classes, overriding inherited methods, and more.

General
Python programming offers immense flexibility and power through its object-oriented paradigm.
Understanding inheritance is crucial as it allows classes to inherit attributes and methods from other classes, promoting code reuse and modularity.
Concepts Covered
Superclass, Baseclass, Parentclass: These terms refer to the class whose attributes and methods are inherited by another class.
Subclass: Also known as a derived class, it inherits attributes and methods from its superclass.
Listing Attributes and Methods: We'll explore how to inspect and list all attributes and methods of a class or instance.
Overriding Methods and Attributes: Subclasses can override methods and attributes inherited from their superclass to tailor functionality to their specific needs.
Multiple Inheritance: Python supports inheriting from multiple base classes, allowing for complex class hierarchies.
isinstance, issubclass, type, super: These built-in functions help in determining relationships between objects and classes.
Tasks Overview
Task 0: Lookup
Implement a function that returns a list of available attributes and methods of an object without using any module.
Task 1: My List
Create a class MyList that inherits from the built-in list class and includes a method to print the list in sorted order.
Task 2: Exact Same Object
Write a function that checks if an object is exactly an instance of the specified class.
Task 3: Same Class or Inherit From
Implement a function to determine if an object is an instance of, or inherited from, a specified class.
Task 4: Only Sub Class of
Create a function to check if an object is an instance of a class that directly or indirectly inherits from a specified class.
Task 5: Geometry Module
Define an empty class BaseGeometry to serve as the base class for geometric shapes.
Task 6: Improve Geometry
Enhance the BaseGeometry class by adding a method area() that raises an exception to enforce implementation by subclasses.
Task 7: Integer Validator
Expand the BaseGeometry class with a method integer_validator() to validate integer values.
Task 8: Rectangle
Create a class Rectangle that inherits from BaseGeometry, with private attributes for width and height and validation of positive integers.
Task 9: Full Rectangle
Extend the Rectangle class with an implementation of the area() method and customized print() and str() methods.
Task 10: Square #1
Implement a class Square that inherits from Rectangle, enforcing a square shape by ensuring width and height are equal.
Task 11: Square #2
Enhance the Square class with custom print() and str() methods to describe the square.
Task 12: My Integer
Define a class MyInt that inherits from int but inverts the behavior of equality operators == and !=.
Task 13: Can I?
Write a function add_attribute() to dynamically add attributes to an object if possible, raising a TypeError if not.
Throughout these tasks, we'll gain a deeper understanding of inheritance and its practical applications in Python.
