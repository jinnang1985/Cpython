//linking with libs: -I/usr/include/python2.7 -lpython2.7

#include "randcor_gen.h"

#include <string>
#include <limits.h>
#include <unistd.h>
#define GetCurrentDir getcwd

int set_all(PyObject *target, PyObject *item)
{
    int i, n;
    n = PyObject_Length(target);
    if (n < 0)
        return -1;
    for (i = 0; i < n; i++) {
        PyObject *index = PyInt_FromLong(i);
        if (!index)
            return -1;
        if (PyObject_SetItem(target, index, item) < 0) {
            Py_DECREF(index);
            return -1;
        }
        Py_DECREF(index);
    }
    return 0;
}

int main(int argc, char *argv[]) {
	
/*  Rand_corr<float> randt;*/
/*  randt.initial();*/
/*  randt.print();*/
  
  Py_Initialize();  

  // add current path to sys
  PyObject* sysPath = PySys_GetObject((char*)"path");
  PyObject* curDir = PyString_FromString(".");
  PyList_Append(sysPath, curDir);
  Py_DECREF(curDir);

  FILE*        mul_file;
  PyObject*    main_module, * global_dict, * expression;
  PyObject*    main_dict;
  PyObject*    result;
  PyObject*    mod;

  main_module = PyImport_AddModule("__main__");
  global_dict = PyModule_GetDict(main_module);

  PyObject* modname = PyUnicode_FromString("get_rand");
  if (modname == NULL)
  {
    PyErr_Print();
    std::exit(1);
  }

  // argument
  int ncor = 3;
  PyObject* arglist = PyTuple_New(ncor);
/*  for (int i = 0; i < ncor; i++) {*/
/*    PyObject *item  = PyFloat_FromDouble(0.6);*/
/*    if (PyList_Append(arglist, item) < 0) {*/
/*        Py_DECREF(item);*/
/*        return 1;*/
/*    }*/
/*    printf("length of arglist is : %ld \n", PyList_GET_SIZE(arglist));*/
/*    Py_DECREF(item);*/
/*  }*/

  PyObject *pArgs, *pValue;

  for (int i = 0; i < ncor; ++i) {
    pValue = PyFloat_FromDouble(0.6);
    if (!pValue) {
      Py_DECREF(pArgs);
      Py_DECREF(pValue);
      fprintf(stderr, "Cannot convert argument\n");
      return 1;
      }
      /* pValue reference stolen here: */
      PyTuple_SetItem(pArgs, i, pValue);
  }

  
  ///////
  mod = PyImport_Import(modname);
  if (mod == NULL)
  {
    PyErr_Print();
    std::exit(1);
  }
  else 
  {
    PyObject* mdict = PyModule_GetDict(mod);
    expression = PyDict_GetItemString(mdict, "get_rand"); 
    if (expression) 
    {
      PyObject *result = PyObject_CallObject(expression, NULL);
    }
    else
    {
      PyErr_Print(); exit(2);
    }

    Py_XDECREF(mod);
    Py_XDECREF(mdict);
  }

  Py_XDECREF(modname);

  Py_Finalize();
  
  return 0;
}
