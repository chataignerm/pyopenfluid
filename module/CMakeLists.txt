#
# CMake build for PyOpenFLUID
#
# Author : Bastien VAYSSE <bastien.vaysse@supagro.inra.fr>
#

SET(pyopenfluid_script
    __init__.py
    PyOpenFLUID.py)
# copy PyOpenFLUID module (python files) of the library and configure them
FOREACH(script ${pyopenfluid_script})
  CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${script}.in"
      "${PYTHON_OUTPUT_SRC_PATH}/${script}" @ONLY)
ENDFOREACH(script)


# build final path+name of pyopenfluid library
GET_PROPERTY(PYOPENFLUID_DYNAMIC_LIBRARY_RAWNAME TARGET PyOpenFLUID PROPERTY OUTPUT_NAME)
GET_PROPERTY(PYOPENFLUID_DYNAMIC_LIBRARY_PREFIX TARGET PyOpenFLUID PROPERTY PREFIX)
SET(PYOPENFLUID_DYNAMIC_LIBRARY_NAME "${PYOPENFLUID_DYNAMIC_LIBRARY_PREFIX}${PYOPENFLUID_DYNAMIC_LIBRARY_RAWNAME}${CMAKE_SHARED_LIBRARY_SUFFIX}")

# configuration setup.py
CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in"
    "${PYTHON_OUTPUT_PATH}/setup.py" @ONLY)
