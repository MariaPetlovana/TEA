#include "Encrypt.h"

#include "Tree_Node.h"
#include "Tree.h"
#include "Table.h"
#include "ValueTable.h"
#include "HaffmanTable.h"
#include <vector>
//#include "Encrypt.h"

void Encrypt::Encryption(ValueTable* Value, char* NameFileTo)
{
    int cou=0;
    char buf=0;

    ofstream fo(NameFileTo);

    string str=Value->ReturnStr();
    Tree<Tree_Node*, char, int> MyTree;

    MyTree.CreateTree(MyTree.BuildNodes(Value->BuildTable()));
    HaffmanTable MyHaf(MyTree.GetRoot());

    map<char, vector<bool> > HafTable = MyHaf.BuildTable();

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

