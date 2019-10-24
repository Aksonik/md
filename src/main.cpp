#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <useful.h>
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

/* run with a path to the option file as an argument*/
string optFile=argv[1];
printf("Options file: %s\n",optFile.c_str());

/* default options */ 
 int steps=0;
 double dt=0.002;
 string initXYZ="init.xyz";
 string FF="ff.dat";
 string trajectory="traj.xyz";

 readOptClass objectOpt;
 objectOpt.optFile=optFile;
 objectOpt.getOpt(steps,dt,initXYZ,FF,trajectory);	// set options from the options file

 printf("Number of steps: %i\n",steps);
 printf("Time step: %f\n",dt);
 printf("Initial structure: %s\n",initXYZ.c_str());
 printf("Force field: %s\n",FF.c_str());

/* read initial structure */
 readXYZClass xyzObject;	// xyzObject(var) would pass var to the constructor readXYZClass
 xyzObject.initXYZ=initXYZ.c_str();

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

 xyzObject.getXYZ(num,type);	// substitute atom types

// for(int n=0;n<num;n++){
//  printf("Atom type: %c\n",type[n]);
// }

 double** xyzPtr=xyzObject.getXYZ(num,type);
 for(int n=0;n<num;n++){
  printf("Coor: %f %f %f\n",xyzPtr[n][0],xyzPtr[n][1],xyzPtr[n][2]);
 }


 readFFClass objectFF;
 objectFF.fileFF=FF;
 objectFF.setFF(num,type,mass,sig,eps);		// set FF parameters

 for(int n=0;n<num;n++){
  printf("FF: %c %lf %lf %lf\n",type[n],mass[n],sig[n],eps[n]);
 }

 genVelClass genVelObj;
 double** velPtr=genVelObj.genVel(num);

 for(int n=0;n<num;n++){
  printf("Vel: %f %f %f\n",velPtr[n][0],velPtr[n][1],velPtr[n][2]);
 }



 leapFrogClass leapFrogObject;
 leapFrogObject.type=type;
 leapFrogObject.trajectory=trajectory;
 leapFrogObject.step(dt,steps,xyzPtr,mass,sig,eps,velPtr,num);

 return 0;
}
