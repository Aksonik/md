#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;

int main(){

  int f; 		// frame
  double x,y,z;		// coordinates
  double bx,by,bz;	// box size
  char n;		// atom type
  int m;		// number of atoms

  char ch;
  int l=1;		// line

  FILE* ptr=fopen("sys.xyz","r");
  char* buf[100];

  while(!feof(ptr)){
//   printf("Line: %i\n",l);
   if(l==1){
    fscanf(ptr,"%i",&m);
//    printf("atoms: %i\n",m);
   }
   else if(l==2){
    fscanf(ptr,"%lf %lf %lf",&bx,&by,&bz);
//    printf("box: %lf %lf %lf\n",bx,by,bz);
   }
   else{
    fscanf(ptr,"%c %lf %lf %lf",&n,&x,&y,&z);
//    printf("coor: %c %lf %lf %lf\n",n,x,y,z);
   }
   ch=fgetc(ptr);
   if(ch=='\n'){
    l++;
   }
  }

  fclose(ptr);

 return 0;
}
