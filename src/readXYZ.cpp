#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "readXYZ.h"

using namespace xyzName;
using namespace std; 	// cout instead of std::cout

int readXYZClass::getNum(){

/* reads number of atoms */

 char ch;
 int l=1;		// line
 int num;

 FILE* inputFile=fopen("/home/nawrocki/Documents/scr/git/cpp_project/md/md/test/sys.xyz","r");

 while(!feof(inputFile) && l==1){
//  printf("Line XYZ: %i\n",l);
  if(l==1){
   fscanf(inputFile,"%i",&num);
//   printf("Number of atoms: %i\n",num);
  }
  ch=fgetc(inputFile);	// goes character by character every loop iteration
//  printf("Char XYZ: %c\n",ch);
  if(ch=='\n'){
   l++;			// new line
  }
 }
 fclose(inputFile);
 return num;
}

double** readXYZClass::getXYZ(char *type){

/* reads atoms coordinates */

 char ch;
 int l=1;		// line
 int i=0;		// index of an atom

 FILE* inputFile=fopen("/home/nawrocki/Documents/scr/git/cpp_project/md/md/test/sys.xyz","r");

 double** xyz;
 xyz=new double*[9];

 type[3]='Q';

 while(!feof(inputFile)){
  ch=fgetc(inputFile);
//  printf("Char XYZ: %c\n",ch);
  if(ch=='\n'){
   l++;
  }
//  printf("Line XYZ: %i\n",l);

  if(l>=3){
   if(i<=8){
//    printf("%i\n",i);
    xyz[i]=new double[3];
   };
   if(fscanf(inputFile,"%c %lf %lf %lf",&type[i],&(xyz[i][0]),&(xyz[i][1]),&(xyz[i][2]))>0){
//    printf("coor XYZ: %c %lf %lf %lf\n",n[i],xyz[i][0],xyz[i][1],xyz[i][2]);
    i++;
   }
  }
 }

 fclose(inputFile);

 return xyz;
}

double* readXYZClass::getBox(){

/* reads initial box size */

 char ch;
 int l=1;		// line

 FILE* inputFile=fopen("/home/nawrocki/Documents/scr/git/cpp_project/md/md/test/sys.xyz","r");

 while(!feof(inputFile) && l<2){
  ch=fgetc(inputFile);
  if(ch=='\n'){
   l++;			// new line
  }
  if(l==2){
   fscanf(inputFile,"%lf %lf %lf",&box[0],&box[1],&box[2]);
//   printf("box: %lf %lf %lf\n",box[0],box[1],box[2]);
  }
 }

 fclose(inputFile);
 return box;
}
