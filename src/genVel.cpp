#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "genVel.h"
#include <cstdlib>
#include <ctime>

using namespace genVelName;
using namespace std; 	// cout instead of std::cout

double** genVelClass::genVel(int num){

/* generates random initial velocities for num particles */

double** vel;
vel=new double*[num];

srand(time(0));		// generates seed for rand()

for(int n=0;n<num;n++){
 vel[n]=new double[3];
 for(int d=0;d<3;d++){
  vel[n][d]=(rand()%20000+1-10000)*0.001;	// in range -10.000 to 10.000
 }
}

 return vel;
}
