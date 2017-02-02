#if !defined WRITE_FILE
#define WRITE_FILE
//using CSC2110::WriteFile; //indicates that you will be using a particular class in a particular namespace

#include "Text.h"
using CSC2110::String;

#include <fstream>
using namespace std;

namespace CSC2110
{
class WriteFile
{
   private:
      ofstream* output_file;
      bool closed;

   public:
      WriteFile(const char* file_name);
      ~WriteFile();
      void writeLine(String* line);
      void close();
};
}

#endif
