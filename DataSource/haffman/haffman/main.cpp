#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <list>
#include <vector>
#include <string>

using namespace std;

map<char, int> m;
vector<bool> b;
map<char, vector<bool> > HaffmanTable1;

ifstream f;
ofstream fo;

#include "Tree_Node.h"

/*
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include "Encrypt.h"
*/
/*
class Tree_Node
{
    public:
        int digit;
        char symbol;
        Tree_Node* l, *r;
        /*Tree_Node(Tree_Node* Node)
        {
            this=new Tree_Node;
            digit=Node->digit;
            symbol=Node->symbol;

        }
        Tree_Node(Tree_Node* _left, Tree_Node* _right)
        {
            l=_left;
            r=_right;
            digit=_left->digit+_right->digit;
            //symbol(_left->symbol){};
        }
        Tree_Node()
        {
            //digit=1;
            //symbol=-1;
            l=NULL;
            r=NULL;
        }
};

template<typename T, typename D, typename F>
class Tree
{
    protected:
        Tree_Node* Tree_Root;
        //string str;

        struct MySort
        {
            bool operator()(Tree_Node* l, Tree_Node* r) const
            {
                return l->digit<r->digit;
            }
        };

    public:
        Tree()
        {
            Tree_Root=NULL;
        }
        Tree(Tree_Node t)
        {
            Tree_Root=new Tree_Node(t);
        }
        Tree_Node* GetRoot()
        {
            return Tree_Root;
        }
        void CreateTree(list<T> ListTree)
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
        list<T> BuildNodes(map<D, F> TreeMap)
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
};

template<typename T, typename D>
class Table
{
    protected:
        map<T, D> TableMap;
        //string str;
    public:
        virtual map<T, D> BuildTable() = 0;
};

//template<typename T, typename D>
class ValueTable: public Table<char, int>
{
    protected:
        string str;
        ifstream f;

        void ReturnValueTable()
        {
            str="";
            char ch;

            while(!f.eof() && f.get(ch))
            {
                ++TableMap[ch];
                str+=ch;
            }
        }
    public:
        string ReturnStr()
        {
            return str;
        }
        ValueTable(char* NameFile)
        {
            f.open(NameFile);
        }

        virtual map<char, int> BuildTable()
        {
            ReturnValueTable();
            return TableMap;
        }
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


//template<typename T, typename D>
class HaffmanTable: public Table<char, vector<bool> >
{
    protected:
        Tree_Node* Node;

        friend void BuildHaffmanTable(Tree_Node* N, map<char, vector<bool> > &HaffmanTableMap, vector<bool> &b);

    public:
        HaffmanTable(Tree_Node* TNode)
        {
            Node=TNode;
        }
        virtual map<char, vector<bool> > BuildTable()
        {
            vector<bool> b;
            BuildHaffmanTable(Node, TableMap, b);
            return TableMap;
        }
};

class Encrypt
{
    public:
        void Encryption(ValueTable* Value, char* NameFileTo)
        {
            int cou=0;
            char buf=0;

            ofstream fo(NameFileTo);

            string str=Value->ReturnStr();
            Tree<Tree_Node*, char, int> MyTree;

            MyTree.CreateTree(MyTree.BuildNodes(Value->BuildTable));
            HaffmanTable MyHaf(MyTree.GetRoot());

            map<char, int> HafTable = MyTable->BuildTable();

            for(int i=0; i<str.length(); i++)
            {
                //char ch=str[i];
                vector<bool> v=HafTable[str[i]];
                for(int j=0; j<v.size(); j++)
                {
                    //cout<<v[j];
                    buf=buf | v[j]<<(7-cou);
                    cou++;
                    if(cou==8)
                    {
                        cou=0;
                        fo<<buf;
                        buf=0;
                    }
                }
        //if(cou)
        //{
          //  cou=0;
          //  fo<<buf;
          //  buf=0;
        //}
        //fo<<v[j];
    }
    if(cou)
    {
        cou=0;
        fo<<buf;
        buf=0;
    }
        }
};
*/
struct MySort
{
    bool operator()(Tree_Node* l, Tree_Node* r) const
    {
        return l->digit<r->digit;
    }
};

/*
int MySort(Tree_Node* a, Tree_Node* b)
{
    return a->digit<b->digit;
}*/

void BuildTable(Tree_Node* Tree_Root)
{
    if(Tree_Root->l!=NULL)
    {
        b.push_back(0);
        cout<<0<<endl;
        BuildTable(Tree_Root->l);
    }

    if(Tree_Root->r!=NULL)
    {
        b.push_back(1);
        cout<<1<<endl;
        BuildTable(Tree_Root->r);
    }

    if(Tree_Root->symbol) HaffmanTable1[Tree_Root->symbol]=b;

    b.pop_back();
}

int main()
{
    f.open("test.txt");
    fo.open("result.txt");
    string str="";
    char ch;
    while(!f.eof() && f.get(ch))
    {
        ++m[ch];
        str+=ch;
    }
    for(map<char, int>::iterator iter=m.begin(); iter!=m.end(); iter++)
    cout<<(*iter).first<<" "<<(*iter).second<<endl;

    list<Tree_Node*> My_List;

    for(map<char, int>::iterator iter=m.begin(); iter!=m.end(); iter++)
    {
        Tree_Node* Node=new Tree_Node();
        Node->symbol=iter->first;
        Node->digit=iter->second;
        My_List.push_back(Node);
        //delete Node;
    }

    while(My_List.size()!=1)
    {
        My_List.sort(MySort());

        Tree_Node* LNode=My_List.front();
        My_List.pop_front();
        Tree_Node* RNode=My_List.front();
        My_List.pop_front();

        Tree_Node* Parent_Node=new Tree_Node(LNode, RNode);
        My_List.push_back(Parent_Node);
    }

    Tree_Node* root=My_List.front();
    BuildTable(root);

    cout<<endl<<endl<<endl;
    for(map<char, vector<bool> >::iterator iter=HaffmanTable1.begin(); iter!=HaffmanTable1.end(); iter++)
    {
        cout<<(*iter).first<<" ";
        for(int i=0; i<(iter->second).size(); i++)
        cout<<(*iter).second[i];
        cout<<endl;
    }

    cout<<str<<endl;

    int cou=0;
    char buf=0;

    for(int i=0; i<str.length(); i++)
    {
        //char ch=str[i];
        vector<bool> v=HaffmanTable1[str[i]];
        for(int j=0; j<v.size(); j++)
        {
            //cout<<v[j];
            buf=buf | v[j]<<(7-cou);
            cou++;
            if(cou==8)
            {
                cou=0;
                fo<<buf;
                buf=0;
            }
        }
        //if(cou)
        //{
          //  cou=0;
          //  fo<<buf;
          //  buf=0;
        //}
        //fo<<v[j];
    }
    if(cou)
    {
        cou=0;
        fo<<buf;
        buf=0;
    }
        //fo<<v[j];

    //if(cou) fo<<buf;

//dearchivator

    ifstream fo2("result.txt");
    Tree_Node* root_tree=root;
    cou=0;
    fo2.get(buf);
    while(!fo2.eof())
    {
        bool b = buf & (1<<(7-cou));
        if(b) root_tree=root_tree->r;
        else root_tree=root_tree->l;

        if(root_tree->l==NULL && root_tree->r==NULL)
        {
            //fo<<root_tree->symbol;
            cout<<root_tree->symbol;
            root_tree=root;
        }
        ++cou;
        if(cou==8)
        {
            cou=0;
            fo2.get(buf);
        }
    }

    f.close();
    fo.close();
    fo2.close();
    cout << "Hello world!" << endl;
    return 0;
}

