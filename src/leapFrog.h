#ifndef LEAPFROG_H
#define LEAPFROG_H

#include <string>

namespace leapFrogName{
 class leapFrogClass { 

  public:
   char* type;
   std::string trajectory;
   void writeXYZ(int, double**, int);
   void step(double, int, double**, double*, double*, double*, double**, int);
 };
}

#endif
