#ifndef HAFFMANTABLE_H_INCLUDED
#define HAFFMANTABLE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"

using namespace std;

class HaffmanTable: public Table<char, vector<bool> >
{
    protected:
        Tree_Node* Node;

        friend void BuildHaffmanTable(Tree_Node* N, map<char, vector<bool> > &HaffmanTableMap, vector<bool> &b);

    public:
        HaffmanTable(Tree_Node* TNode);
        virtual map<char, vector<bool> > BuildTable();
};

void BuildHaffmanTable(Tree_Node* Tree_Root, map<char, vector<bool> > &MapTable, vector<bool> &b)
{
    if(Tree_Root->l!=NULL)
    {
        b.push_back(0);
        //cout<<0<<endl;
        BuildHaffmanTable(Tree_Root->l, MapTable, b);
    }

    if(Tree_Root->r!=NULL)
    {
        b.push_back(1);
        //cout<<1<<endl;
        BuildHaffmanTable(Tree_Root->r, MapTable, b);
    }

    if(Tree_Root->symbol) MapTable[Tree_Root->symbol]=b;

    b.pop_back();
}

#endif // HAFFMANTABLE_H_INCLUDED
