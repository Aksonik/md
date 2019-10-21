#include <math.h>
#include <string>

class usefulClass{
 public:

  double dist3D(double x1,double y1,double z1,double x2,double y2,double z2){
   /* calculates distance between two points */
   double d;
   d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
   return d;
  }

  int numLines(std::string fileName){
  /* reads number of lines of the file */
   int l=0;
   char ch;

   FILE* inputFile=fopen(fileName.c_str(),"r");

   while(!feof(inputFile)){
    ch=fgetc(inputFile);
    if(ch=='\n'){
     l++;
    }
   }

  fclose(inputFile);
  return l;
  }
};
