#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <useful.h>
#include "readFF.h"

using namespace readFFName;
using namespace std; 	// cout instead of std::cout

void readFFClass::setFF(int num,char *type,double *mass,double *sig,double *eps){
/* reads FF parameters */

 int i=0;		// atom index
 int numTypes;		// number of atom types

 usefulClass usefulObj;
 numTypes=usefulObj.numLines(fileFF.c_str());

 char typeFF[numTypes];
 double massFF[numTypes];
 double sigFF[numTypes];
 double epsFF[numTypes];

 FILE* inputFile=fopen(fileFF.c_str(),"r");

/* doesn't work correctly when type is N */

 while(!feof(inputFile)){
  if(fscanf(inputFile,"%c %lf %lf %lf",&typeFF[i],&massFF[i],&sigFF[i],&epsFF[i])==4){
   printf("FF read: %c %lf %lf %lf\n",typeFF[i],massFF[i],sigFF[i],epsFF[i]);
   i++;
  }
 }

 for(int n=0;n<num;n++){
  for(int m=0;m<numTypes;m++){
   if(type[n]==typeFF[m]){
    mass[n]=massFF[m];
    sig[n]=sigFF[m];
    eps[n]=epsFF[m];
   }
  }
 }

 fclose(inputFile);
}
