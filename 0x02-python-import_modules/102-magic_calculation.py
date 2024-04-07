#!/usr/bin/python3
def magic_calculation(a, b):
    add = __import__("102-magic_calculation").add
    sub = __import__("102-magic_calculation").sub

    if a < b:
        c = add(a, b)
        for i in range(4, 6):
            c = add(c, i)
        return c
    else:
        return sub(a, b)
