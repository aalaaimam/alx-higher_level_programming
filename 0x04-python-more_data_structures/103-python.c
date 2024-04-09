#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - prints some basic info about Python lists
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t i, size;
    PyObject *element;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    size = PyList_Size(p);
    for (i = 0; i < size; i++)
    {
        element = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(element)->tp_name);
    }
}

/**
 * print_python_bytes - prints some basic info about Python bytes objects
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t i, size;
    unsigned char *str;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = (unsigned char *)PyBytes_AsString(p);

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    printf("  first %ld bytes: ", (size < 10) ? size : 10);
    for (i = 0; i < size && i < 10; i++)
    {
        printf("%02x", str[i]);
        if (i < 9 && i < size - 1)
            printf(" ");
    }
    printf("\n");
}
