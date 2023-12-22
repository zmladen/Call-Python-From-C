#include <stdio.h>
#include <time.h>  // Include time.h for clock()
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

    // Start timing
    clock_t start = clock();

    // Call the function to calculate the mean
    double result = call_python_function(numbers, size);

    // End timing
    clock_t end = clock();

    // Calculate the time taken in seconds
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print the result and time taken
    printf("Result of call: %f\n", result);
    printf("Time taken for Python function: %f seconds\n", time_taken);

    Py_Finalize();
    return 0;
}
