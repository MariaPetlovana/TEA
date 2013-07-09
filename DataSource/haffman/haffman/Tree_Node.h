#ifndef TREE_NODE_H_INCLUDED
#define TREE_NODE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

class Tree_Node
{
    public:
        int digit;
        char symbol;
        Tree_Node* l, *r;

        Tree_Node(Tree_Node* _left, Tree_Node* _right);
        Tree_Node();
};

#endif // TREE_NODE_H_INCLUDED
