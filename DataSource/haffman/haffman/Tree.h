#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <map>

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"

using namespace std;

template<typename T, typename D, typename F>
class Tree
{
    protected:
        Tree_Node* Tree_Root;

        struct MySort
        {
            bool operator()(Tree_Node* l, Tree_Node* r) const
            {
                return l->digit<r->digit;
            }
        };

    public:
        Tree();
        Tree(Tree_Node t);
        Tree_Node* GetRoot();
        void CreateTree(list<T> ListTree);
        list<T> BuildNodes(map<D, F> TreeMap);
};

template<typename T, typename D, typename F>
Tree<T, D, F>::Tree()
{
    Tree_Root=NULL;
}

template<typename T, typename D, typename F>
Tree<T, D, F>::Tree(Tree_Node t)
{
    Tree_Root=new Tree_Node(t);
}

template<typename T, typename D, typename F>
Tree_Node* Tree<T, D, F>::GetRoot()
{
    return Tree_Root;
}

template<typename T, typename D, typename F>
void Tree<T, D, F>::CreateTree(list<T> ListTree)
{
    while(ListTree.size()!=1)
    {
        ListTree.sort(MySort());

        Tree_Node* LNode=ListTree.front();
        ListTree.pop_front();
        Tree_Node* RNode=ListTree.front();
        ListTree.pop_front();

        Tree_Node* Parent_Node=new Tree_Node(LNode, RNode);
        ListTree.push_back(Parent_Node);
    }

    Tree_Root=ListTree.front();
}

template<typename T, typename D, typename F>
list<T> Tree<T, D, F>::BuildNodes(map<D, F> TreeMap)
{
    list<T> TreeList;
    //map<D, T>::iterator iter<D, T>;

    for(typename map<D, F>::iterator iter=TreeMap.begin(); iter!=TreeMap.end(); iter++)
    {
        Tree_Node* Node=new Tree_Node();
        Node->symbol=iter->first;
        Node->digit=iter->second;
        TreeList.push_back(Node);
        //delete Node;
    }

    return TreeList;
}

#endif // TREE_H_INCLUDED
