#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "genVel.h"
#include <cstdlib>
#include <ctime>

using namespace genVelName;
using namespace std; 	// cout instead of std::cout

void genVelClass::genVel(int num){
/* generates random initial velocities for num particles */

 srand(time(0));		// generates seed for rand()

 for(int n=0;n<num;n++){
  for(int d=0;d<3;d++){
   vel[n][d]=(rand()%20000+1-10000)*0.001;	// in range -10.000 to 10.000
  }
 }
}
