#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector> 
#include "readOpt.h"

using namespace std; 		// cout instead of std::cout
using namespace readOptName;

void readOptClass::getOpt(){
/* reads the options file */
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
    istringstream(fileContent[1]) >> steps;	// converts string to integer
   }
   if((fileContent[0]=="save")&&(fileContent[1]=="frequency:")){
    istringstream(fileContent[2]) >> saveFrq;	// converts string to integer
   }
   if(fileContent[0]=="initial:"){
    initXYZ=fileContent[1];
   }
   if((fileContent[0]=="time")&&(fileContent[1]=="step:")){
    istringstream(fileContent[2]) >> dt;
   }
   if((fileContent[0]=="force")&&(fileContent[1]=="field:")){
    fileFF=fileContent[2];
   }
   if((fileContent[0]=="box")&&(fileContent[1]=="size:")){
    {istringstream(fileContent[2])>>box[0];}
    {istringstream(fileContent[3])>>box[1];}
    {istringstream(fileContent[4])>>box[2];}
   }
   if(fileContent[0]=="trajectory:"){
    trajFile=fileContent[1];
   }
  }
  inputFile.close ();
 }
}



//   for(int i=0; i<fileContent.size(); ++i){
//   }

