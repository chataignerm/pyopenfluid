#include <string>
#include <vector>
#include <list>
#include <map>
#include <boost/python.hpp>
#include <Python.h>
#include <sstream>


namespace tools {

std::string stringFill (const std::string Input, const std::string StrFill,
    int MaxLength)
{
  std::string Res = std::string(Input);
  while (Res.length() < MaxLength)
    Res = StrFill + Res;
  return Res;
}


// =====================================================================
// =====================================================================


std::string zeroFill (const std::string Input, int MaxLength)
{
  return stringFill(Input, std::string("0"), MaxLength);
}

} // tools


// =====================================================================
// =====================================================================


namespace topython {

void printStdOut (std::string& Message, int EOL=0)
{
  int LenMsg = Message.length();

  if (LenMsg >= 1000)
  {
    int NFois = LenMsg / 999;
    std::string TmpString;
    int i;

    for (i=0; i<NFois; i++)
    {
      TmpString = Message.substr(i*999, 999);
      PySys_WriteStdout("%.999s", TmpString.c_str());
    }

    i = NFois*999;
    TmpString = Message.substr(i, (LenMsg-i));
    PySys_WriteStdout("%.999s", TmpString.c_str());
  }
  else
    PySys_WriteStdout("%.999s", Message.c_str());

  if (EOL)
    PySys_WriteStdout("\n");
}


// =====================================================================
// =====================================================================


void printStdErr (std::string& Message, int EOL=0)
{
  int LenMsg = Message.length();

  if (LenMsg >= 1000)
  {
    int NFois = LenMsg / 999;
    std::string TmpString;
    int i;

    for (i=0; i<NFois; i++)
    {
      TmpString = Message.substr(i*999, 999);
      PySys_WriteStderr("%.999s", TmpString.c_str());
    }

    i = NFois*999;
    TmpString = Message.substr(i, (LenMsg-i));
    PySys_WriteStderr("%.999s", TmpString.c_str());
  }
  else
    PySys_WriteStderr("%.999s", Message.c_str());

  if (EOL)
    PySys_WriteStderr("\n");
}


// =====================================================================
// =====================================================================


void printStdOut (const char* CharMessage, int EOL=0)
{
  std::string Message = std::string(CharMessage);
  printStdOut(Message, EOL);
}


// =====================================================================
// =====================================================================


void printStdErr (const char* CharMessage, int EOL=0)
{
  std::string Message = std::string(CharMessage);
  printStdOut(Message, EOL);
}


// =====================================================================
// =====================================================================


void printStdOut (std::stringstream& StringStream, int EOL=0)
{
  std::string Message = StringStream.str();
  printStdOut(Message, EOL);
}


// =====================================================================
// =====================================================================


void printStdErr (std::stringstream& StringStream, int EOL=0)
{
  std::string Message = StringStream.str();
  printStdOut(Message, EOL);
}


// =====================================================================
// =====================================================================


void printStdOut (std::iostream& IOStream, int EOL=0)
{
  std::string StringMessage;
  IOStream >> StringMessage;
  printStdOut(StringMessage, EOL);
}


// =====================================================================
// =====================================================================


void printStdErr (std::iostream& IOStream, int EOL=0)
{
  std::string StringMessage;
  IOStream >> StringMessage;
  printStdOut(StringMessage, EOL);
}


} // topython