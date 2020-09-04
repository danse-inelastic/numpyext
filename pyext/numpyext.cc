// -*- C++ -*-
// 
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 
//                               Michael A.G. Aivazis
//                        California Institute of Technology
//                        (C) 1998-2005  All Rights Reserved
// 
//  <LicenseText>
// 
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 

#include <portinfo>

#include <Python.h>

#if PY_MAJOR_VERSION >= 3
  #define MOD_ERROR_VAL NULL
  #define MOD_SUCCESS_VAL(val) val
  #define MOD_INIT(name) PyMODINIT_FUNC PyInit_##name(void)
  #define MOD_DEF(ob, name, doc, methods) \
          static struct PyModuleDef moduledef = { \
            PyModuleDef_HEAD_INIT, name, doc, -1, methods, }; \
          ob = PyModule_Create(&moduledef);
#else
  #define MOD_ERROR_VAL
  #define MOD_SUCCESS_VAL(val)
  #define MOD_INIT(name) void init##name(void)
  #define MOD_DEF(ob, name, doc, methods) \
          ob = Py_InitModule3(name, methods, doc);
#endif

#include "exceptions.h"
#include "bindings.h"


//numpy stuff
#define PY_ARRAY_UNIQUE_SYMBOL numpyext_ARRAY_API
#include "numpy/arrayobject.h"


char pynumpyext_module__doc__[] = "";

// Initialization function for the module (*must* be called initnumpyext)
extern "C"
// void
MOD_INIT(numpyext)
{
    // create the module and add the functions
    PyObject * m;
    MOD_DEF(m, "numpyext", pynumpyext_module__doc__, pynumpyext_methods)
	   
    if (m == NULL)
        return MOD_ERROR_VAL;

    // get its dictionary
    PyObject * d = PyModule_GetDict(m);

    // check for errors
    if (PyErr_Occurred()) {
        Py_FatalError("can't initialize module numpyext");
    }

    // install the module exceptions
    pynumpyext_runtimeError = PyErr_NewException("numpyext.runtime", 0, 0);
    PyDict_SetItemString(d, "RuntimeException", pynumpyext_runtimeError);

    // numpy
    import_array();

    return MOD_SUCCESS_VAL(m);
}

// version
// $Id$

// End of file
