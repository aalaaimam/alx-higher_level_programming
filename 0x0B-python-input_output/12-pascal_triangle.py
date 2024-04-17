#!/usr/bin/python3
"""pascal_triangle module."""


def pascal_triangle(n):
    """Generate Pascal's triangle up to the given number of rows."""
    if n <= 0:
        return []

    triangles = [[1]]
    while len(triangles) < n:
        prev_row = triangles[-1]
        next_row = [1]
        for i in range(len(prev_row) - 1):
            next_row.append(prev_row[i] + prev_row[i + 1])
        next_row.append(1)
        triangles.append(next_row)

    return triangles
