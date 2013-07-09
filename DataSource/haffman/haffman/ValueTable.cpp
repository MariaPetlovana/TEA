#include "ValueTable.h"

void ValueTable::ReturnValueTable()
{
    str="";
    char ch;

    while(!f.eof() && f.get(ch))
    {
        ++TableMap[ch];
        str+=ch;
    }
}

string ValueTable::ReturnStr()
{
    return str;
}

ValueTable::ValueTable(char* NameFile)
{
    f.open(NameFile);
}

map<char, int> ValueTable::BuildTable()
{
    ReturnValueTable();
    return TableMap;
}
