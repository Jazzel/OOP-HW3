#pragma once
#include "truck.hpp"

/**
 * ? @brief BST structure
 * * contains attributes of BST - uses Truck struct
 * * contains public functions
 * * -- intializeNode : initializes empty node with Truck and left and right as NULL
 * * -- insertNode : checks and inserts Nodes in left and right of BST
 */

struct BSTNode
{
    Truck val;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode *intializeNode(Truck);
    BSTNode *insertNode(BSTNode *, Truck);
};
