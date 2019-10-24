#ifndef READOPT_H
#define READOPT_H

#include <string>	// do not use namespace in headers

namespace readOptName{
 class readOptClass{
  public:
   std::string optFile;
   void getOpt(int&, double&,std::string&,std::string&,std::string&);
 };
}

#endif
