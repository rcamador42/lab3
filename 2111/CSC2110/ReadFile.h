#if !defined READ_FILE_H
#define READ_FILE_H
//using CSC2110::ReadFile; //indicates that you will be using a particular class in a particular namespace


#include "Text.h"

#include <fstream>
using namespace std;

namespace CSC2110
{
class ReadFile
{
   private:
      ifstream* input_file;
      bool _eof;
      bool closed;

   public:
      ReadFile(const char* file_name);
      ~ReadFile();
      CSC2110::String* readLine();
	  
      bool eof();
      void close();
	  
	  static char* entireFile(const char* file_name);
};
}

#endif
