#ifndef VALUETABLE_H_INCLUDED
#define VALUETABLE_H_INCLUDED

#include "Table.h"

class ValueTable: public Table<char, int>
{
    protected:
        string str;
        ifstream f;

        void ReturnValueTable();
    public:
        string ReturnStr();
        ValueTable(char* NameFile);

        virtual map<char, int> BuildTable();
};

#endif // VALUETABLE_H_INCLUDED
