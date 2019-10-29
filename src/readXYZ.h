#ifndef READXYZ_H
#define READXYZ_H

//#include <string>
#include "readOpt.h"

using namespace readOptName;

namespace xyzName {
 class readXYZClass : public readOptClass{
  public:
   int num;
   char* type;		// declare array of unknown size for atom types
   double** xyz;

   void getNum();	// get number of atoms
   void decType(){
    type=new char[num];
   }
   void decXYZ(){
    xyz=new double*[num];
    for(int i=0;i<=num;i++){
     xyz[i]=new double[3];
    }
   }
   double** getXYZ();
  private:
   char ch;		// variable known within the class
 };
}

#endif
