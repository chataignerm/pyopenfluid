#
# CMake build for PyOpenFLUID
#
# Author : Bastien VAYSSE <bastien.vaysse@supagro.inra.fr>
#

INCLUDE(DocStrings.cmake)


# create boost, python and doxygen docstrings
STRING(ASCII 35 HASH)
SET(DOXYGEN_DOC_PREFIX "    ${HASH} ")

FUNCTION(ADDTOVAR NAMEVAR CONTENT)
  SET(${NAMEVAR} "${${NAMEVAR}}${CONTENT}" PARENT_SCOPE)
ENDFUNCTION()

FUNCTION(ADAPT_ADVANCED_DOCSTRING FUNCTIONNAME)
  # init
  SET(TMPBUFFER_BO "")
  SET(TMPBUFFER_PY "")
  SET(TMPBUFFER_DX "")

  # description
  SET(DESC_LENGTH -1)
  STRING(LENGTH "${DOCSTRINGRAW_DESCRIPTION_${FUNCTIONNAME}}" DESC_LENGTH)
  IF (${DESC_LENGTH} GREATER 0)
    ADDTOVAR(TMPBUFFER_BO "${DOCSTRINGRAW_DESCRIPTION_${FUNCTIONNAME}}")
    ADDTOVAR(TMPBUFFER_PY "${DOCSTRINGRAW_DESCRIPTION_${FUNCTIONNAME}}")
    ADDTOVAR(TMPBUFFER_DX "\n@brief ${DOCSTRINGRAW_DESCRIPTION_${FUNCTIONNAME}}")
  ENDIF (${DESC_LENGTH} GREATER 0)

  # parameters
  SET(PARAMETERS_LENGTH -1)
  STRING(LENGTH "${DOCSTRINGRAW_PARAMETERS_${FUNCTIONNAME}}" PARAMETERS_LENGTH)
  IF (${PARAMETERS_LENGTH} GREATER 0)
    ADDTOVAR(TMPBUFFER_BO "\\n\\nKeyword arguments:")
    ADDTOVAR(TMPBUFFER_PY "\n\nKeyword arguments:")
    ADDTOVAR(TMPBUFFER_DX "\n")
  ENDIF (${PARAMETERS_LENGTH} GREATER 0)
  FOREACH(PARAMETER ${DOCSTRINGRAW_PARAMETERS_${FUNCTIONNAME}})
    ADDTOVAR(TMPBUFFER_BO "\\n${PARAMETER}")
    ADDTOVAR(TMPBUFFER_PY "\\n${PARAMETER}")
    STRING(REPLACE "--" "  " PARAMETER_DX "${PARAMETER}")
    ADDTOVAR(TMPBUFFER_DX "\n@param ${PARAMETER_DX}")
  ENDFOREACH()

  # optional parameters
  SET(PARAMETERS_LENGTH -1)
  STRING(LENGTH "${DOCSTRINGRAW_OPTIONAL_PARAMETERS_${FUNCTIONNAME}}" PARAMETERS_LENGTH)
  IF (${PARAMETERS_LENGTH} GREATER 0)
    ADDTOVAR(TMPBUFFER_BO "\\n\\nOptional arguments:")
    ADDTOVAR(TMPBUFFER_PY "\n\nOptional arguments:")
    ADDTOVAR(TMPBUFFER_DX "\n")
  ENDIF (${PARAMETERS_LENGTH} GREATER 0)
  FOREACH(PARAMETER ${DOCSTRINGRAW_OPTIONAL_PARAMETERS_${FUNCTIONNAME}})
    ADDTOVAR(TMPBUFFER_BO "\\n${PARAMETER}")
    ADDTOVAR(TMPBUFFER_PY "\\n${PARAMETER}")
    STRING(REPLACE "--" "  " PARAMETER_DX "${PARAMETER}")
    ADDTOVAR(TMPBUFFER_DX "\n@param ${PARAMETER_DX}")
  ENDFOREACH()

  # return
  SET(RETURN_LENGTH -1)
  STRING(LENGTH "${DOCSTRINGRAW_RETURN_${FUNCTIONNAME}}" RETURN_LENGTH)
  IF (${RETURN_LENGTH} GREATER 0)
    ADDTOVAR(TMPBUFFER_BO "\\n\\nReturns:\\n${DOCSTRINGRAW_RETURN_${FUNCTIONNAME}}")
    ADDTOVAR(TMPBUFFER_PY "\n\nReturns:\n${DOCSTRINGRAW_RETURN_${FUNCTIONNAME}}")
    ADDTOVAR(TMPBUFFER_DX "\n\n@return ${DOCSTRINGRAW_RETURN_${FUNCTIONNAME}}")
  ENDIF (${RETURN_LENGTH} GREATER 0)

  # example (only for boost and python)
  SET(EXAMPLES_LENGTH -1)
  STRING(LENGTH "${DOCSTRINGRAW_EXAMPLES_${FUNCTIONNAME}}" EXAMPLES_LENGTH)
  IF (${EXAMPLES_LENGTH} GREATER 0)
    ADDTOVAR(TMPBUFFER_BO "\\n\\nExamples:\\n${DOCSTRINGRAW_EXAMPLES_${FUNCTIONNAME}}")
    ADDTOVAR(TMPBUFFER_PY "\n\nExamples:\n${DOCSTRINGRAW_EXAMPLES_${FUNCTIONNAME}}")
  ENDIF (${EXAMPLES_LENGTH} GREATER 0)

  # finalization
  STRING(REPLACE "\n" "\\n" TMPBUFFER_BO_FINAL "${TMPBUFFER_BO}")
  STRING(REPLACE "\n" "\\n" TMPBUFFER_PY_FINAL "${TMPBUFFER_PY}")
  STRING(REPLACE "\n" "\n${DOXYGEN_DOC_PREFIX}" TMPBUFFER_DX_FINAL "${TMPBUFFER_DX}")

  # recording
  SET(DOCSTRING_boost_${FUNCTIONNAME} "${TMPBUFFER_BO_FINAL}" CACHE INTERNAL "" FORCE)
  SET(DOCSTRING_python_${FUNCTIONNAME} "${TMPBUFFER_PY_FINAL}" CACHE INTERNAL "" FORCE)
  SET(DOCSTRING_doxygen_${FUNCTIONNAME} "${TMPBUFFER_DX_FINAL}" CACHE INTERNAL "" FORCE)
ENDFUNCTION()

FOREACH(FUNCTIONNAME ${DOCSTRING_ALL_FUNCTION_ADVANCED})
  ADAPT_ADVANCED_DOCSTRING("${FUNCTIONNAME}")
ENDFOREACH()
