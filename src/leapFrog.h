#ifndef LEAPFROG_H
#define LEAPFROG_H

namespace leapFrogName{
 class leapFrogClass { 

  public:
   char* type;
   void writeXYZ(int, double**, int);
   void step(double, int, double**, double*, double*, double*, double**, int);
 };
}

#endif
