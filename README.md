Python path for <Python.h>

C:\Users\mzec\AppData\Local\Programs\Python\Python39\include

gcc main.c utility_functions.c -o my_program_funct -IC:\Users\mzec\AppData\Local\Programs\Python\Python39\include -LC:\Users\mzec\AppData\Local\Programs\Python\Python39\libs -lpython39


Notes:
=======
- Changes in python scripts will be applied witout need to compile again!
- The venv does not need to be started
- All libraries can be installed to venv and global python is used to provide interface (API) through <Puthon.h>


DLL compilation:
=================

gcc -shared -o utility_functions.dll utility_functions.c -I C:\Users\mzec\AppData\Local\Programs\Python\Python39\include -L C:\Users\mzec\AppData\Local\Programs\Python\Python39\libs -lpython39
gcc -o my_program_funct_dll.exe main.c utility_functions.dll  -IC:\Users\mzec\AppData\Local\Programs\Python\Python39\include -LC:\Users\mzec\AppData\Local\Programs\Python\Python39\libs -lpython39
