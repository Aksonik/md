#ifndef READXYZ_H
#define READXYZ_H

namespace xyzName{
 class readXYZClass{
  public:
   double box[3];	// box size
   char n[9];			// atom type
   int m;			// number of atoms
   double** getXYZ(char*);
   double* getBox();
   int getNum();
   readXYZClass(){		// the same name as class, called when object created
    printf("constructor: here some variables might be initialized.\n");
   }
 };
}

#endif
