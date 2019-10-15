#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <distance.h>
#include "readXYZ.h"
#include "leapFrog.h"
#include "readOpt.h"
#include "readFF.h"
#include "genVel.h"

using namespace std;
using namespace xyzName;
using namespace leapFrogName;
using namespace readOptName;
using namespace readFFName;
using namespace genVelName;

int main(int argc,char *argv[]){

/* 
 to read input from command line and apply libraries

 double n1=atof(argv[1]);
 double n2=atof(argv[2]);

 printf("input: %f %f\n",n1,n2);

 usefulClass usefulObject;
 printf("distance: %f\n",usefulObject.distanceFunction(n1,n1,n1,n2,n2,n2));
*/

 readXYZClass xyzObject;

 int num=xyzObject.getNum();
 printf("Number of atoms: %i\n",num);

 double* boxPtr=xyzObject.getBox();
 printf("Box size [A]: %f %f %f\n",boxPtr[0],boxPtr[1],boxPtr[2]);


/* initialize atom types and FF parameters: mass, sigma and epsilon */

 char type[num];
 double mass[num];
 double sig[num];
 double eps[num];

 for(int n=0;n<num;n++){
  type[n]='X';
  mass[n]=1.000;
  sig[n]=1.000;
  eps[n]=100.000;
 }

 xyzObject.getXYZ(type);	// substitute atom types

 for(int n=0;n<num;n++){
  printf("Atom type: %c\n",type[n]);
 }

// xyzObject.getXYZ();
 double** xyzPtr=xyzObject.getXYZ(type);
 for(int n=0;n<num;n++){
  printf("Coor: %f %f %f\n",xyzPtr[n][0],xyzPtr[n][1],xyzPtr[n][2]);
 }


 readFFClass objectFF;
 objectFF.setFF(num,type,mass,sig,eps);		// set FF parameters

 for(int n=0;n<num;n++){
  printf("FF: %lf %lf %lf\n",mass[n],sig[n],eps[n]);
 }

 genVelClass genVelObj;
 double** velPtr=genVelObj.genVel(num);

 for(int n=0;n<num;n++){
  printf("Vel: %f %f %f\n",velPtr[n][0],velPtr[n][1],velPtr[n][2]);
 }

/* default options */ 
 int steps=0;
 double dt=0.002;

 readOptClass objectOpt;
 objectOpt.getOpt(steps,dt);		// substitute default options
 printf("Number of steps: %i\n",steps);
 printf("Time step: %f\n",dt);

 leapFrogClass leapFrogObject;
 leapFrogObject.step(dt,steps,xyzPtr,mass,sig,eps,velPtr);



 return 0;
}
