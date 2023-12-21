#include "utility_functions.h"
#include <Python.h>

double call_python_function(double numbers[], int size) {
    // Initialize the Python Interpreter
    // Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./venv/Lib/site-packages')");

    // Import the Python module
    PyObject *pName = PyUnicode_DecodeFSDefault("utility");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "calculate_mean");

        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject *pArgs = PyTuple_New(1);
            PyObject *pValue = PyList_New(size);

            // Add numbers to the Python list
            for (int i = 0; i < size; i++) {
                PyList_SetItem(pValue, i, PyFloat_FromDouble(numbers[i]));
            }

            PyTuple_SetItem(pArgs, 0, pValue);

            PyObject *pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pResult != NULL && PyFloat_Check(pResult)) {
                double result = PyFloat_AsDouble(pResult);
                Py_DECREF(pResult);
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                Py_Finalize();
                return result;
            }
            else {
                if (PyErr_Occurred())
                    PyErr_Print();
                fprintf(stderr, "Call failed or returned non-float\n");
                Py_XDECREF(pResult);
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "calculate_mean");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", "utility");
    }

    // Py_Finalize();
    return 0; // Return 0 or an appropriate error value
}

const char* get_pytorch_version() {
    // Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./venv/Lib/site-packages')");

    PyObject *pName = PyUnicode_DecodeFSDefault("utility");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        PyObject *pFunc = PyObject_GetAttrString(pModule, "get_torch_version");

        if (pFunc && PyCallable_Check(pFunc)) {
            PyObject *pResult = PyObject_CallObject(pFunc, NULL);

            if (pResult != NULL) {
                const char* version_temp = PyUnicode_AsUTF8(pResult);
                char* version = strdup(version_temp);  // Duplicate the string

                Py_DECREF(pResult);
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                // Py_Finalize();
                return version;
            } else {
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
            }
        } else {
            PyErr_Print();
            fprintf(stderr, "Cannot find function 'get_torch_version'\n");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        fprintf(stderr, "Failed to load 'pytorch_helpers'\n");
    }

    // Py_Finalize();
    return NULL; // Return NULL in case of error
}