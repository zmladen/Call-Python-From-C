#include <stdio.h>
#include "utility_functions.h"
#include <Python.h>

int main() {
    Py_Initialize();
    // PyRun_SimpleString("import sys");
    // PyRun_SimpleString("sys.path.append('./venv/Lib/site-packages')");
    // Get and print PyTorch version
    const char* torch_version = get_pytorch_version();
    if (torch_version != NULL) {
        printf("PyTorch version: %s\n", torch_version);
        free((void*)torch_version);  // Free the duplicated string
    } else {
        printf("Failed to get PyTorch version\n");
    }

    // Your array of numbers
    double numbers[] = {11.0, 2.5, 3.2, 4.8};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Call the function to calculate the mean and print the result
    double result = call_python_function(numbers, size);
    printf("Result of call: %f\n", result);

    Py_Finalize();
    return 0;
}

