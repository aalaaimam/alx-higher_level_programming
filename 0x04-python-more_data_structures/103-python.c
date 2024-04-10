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
        element = PyList_GetItem(p, i);
        printf("Element %ld: ", i);
        if (PyBytes_Check(element))
        {
            printf("bytes\n");
            printf("[.] bytes object info\n");
            printf("  size: %ld\n", PyBytes_Size(element));
            printf("  trying string: %s\n", PyBytes_AsString(element));
            printf("  first 6 bytes: ");
            unsigned char *str = (unsigned char *)PyBytes_AsString(element);
            for (int j = 0; j < 6; j++)
            {
                printf("%02x ", str[j]);
            }
            printf("\n");
        }
        else
        {
            printf("%s\n", Py_TYPE(element)->tp_name);
        }
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
    printf("  first 6 bytes: ");
    for (Py_ssize_t i = 0; i < size && i < 6; i++)
    {
        printf("%02x ", str[i]);
    }
    printf("\n");
}

int main() {
    PyObject *l, *b;
    Py_Initialize();
    l = PyList_New(0);
    b = PyBytes_FromString("What does the 'b' character do in front of a string literal?");
    PyList_Append(l, b);
    print_python_bytes(b);
    print_python_list(l);
    Py_Finalize();
    return 0;
}
