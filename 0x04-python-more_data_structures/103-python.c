#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - prints basic info about Python lists
 * @p: PyObject pointer
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t i, size;
    PyObject *element;

    printf("[*] Python list info\n");
    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        element = PySequence_GetItem(p, i);
        if (!element)
        {
            printf("Element %ld: <failed to retrieve>\n", i);
            continue;
        }
        printf("Element %ld: ", i);
        PyObject_Print(element, stdout, 0);
        printf("\n");
        Py_DECREF(element);
    }
}

/**
 * print_python_bytes - prints basic info about Python bytes objects
 * @p: PyObject pointer
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size;
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
    printf("  first %ld bytes: ", size);
    for (Py_ssize_t i = 0; i < size; i++)
    {
        printf("%02x", str[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}
