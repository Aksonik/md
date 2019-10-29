#ifndef LEAPFROG_H
#define LEAPFROG_H

#include <string>
#include "readOpt.h"

using namespace readOptName;

namespace leapFrogName{
 class leapFrogClass : public readOptClass{ 

  public:
   char* type;
   void writeXYZ(int, double**, int);
   void step(double**,double*,double*,double*,double**,int);
   void pbc(double*);
   double* force(int, int, double**, double*, double*, int);
 };
}

#endif
