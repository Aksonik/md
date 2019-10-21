#ifndef READXYZ_H
#define READXYZ_H

#include <string>

namespace xyzName{
 class readXYZClass{
  public:

   std::string initXYZ;		// initXYZ=file.xyz - static data cannot be initialized

   double box[3];	// box size

   readXYZClass(){		// the same name as class, called when object is being created
    printf("constructor: some variables might be initialized here.\n");
   }

   double** getXYZ(int, char*);
   double* getBox();
   int getNum();

  private:
   char ch;		// variable known within the class
 };
}

#endif
