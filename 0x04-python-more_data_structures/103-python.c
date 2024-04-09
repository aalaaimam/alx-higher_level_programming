#include <stdio.h>
#include <Python.h>

void print_python_list(PyObject *p) {
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");
    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);

    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

void print_python_bytes(PyObject *p) {
    Py_ssize_t size, i;
    char *str;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("  size: %ld\n", size);
    
    printf("  trying string: %s\n", PyUnicode_AsUTF8AndSize(p, &size));
    
    printf("  first %ld bytes:", (size > 10) ? 10 : size);
    str = PyBytes_AsString(p);
    for (i = 0; i < ((size > 10) ? 10 : size); i++) {
        printf(" %02x", str[i] & 0xFF);
    }
    printf("\n");
}
