# ------------- Modify these -------------
set (SRC_FILES
  __init__.py
  )
# ----------------------------------------


set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
# configure_file(${SETUP_PY_IN} ${SETUP_PY})
configure_file("setup.py.in" "setup.py")

configure_file("MANIFEST.in" "MANIFEST.in")

# copy all python source over to build directory
foreach (py ${SRC_FILES})
  configure_file(
    "${PROJECT_NAME}/${py}"
    "${PROJECT_NAME}/${py}"
    )
endforeach (py)

set(DEPS        "${SRC_FILES} ${PYBINDING_NAME}")
PREPEND(DEPS ${PYBINDING_NAME})
set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/build/timestamp")


add_custom_command(OUTPUT ${OUTPUT}
  COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} build
  COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT}
  DEPENDS ${DEPS})

add_custom_target(target ALL DEPENDS ${OUTPUT})

install(CODE "execute_process(COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} install --prefix=${CMAKE_INSTALL_PREFIX})")
