#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "readXYZ.h"

using namespace xyzName;
using namespace std; 	// cout instead of std::cout

void readXYZClass::getNum(){
/* reads number of atoms */

 int l=1;		// line

 FILE* inputFile=fopen(initXYZ.c_str(),"r");

 while(!feof(inputFile) && l==1){
  if(l==1){
   fscanf(inputFile,"%i",&num);
  }
  ch=fgetc(inputFile);	// goes one character every loop iteration
  if(ch=='\n'){
   l++;			// new line
  }
 }
 fclose(inputFile);
}

double** readXYZClass::getXYZ(){
/* reads atoms coordinates */

 int l=1;		// line
 int i=0;		// index of an atom

 FILE* inputFile=fopen(initXYZ.c_str(),"r");

 while(!feof(inputFile)){
  ch=fgetc(inputFile);
  if(ch=='\n'){
   l++;
  }
  if(l>=3){
   if(i<=num-1){
   }
   if(fscanf(inputFile,"%c %lf %lf %lf",&type[i],&(xyz[i][0]),&(xyz[i][1]),&(xyz[i][2]))>0){
    i++;
   }
  }
 }

 fclose(inputFile);
}
