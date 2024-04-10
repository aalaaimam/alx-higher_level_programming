#!/usr/bin/python3

"""Defines a matrix division function."""


def matrix_divided(matrix, div):
    """Divide all elements of a matrix by a divisor.

    Args:
        matrix (list): A list of lists of ints or floats.
        div (int/float): The divisor.

    Raises:
        TypeError: If the matrix is not properly formatted or contains non-numbers.
        TypeError: If the divisor is not a number.
        ZeroDivisionError: If the divisor is zero.

    Returns:
        A new matrix representing the result of the division.
    """
    # Check if matrix is a list of lists of ints or floats
    if not isinstance(matrix, list) or not all(isinstance(row, list) for row in matrix):
        raise TypeError("matrix must be a matrix (list of lists) of integers/floats")

    if not all(isinstance(num, (int, float)) for row in matrix for num in row):
        raise TypeError("matrix must contain only integers or floats")

    # Check if all rows have the same length
    if not all(len(row) == len(matrix[0]) for row in matrix):
        raise TypeError("Each row of the matrix must have the same size")

    # Check if divisor is a number
    if not isinstance(div, (int, float)):
        raise TypeError("div must be a number")

    # Check if divisor is not zero
    if div == 0:
        raise ZeroDivisionError("division by zero")

    # Perform matrix division
    return [[round(num / div, 2) for num in row] for row in matrix]


# Example usage:
if __name__ == "__main__":
    # Example matrix
    example_matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    divisor = 2

    # Perform matrix division
    result = matrix_divided(example_matrix, divisor)

    # Print result
    for row in result:
        print(row)
