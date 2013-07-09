#include "Tree_Node.h"

Tree_Node::Tree_Node(Tree_Node* _left, Tree_Node* _right)
{
    l=_left;
    r=_right;
    digit=_left->digit+_right->digit;
    //symbol(_left->symbol){};
}

Tree_Node::Tree_Node()
{
    //digit=1;
    //symbol=-1;
    l=NULL;
    r=NULL;
}
