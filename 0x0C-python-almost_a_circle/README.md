0x0C. Python - Almost a circle
Overview
This project dives deep into Python and object-oriented programming (OOP) concepts. It covers various topics such as importing modules, exception handling, classes, private attributes, getters/setters, class methods, static methods, inheritance, unit testing, file I/O, *args and **kwargs, serialization/deserialization, and JSON manipulation.

Learning Objectives
By completing this project, you should gain proficiency in the following areas:

Understanding unit testing and implementing it in a large project
Serializing and deserializing classes
Reading and writing JSON files
Using *args and **kwargs
Handling named arguments in functions
Requirements
Python Scripts
Allowed Editors: vi, vim, emacs
Interpreted On: Ubuntu 20.04 LTS using Python 3.8.5
Code Formatting: PEP8 (pycodestyle version 2.8.*)
Executable: All files must be executable
Documentation: Modules, classes, and functions must be documented
Documentation Standard: Each documentation should be a sentence explaining the purpose of the module, class, or method
Test Coverage: All files, classes, and methods must be unit tested
File Organization: Tests should be organized in a folder structure mirroring the project's directory
Python Unit Tests
Testing Module: unittest
Test File Extension: .py
Execution Command: python3 -m unittest discover tests
Project Structure
Directory Structure: The project is organized into folders and files as follows:
models/: Contains Python files for defining classes
tests/: Houses Python files for unit testing
File Naming: Files follow a consistent naming convention based on the class or functionality they implement
Tasks
The project consists of several tasks, each focusing on specific aspects of Python and OOP. Here's a brief overview of the tasks:

If it's not tested it doesn't work
Ensure all files, classes, and methods are unit tested and adhere to PEP 8 standards.
Base class
Implement a base class Base with specific functionalities.
First Rectangle
Create a class Rectangle that inherits from Base with additional attributes and methods.
Validate attributes
Add validation to the attributes of the Rectangle class.
Area first
Implement a method to calculate the area of a rectangle.
Display #0
Add a method to display the rectangle using the # character.
str
Override the __str__ method to customize string representation of a rectangle.
Display #1
Improve the display method to include x and y coordinates.
Update #0
Add a method to update attributes of a rectangle.
Update #1
Enhance the update method to accept keyword arguments.
And now, the Square!
Implement a class Square inheriting from Rectangle.
Square size
Add getter and setter methods for the size attribute in the Square class.
Square update
Implement a method to update attributes of a square.
Rectangle instance to dictionary representation
Add a method to convert a rectangle instance to a dictionary.
Square instance to dictionary representation
Implement a method to convert a square instance to a dictionary.
Dictionary to JSON string
Add a static method to convert a list of dictionaries to a JSON string.
JSON string to file
Implement a method to save JSON string representation to a file.
JSON string to dictionary
Add a static method to convert a JSON string to a list of dictionaries.
Dictionary to Instance
Implement a method to create an instance from a dictionary.
File to instances
Add a method to load instances from a file.
Conclusion
By completing this project, you will have a comprehensive understanding of Python and its object-oriented features. Through rigorous testing and adherence to coding standards, you'll build a solid foundation for developing scalable and maintainable Python applications.
