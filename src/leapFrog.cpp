#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "readXYZ.h"
#include "leapFrog.h"
#include <cmath>

using namespace leapFrogName;
using namespace std; 	// cout instead of std::cout

double f[3];

void leapFrogClass::writeXYZ(int t, double **xyz, int num){
 FILE* outputFile=fopen("traj.xyz","a");	// append
 fprintf(outputFile,"%i\n",num);
 fprintf(outputFile,"box\n");
 for(int p=0;p<num;p++){
  fprintf(outputFile,"%c %f %f %f\n",type[p],xyz[p][0],xyz[p][1],xyz[p][2]);
 }
 fclose(outputFile);
}

double* force(int t, int p1, double **xyz, double *sig, double *eps, int num){

/* calculates force acting on a particular atom */

   f[0]=0.000;
   f[1]=0.000;
   f[2]=0.000;

   for(int p2=0;p2<num;p2++){
    if(p1!=p2){
     double dx=xyz[p1][0]-xyz[p2][0];
     double dy=xyz[p1][1]-xyz[p2][1];
     double dz=xyz[p1][2]-xyz[p2][2];

     double dxx=dx*dx;
     double dyy=dy*dy;
     double dzz=dz*dz;

     double epsilon=sqrt(eps[p1]*eps[p2]);
     double sigma=(sig[p1]+sig[p2])*0.5;

     double sigma2=sigma*sigma;
     double r2=dx*dx+dy*dy+dz*dz;
     double fr2=sigma2/r2;
     double fr6=fr2*fr2*fr2;
     double fpr=48.0*epsilon*fr6*(fr6-0.5)/r2;

     f[0]=f[0]+fpr*dx;
     f[1]=f[1]+fpr*dy;
     f[2]=f[2]+fpr*dz;
  }
 }

// printf("ForceX %i %i %f %f %f\n",t,p1,f[0],f[1],f[2]);

 return f;
}

void pbc(double *xyz){

/* applies periodic boundary conditions */

 double box[3];
 box[0]=30.0;
 box[1]=30.0;
 box[2]=30.0;

 for(int i=0;i<=2;i++){
  if(xyz[i]<0.0){
   xyz[i]=xyz[i]+box[i];
  }
  else if(xyz[i]>box[i]){
   xyz[i]=xyz[i]-box[i];
  }
 }
}

void leapFrogClass::step(double dt, int steps, double **xyz, double *mass, double *sig, double *eps, double **vel, int num){

 for(int t=1;t<=steps;t++){
  for(int p=0;p<num;p++){

//   force(t,p,xyz);
   double* ptrForce=force(t,p,xyz,sig,eps,num);
//   printf("Force: %f %f %f\n",ptrForce[0],ptrForce[1],ptrForce[2]);

   vel[p][0]=vel[p][0]+0.5*dt*ptrForce[0]/mass[p];
   vel[p][1]=vel[p][1]+0.5*dt*ptrForce[1]/mass[p];
   vel[p][2]=vel[p][2]+0.5*dt*ptrForce[2]/mass[p];
    
   xyz[p][0]=xyz[p][0]+dt*vel[p][0];
   xyz[p][1]=xyz[p][1]+dt*vel[p][1];
   xyz[p][2]=xyz[p][2]+dt*vel[p][2];

   pbc(xyz[p]);

  }
  leapFrogClass::writeXYZ(t,xyz,num);
 }

}
