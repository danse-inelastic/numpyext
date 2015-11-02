# ------------- Modify these -------------
set ( SRC_FILES 
  ${PYBINDING_NAME}.cc
  bindings.cc
  exceptions.cc
  getdataptr.cc
  misc.cc
  wrapdataptr.cc
  Iterator1D_Example.cc
  )
# ----------------------------------------

# alias
set ( MOD_NAME ${PYBINDING_NAME} )

# create empty portinfo (pyre-config thing)
execute_process(
  COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_BINARY_DIR}/${LIB_NAME}/include/portinfo
)

# -I and -L
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${CMAKE_BINARY_DIR}/${LIB_NAME}/include)
link_directories(${CMAKE_BINARY_DIR}/${LIB_NAME})

# compile shared library
add_library(${MOD_NAME} SHARED ${SRC_FILES})
target_link_libraries(${MOD_NAME} ${PYTHON_LIBRARY} -l"${PROJECT_NAME}")
set_target_properties(${MOD_NAME} PROPERTIES PREFIX "") # dont need "lib" prefix
set_target_properties(${MOD_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/python/${PROJECT_NAME}") # install to python directory
