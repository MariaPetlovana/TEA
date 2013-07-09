#include "HaffmanTable.h"

HaffmanTable::HaffmanTable(Tree_Node* TNode)
{
    Node=TNode;
}

map<char, vector<bool> > HaffmanTable::BuildTable()
{
    vector<bool> b;
    BuildHaffmanTable(Node, TableMap, b);
    return TableMap;
}
