// ? imports
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>

// ? header files
#include "node.hpp"

// ? namespaces
using namespace std;

// ! -------------- Constants
const string INPUTFILE = "Input.txt";
const string OUTPUTFILE = "Output.txt";

// ! -------------- Global BST
BSTNode *root = NULL;

// ? Updates BSTNode to contains public functions - intializeNode, insertNode

// *********************************************************************************
// *                      Helper functions                                         *
// *********************************************************************************

/**
 * ? @brief intializeNode
 * * initializes the BST top if the BST is NULL
 *
 * ? @param truck
 * * takes parameter truck as Truck structure
 *
 * ! @return BSTNode*
 * * returns BST pointer as memory address
 *
 */
BSTNode *intializeNode(Truck truck)
{
   // * initliazing temp BST
   BSTNode *temp = new BSTNode;
   // * with truck struct as node and left and right as NULL
   temp->val = truck;
   temp->left = NULL;
   temp->right = NULL;
   // * returning temp BST
   return temp;
}

/**
 * ? @brief insertNode
 * * check whether the new Node needs to go left or right
 * * inserts the node in BST ( stored in memory )
 *
 * ? @param root
 * * pointes to BST stored in memory
 *
 * ? @param truck
 * * truck as Truck structure is stored in BST
 *
 * ! @return BSTNode*
 * * returns BST pointer as memory address
 */
BSTNode *insertNode(BSTNode *root, Truck truck)
{
   // * return null if the root is NULL
   if (!root)
   {
      root = intializeNode(truck);
   }
   // * checking if truck is greater than the parent Node
   // * if true inserting that node on right
   else if (truck.regNo >= root->val.regNo)
   {
      root->right = insertNode(root->right, truck);
   }
   // * else inserting the node on left
   else
   {
      root->left = insertNode(root->left, truck);
   }
   // * return main BST address
   return root;
}

/**
 * ? @brief readandWriteBSTNodes
 * * reads Truck from BST and writes truck attributes in the output file
 *
 * ? @param root
 * * root points to BST stored in memory
 *
 * ? @param out
 * * filestream of output file
 *
 *
 * ! returns void
 */
void readandWriteBSTNodes(BSTNode *root, ofstream *out)
{
   // * return null if the root is NULL
   if (!root)
   {
      return;
   }

   // * recusring to left of the BST
   readandWriteBSTNodes(root->left, out);

   // * writing Truck attributes in the output file
   *out << "Driver: " << root->val.driver << endl;
   *out << "Petrol: " << root->val.petrol << endl;
   *out << "Reg No: " << root->val.regNo << endl;
   *out << "Full Mileage: " << root->val.fullMileage << endl;
   *out << "Empty Mileage: " << root->val.emptyMileage << endl
        << endl;

   // * recusring to right of the BST
   readandWriteBSTNodes(root->right, out);
}

/**
 * ? @brief updatePetrol
 * * -- updates petrol attrubute if the fullMileage + emptyMileage lets the truck travel the distance
 * * in the given petrol
 * * -- else leaves no change to truck
 * * function is recursed to perform the operation of all left and rights of BST
 *
 *
 * ? @param root
 * * pointer to BST stored in memory
 *
 *
 * ! returns void
 */
void updatePetrol(BSTNode *root)
{
   // * return null if the root is NULL
   if (!root)
   {
      return;
   }

   // * recusring to left of the BST
   updatePetrol(root->left);

   // * getting required petrol
   double petrolRequired = 60.0 / root->val.fullMileage + 60.0 / root->val.emptyMileage;
   double checkPetrol = root->val.petrol - petrolRequired;

   // * checking if petrol is enough to travel
   if (checkPetrol >= 0)
   {
      root->val.petrol = checkPetrol;
   }
   // * recusring to right of the BST
   updatePetrol(root->right);
}

// *********************************************************************************
// *                      Main functions                                           *
// *********************************************************************************

/**
 * ? @brief load Trucks
 * * loads data from " INPUTFILE " and make it a Truck structure then adds the Truck to BST
 * * INPUTFILE can be changed above
 *
 * * Uses helper function " insertNode " to insert Truck as a Node in BST
 *
 * ! returns void
 */
void loadTrucks()
{
   // * file stream for reading the file
   ifstream file(INPUTFILE);

   // * temp variables to hold the data after reading the file
   string driver, petrol, regNo, fullMileage, emptyMileage;

   // * going till the last line of file
   while (!file.eof())
   {
      // * initializing temp varible values
      getline(file, driver);
      getline(file, petrol);
      getline(file, regNo);
      getline(file, fullMileage);
      getline(file, emptyMileage);

      // * forming a struct with variables
      Truck truck = {driver, stod(petrol), regNo, stoi(fullMileage), stoi(emptyMileage)};
      // * calling insertNode function to insert Truck as a node in BST
      root = insertNode(root, truck);
   }
   // * closing file stream
   file.close();
}

/**
 * ?@brief make Journey
 * * function updates the petrol attribute if the truck has travelled and done it's job
 * * else the truck attributes remains the same
 *
 * * Uses helper function " updatePetrol "
 *
 * ! returns void
 */
void makeJourney()
{
   updatePetrol(root);
}

/**
 * ? @brief unload trucks
 * * reads truck from the BST and add it to file  " OUTPUTFILE " <- can be changed above
 *
 * * Uses helper function " readandWriteBSTNodes " to read the BST and write data into file
 *
 * ! returns void
 */
void unloadTrucks()
{
   // * creating file stream to read the file
   ofstream *out = new ofstream;
   // * opening file "outputFile" to write data
   out->open(OUTPUTFILE);
   // * calling readandWriteBSTNodes helper function to read BST and write data
   readandWriteBSTNodes(root, out);
   // * closing file stream
   out->close();
}

// ! Root Function
/**
 * ? @brief main function
 * * calls all the main functions required to run the program
 *
 * ! @return int
 */
int main()
{
   loadTrucks();
   makeJourney();
   unloadTrucks();
   return 0;
}
