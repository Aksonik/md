#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector> 
#include "readOpt.h"

using namespace std; 	// cout instead of std::cout
using namespace readOptName;

void readOptClass::getOpt(int &steps2, double &dt, string &initXYZ, string &FF2, string &trajectory){
/* reads the options file */

 int steps;
 float timeStep;
 float box[3];

 ifstream inputFile (optFile.c_str());

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
    istringstream stoi(fileContent[1]);	// converts string to integer
    stoi>>steps;
   }
   if(fileContent[0]=="initial:"){
    initXYZ=fileContent[1];
   }
   if((fileContent[0]=="time")&&(fileContent[1]=="step:")){
    istringstream stoi(fileContent[2]);
    stoi>>timeStep;
   }
   if((fileContent[0]=="force")&&(fileContent[1]=="field:")){
    FF2=fileContent[2];
   }
/* does nothing - box size is read from the xyz file */
   if((fileContent[0]=="box")&&(fileContent[1]=="size:")){
    {istringstream stoi(fileContent[2]);stoi>>box[0];}
    {istringstream stoi(fileContent[3]);stoi>>box[1];}
    {istringstream stoi(fileContent[4]);stoi>>box[2];}
   }
   if(fileContent[0]=="trajectory:"){
    trajectory=fileContent[1];
   }

  }
  inputFile.close ();
 }

 steps2=steps;
 dt=timeStep;
// FF2=FF;
}

//   for(int i=0; i<fileContent.size(); ++i){
//   }

