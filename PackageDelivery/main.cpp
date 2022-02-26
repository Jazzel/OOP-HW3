#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.hpp"
#include <cstring>
#include <fstream>


using namespace std;

BSTNode* root = NULL; // this is the root of BST

// struct Truck
// {
//     string driver;
//     double petrol;
//     string regNo;
//     int fullMileage;
//     int emptyMileage;
// };


// You have to define the functions below
void loadTrucks() {
    fstream newfile;
   newfile.open("input.txt",ios::in);
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){  //read data from file object and put it into string.
         cout << tp << "\n";   //print the data of the string
      }
      newfile.close();   //close the file object.
   } 

}

void makeJourney() {

}

void unloadTrucks() {

}

int main()
{
    loadTrucks();
    makeJourney();
    unloadTrucks();
    return 0;
}
