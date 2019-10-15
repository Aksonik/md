#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "readFF.h"

using namespace readFFName;
using namespace std; 	// cout instead of std::cout

void readFFClass::setFF(int num,char *type,double *mass,double *sig,double *eps){

// char ch;
// int l=1;		// line
 int i=0;		// index of an atom

 char typeFF[3];
 double massFF[3];
 double sigFF[3];
 double epsFF[3];

 FILE* inputFile=fopen("/home/nawrocki/Documents/scr/git/cpp_project/md/md/test/sys.ff","r");

 while(!feof(inputFile)){
/*  ch=fgetc(inputFile);
  if(ch=='\n'){
   l++;
  }
*/
  if(fscanf(inputFile,"%c %lf %lf %lf",&typeFF[i],&massFF[i],&sigFF[i],&epsFF[i])==4){
//   printf("FF: %c %lf %lf %lf\n",typeFF[i],massFF[i],sigFF[i],epsFF[i]);
   i++;
  }
 }

 for(int n=0;n<num;n++){
  for(int m=0;m<3;m++){
   if(type[n]==typeFF[m]){
    mass[n]=massFF[m];
    sig[n]=sigFF[m];
    eps[n]=epsFF[m];
   }
  }
 }

 fclose(inputFile);
}
