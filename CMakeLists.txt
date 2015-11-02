cmake_minimum_required (VERSION 2.6)
project (numpyext)

# needs python
find_package ( PythonLibs REQUIRED )
find_package ( PythonInterp REQUIRED )

# custom functions
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

# variables
set (PYBINDING_NAME "${PROJECT_NAME}module")
set (LIB_NAME "danse_ins_${PROJECT_NAME}")
set (PARENT_PATH "danse/ins")
set (PARENT_PY_PKG "danse.ins")

#
enable_testing()

# subdirs
add_subdirectory(lib)
add_subdirectory(pyext)
add_subdirectory(python)
add_subdirectory(tests)