cmake_minimum_required (VERSION 2.6)
project (numpyext)

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
set (LIB_NAME "lib${PROJECT_NAME}")

# subdirs
add_subdirectory(${LIB_NAME})
add_subdirectory(${PYBINDING_NAME})
add_subdirectory(python)
