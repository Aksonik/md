#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "readXYZ.h"

using namespace xyzName;
using namespace std; 	// cout instead of std::cout

int readXYZClass::getNum(){
/* reads number of atoms */

 int l=1;		// line
 int num;

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
 return num;
}

double** readXYZClass::getXYZ(int num, char *type){
/* reads atoms coordinates */

 int l=1;		// line
 int i=0;		// index of an atom

 FILE* inputFile=fopen(initXYZ.c_str(),"r");

 double** xyz;
 xyz=new double*[num];

 while(!feof(inputFile)){
  ch=fgetc(inputFile);
  if(ch=='\n'){
   l++;
  }

  if(l>=3){
   if(i<=num-1){
    xyz[i]=new double[3];
   }
   if(fscanf(inputFile,"%c %lf %lf %lf",&type[i],&(xyz[i][0]),&(xyz[i][1]),&(xyz[i][2]))>0){
    i++;
   }
  }
 }

 fclose(inputFile);

 return xyz;
}

double* readXYZClass::getBox(){
/* reads initial box size */

 int l=1;		// line

 FILE* inputFile=fopen(initXYZ.c_str(),"r");

 while(!feof(inputFile) && l<2){
  ch=fgetc(inputFile);
  if(ch=='\n'){
   l++;			// new line
  }
  if(l==2){
   fscanf(inputFile,"%lf %lf %lf",&box[0],&box[1],&box[2]);
  }
 }

 fclose(inputFile);
 return box;
}
