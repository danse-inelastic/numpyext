# ------------- Modify these -------------
set ( SRC_FILES 
  Iterator1D.cc
  )

set ( INC_FILES
  Iterator1D.h
  VoidPtr.h
  )

set ( EXPORT_HEADERS
  Iterator1D.h
  )
# ----------------------------------------

# include python headers
execute_process(COMMAND python -c "from __future__ import print_function; import numpy, os; print(os.path.join(os.path.dirname(numpy.__file__), 'core', 'include'))" OUTPUT_VARIABLE NUMPY_INCLUDE_DIR)
include_directories( ${PYTHON_INCLUDE_DIRS} ${NUMPY_INCLUDE_DIR})

# export headers from this project
foreach (header ${EXPORT_HEADERS})
  configure_file(
    "${header}"
    "${CMAKE_CURRENT_BINARY_DIR}/include/${PARENT_PATH}/${PROJECT_NAME}/${header}"
    )
endforeach (header)

# compile shared lib
add_library ( ${LIB_NAME} SHARED ${SRC_FILES} ${INC_FILES} )

# install headers
install (
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${PARENT_PATH}/${PROJECT_NAME}/
  DESTINATION include/${PARENT_PATH}/${PROJECT_NAME})
# install shared lib
install (TARGETS ${LIB_NAME}
  LIBRARY DESTINATION ${INSTALL_LIB_DIR}
  )
