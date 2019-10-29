#ifndef READOPT_H
#define READOPT_H

#include <string>

namespace readOptName{
 class readOptClass{
  public:
   std::string optFile;

   int steps;
   double dt;
   std::string initXYZ;		// do not use namespace in headers
   std::string fileFF;
   std::string trajFile;
   int saveFrq;
   double* box;

   readOptClass(){	// set default options
    steps=0;
    dt=0.001;
    initXYZ="init.xyz";
    fileFF="ff.dat";
    trajFile="traj.xyz";
    saveFrq=10;
    box=new double[3];
   }
   void getOpt();
 };
}

#endif
