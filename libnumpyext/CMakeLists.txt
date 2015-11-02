cmake_minimum_required (VERSION 2.6)
project (libnumpyext)

find_package ( PythonLibs )
include_directories( ${PYTHON_INCLUDE_DIRS} )

set ( SRC_FILES 
  Iterator1D.cc
  )

set ( INC_FILES
  Iterator1D.h
  VoidPtr.h
  )

add_library ( numpyext SHARED ${SRC_FILES} ${INC_FILES} )

install (FILES ${INC_FILES} DESTINATION include/numpyext)
install (TARGETS numpyext
  LIBRARY DESTINATION lib
  )
