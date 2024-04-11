#include <stdio.h>
#include <Python.h>
#include <bytesobject.h>

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }

    PyBytesObject *bytes = (PyBytesObject *)p;
    printf("[.] bytes object info\n");
    printf(" size: %ld\n", (long)(bytes->ob_base.ob_size));

    printf(" trying string: ");
    for (Py_ssize_t i = 0; i < bytes->ob_base.ob_size; i++) {
        printf("%c", bytes->ob_sval[i]);
    }
    printf("\n");

    printf(" first %ld bytes: ", (long)(bytes->ob_base.ob_size > 10 ? 10 : bytes->ob_base.ob_size));
    for (Py_ssize_t i = 0; i < (bytes->ob_base.ob_size > 10 ? 10 : bytes->ob_base.ob_size); i++) {
        printf("%02x", (unsigned char)(bytes->ob_sval[i]));
        if (i != ((bytes->ob_base.ob_size > 10) ? 9 : bytes->ob_base.ob_size - 1))
            printf(" ");
    }
    printf("\n");
}

