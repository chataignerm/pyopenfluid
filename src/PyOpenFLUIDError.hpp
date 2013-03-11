#ifndef __PYOPENFLUIDERROR_HPP_
#define __PYOPENFLUIDERROR_HPP_

#include <Python.h>
#include <string>
#include <exception>

#define HANDLE_EXCEPTION \
catch (openfluid::base::OFException& E) \
{ \
  throw PyOFException(E.what()); \
} \
catch (std::bad_alloc& E) \
{ \
  throw PyOFException(std::string("MEMORY ALLOCATION ERROR, ") \
      + std::string(E.what()) \
      + std::string(". Possibly not enough memory available"), \
      PyExc_MemoryError); \
} \
catch (PyOFException& E) \
{ \
  throw E; \
} \
catch (std::exception& E) \
{ \
  throw PyOFException(std::string("SYSTEM ERROR, ") + std::string(E.what()), \
      PyExc_SystemError); \
} \
catch (...) \
{ \
  throw PyOFException("UNKNOWN ERROR", PyExc_RuntimeError); \
}


// =====================================================================
// ====================      GENERAL EXCEPTION      ====================


class PyOFException : std::exception
{
  public :

    PyOFException (PyObject* PyExcType = NULL);


// =====================================================================
// =====================================================================


    PyOFException (std::string InputMsg, PyObject* PyExcType = NULL);


// =====================================================================
// =====================================================================


    PyOFException (char* InputMsg, PyObject* PyExcType = NULL);


// =====================================================================
// =====================================================================


    PyOFException (const char* InputMsg, PyObject* PyExcType = NULL);


// =====================================================================
// =====================================================================


    inline virtual ~PyOFException () throw () {};


// =====================================================================
// =====================================================================


    inline const char* what() const throw() { return this->m_Message.c_str(); };


// =====================================================================
// =====================================================================


    inline PyObject* errorType() const { return this->m_Type; };


// =====================================================================
// =====================================================================


  private :
    std::string m_Message;
    PyObject* m_Type;
};


// =====================================================================
// ===================      TRANSLATOR EXCEPTION      ==================


void TranslatePyOFException (const PyOFException& e);

#endif // __PYOPENFLUIDERROR_HPP_
