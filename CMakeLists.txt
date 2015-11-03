cmake_minimum_required (VERSION 2.6)
project (numpyext)

set(VERSION "0.1")
set(AUTHOR "Jiao Lin")
set(VENDOR "DANSE")
set(SUMMARY "limited utils for get data ptr from numpy array")
set(LICENSE "BSD")
set(RPM_APP_GROUP "Library/Misc")


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")

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

# packaging
set(CPACK_PACKAGE_VERSION ${VERSION})
# set(CPACK_GENERATOR  "RPM")
set(CPACK_PACKAGE_NAME ${PARENT_PY_PKG}.${PROJECT_NAME})
set(CPACK_PACKAGE_SUMMARY ${SUMMARY})
set(CPACK_PACKAGE_LICENSE ${LICENSE})
set(CPACK_PACKAGE_RELEASE 0)
set(CPACK_PACKAGE_APP_GROUP ${RPM_APP_GROUP})
set(CPACK_PACKAGE_CONTACT ${AUTHOR})
set(CPACK_PACKAGE_VENDOR ${VENDOR})
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)
include(UseRPMTools)
IF(RPMTools_FOUND)
  RPMTools_ADD_RPM_TARGETS("${LIB_NAME}" ${CMAKE_SOURCE_DIR}/rpm.spec.in)
ENDIF(RPMTools_FOUND)
