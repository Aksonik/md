#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector> 
#include "readOpt.h"

using namespace std; 	// cout instead of std::cout
using namespace readOptName;

void readOptClass::getOpt(int &steps2, double &dt){

/* reads the options file */

 int steps;
 float timeStep;
 float box[3];

 ifstream inputFile ("/home/nawrocki/Documents/scr/git/cpp_project/md/md/test/sys.opt2");

 if(inputFile.is_open()){

  int l=0;
  string line;

  while(getline(inputFile,line)){
   l++;
   stringstream wordsBuf(line);		// stringstream to isolate words using operator >>
   int w=0;
   string word;
   vector <string> fileContent;

   while(wordsBuf>>word){
    w++;
    fileContent.push_back(word);  	// store words in a vector
   }

   if(fileContent[0]=="steps:"){
    istringstream stoi(fileContent[1]);
    stoi>>steps;
   }
   if((fileContent[0]=="time")&&(fileContent[1]=="step:")){
    istringstream stoi(fileContent[2]);
    stoi>>timeStep;
   }
   if((fileContent[0]=="box")&&(fileContent[1]=="size:")){
    {istringstream stoi(fileContent[2]);stoi>>box[0];}
    {istringstream stoi(fileContent[3]);stoi>>box[1];}
    {istringstream stoi(fileContent[4]);stoi>>box[2];}
   }

  }
  inputFile.close ();
 }
 printf("Number of steps: %i\n",steps);
 printf("Time step: %f\n",timeStep);
 printf("Box size: %f %f %f\n",box[0],box[1],box[2]);
 steps2=steps;
 dt=timeStep;
}

//   for(int i=0; i<fileContent.size(); ++i){
//   }

