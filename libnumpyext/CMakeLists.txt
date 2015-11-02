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
include_directories( ${PYTHON_INCLUDE_DIRS} )

# export headers from this project
foreach (header ${EXPORT_HEADERS})
  configure_file(
    "${header}"
    "${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}/${header}"
    )
endforeach (header)

# compile shared lib
add_library ( ${PROJECT_NAME} SHARED ${SRC_FILES} ${INC_FILES} )

# install headers
install (
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME} 
  DESTINATION include)
# install shared lib
install (TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  )
