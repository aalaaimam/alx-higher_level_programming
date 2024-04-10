#include <Python.h>

/**
 * print_python_bytes - prints information about Python bytes objects
 * @p: pointer to the PyObject representing the bytes object
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    unsigned char *str;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)p)->ob_size;
    str = (unsigned char *)((PyBytesObject *)p)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    if (size >= 10)
        size = 10;

    printf("  first %ld bytes: ", size);
    for (i = 0; i < size; ++i)
    {
        printf("%02x", str[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}

/**
 * print_python_list - prints information about Python list objects
 * @p: pointer to the PyObject representing the list object
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, allocated, i;
    PyObject *item;

    printf("[*] Python list info\n");
    size = PyList_Size(p);
    allocated = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    for (i = 0; i < size; ++i)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}
