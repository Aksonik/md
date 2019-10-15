#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std; 	// cout instead of std::cout
using namespace xyz;

int main(){

  double x,y,z;		// coordinates
  double bx,by,bz;	// box size
  char n;		// atom type
  int m;		// number of atoms

  char ch;
  int l=1;		// line

  FILE* inputFile=fopen("sys.xyz","r");
  char* buf[100];

  while(!feof(inputFile)){
//   printf("Line: %i\n",l);
   if(l==1){
    fscanf(inputFile,"%i",&m);
//    printf("atoms: %i\n",m);
   }
   else if(l==2){
    fscanf(inputFile,"%lf %lf %lf",&bx,&by,&bz);
//    printf("box: %lf %lf %lf\n",bx,by,bz);
   }
   else{
    fscanf(inputFile,"%c %lf %lf %lf",&n,&x,&y,&z);
//    printf("coor: %c %lf %lf %lf\n",n,x,y,z);
   }
   ch=fgetc(inputFile);
   if(ch=='\n'){
    l++;
   }
  }

  fclose(inputFile);

 return 0;
}
