# ------------- Modify these -------------
set (SRC_FILES
  __init__.py
  )
# ----------------------------------------


# setup.py
set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
configure_file("setup.py.in" "setup.py")

# manifest template. need for proper installation
configure_file("MANIFEST.in" "MANIFEST.in")

# copy all python source over to build directory
foreach (py ${SRC_FILES})
  configure_file(
    "${PROJECT_NAME}/${py}"
    "${PARENT_PATH}/${PROJECT_NAME}/${py}"
    )
endforeach (py)

# use a timestamp to connect dependency of the target
# on the python source files and also the binding modules
set(DEPS        "${SRC_FILES} ${PYBINDING_NAME}")
PREPEND(DEPS ${PYBINDING_NAME})
set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/build/timestamp")
# use setup.py to build and then update time stamp
add_custom_command(OUTPUT ${OUTPUT}
  COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} build
  COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT}
  DEPENDS ${DEPS})
# 
add_custom_target(pypkg ALL DEPENDS ${OUTPUT})

# install
# have to specify working_directory otherwise manifest.in is not used
set(INSTALL_PY_PATH "${INSTALL_LIB_DIR}/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages")
install(CODE "execute_process(WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/python COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} install --home=${CMAKE_INSTALL_PREFIX} --install-purelib=${INSTALL_PY_PATH} )")
