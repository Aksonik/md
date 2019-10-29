#ifndef READFF_H
#define READFF_H

//#include <string>
#include "readXYZ.h"

using namespace xyzName;

namespace readFFName{
 class readFFClass : public readXYZClass{
  public:
   double* mass;
   double* sig;
   double* eps;

   readFFClass(int num){
    mass=new double[num];
    sig=new double[num];
    eps=new double[num];
   };
   void setFF(int,char*);
 };
}

#endif
