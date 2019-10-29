#ifndef GENVEL_H
#define GENVEL_H

namespace genVelName{
 class genVelClass{
  public:
   double** vel;
   genVelClass(int num){
    vel=new double*[num];
    for(int i=0;i<num;i++){
     vel[i]=new double[3];
    }
   }
   void genVel(int);
 };
}

#endif
