#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <useful.h>	// libraries go here

#include "readXYZ.h"
#include "readOpt.h"
#include "readFF.h"
#include "genVel.h"
#include "leapFrog.h"

using namespace std;
using namespace xyzName;
using namespace leapFrogName;
using namespace readOptName;
using namespace readFFName;
using namespace genVelName;

int main(int argc,char *argv[]){

// run with a path to the option file as an argument
 string optFile=argv[1];
 printf("Options file: %s\n",optFile.c_str());

// read options file
 readOptClass readOptObj;
 readOptObj.optFile=optFile;
 readOptObj.getOpt();

// read initial XYZ file
 printf("Initial XYZ file: %s\n",readOptObj.initXYZ.c_str());

 readXYZClass xyzObject;
 xyzObject.initXYZ=readOptObj.initXYZ.c_str();

 xyzObject.getNum();
 printf("Number of atoms: %i\n",xyzObject.num);

 xyzObject.decType(); 	// declare atoms needs their number first
 xyzObject.decXYZ(); 

 xyzObject.getXYZ();

 for(int n=0;n<xyzObject.num;n++){
  printf("Atom: %c %f %f %f\n",xyzObject.type[n],
                               xyzObject.xyz[n][0],
                               xyzObject.xyz[n][1],
                               xyzObject.xyz[n][2]);
 }

// read force field file
 printf("Force field file: %s\n",readOptObj.fileFF.c_str());

 readFFClass readFFObj(xyzObject.num);
 
 readFFObj.fileFF=readOptObj.fileFF;
 readFFObj.setFF(xyzObject.num,xyzObject.type);		// set FF parameters

 for(int n=0;n<xyzObject.num;n++){
  printf("FF: %c %lf %lf %lf\n",xyzObject.type[n],
                                readFFObj.mass[n],
                                readFFObj.sig[n],
                                readFFObj.eps[n]);
 }

// generate velocities
 genVelClass genVelObj(xyzObject.num);
 genVelObj.genVel(xyzObject.num);

 for(int n=0;n<xyzObject.num;n++){
  printf("Vel: %f %f %f\n",genVelObj.vel[n][0],genVelObj.vel[n][1],genVelObj.vel[n][2]);
 }

// run a simulation
 leapFrogClass leapFrogObject;

 leapFrogObject.steps=readOptObj.steps;
 leapFrogObject.dt=readOptObj.dt;
 leapFrogObject.saveFrq=readOptObj.saveFrq;
 leapFrogObject.type=xyzObject.type;
 leapFrogObject.box=readOptObj.box;
 leapFrogObject.trajFile=readOptObj.trajFile;

 printf("Number of steps: %i\n",readOptObj.steps);
 printf("Time step: %f\n",readOptObj.dt);
 printf("Save frequency: %i\n",readOptObj.saveFrq);
 printf("Box size: %f %f %f\n",readOptObj.box[0],readOptObj.box[1],readOptObj.box[2]);

 leapFrogObject.step(xyzObject.xyz,readFFObj.mass,readFFObj.sig,readFFObj.eps,genVelObj.vel,xyzObject.num);

 return 0;
}
