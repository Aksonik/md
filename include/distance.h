#include <math.h>

class usefulClass{
 public:
  double x1,y1,z1;
  double x2,y2,z2;
  double d;
  double distanceFunction(double x1,double y1,double z1,double x2,double y2,double z2)
  {d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
   return d;
  };
};
