#include <Python.h>
#include <stdio.h>  // Include standard I/O library for printf function

void print_python_list(PyObject *p) {
    Py_ssize_t size, i;
    PyObject *item;

    size = PyList_Size(p);
    if (size == -1) {
        printf("[*] Failed to retrieve Python list size\n");
        return;
    }

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);

    // Check if the object is actually a list
    if (!PyList_Check(p)) {
        printf("[!] Error: Not a Python list\n");
        return;
    }

    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; ++i) {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    Py_ssize_t size, i;
    unsigned char *string;

    printf("[.] bytes object info\n");

    // Check if the object is actually bytes
    if (!PyBytes_Check(p)) {
        printf("[!] Error: Not a Python bytes object\n");
        return;
    }

    size = PyBytes_Size(p);
    string = (unsigned char *)PyBytes_AsString(p);

    if (size == -1 || string == NULL) {
        printf("[*] Failed to retrieve bytes object information\n");
        return;
    }

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", (char *)string);

    printf("  first %ld bytes: ", (size > 10) ? 10 : size);
    for (i = 0; i < ((size > 10) ? 10 : size); ++i) {
        printf("%02x ", string[i]);
    }
    printf("\n");
}
