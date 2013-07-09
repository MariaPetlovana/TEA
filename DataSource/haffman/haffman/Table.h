#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

template<typename T, typename D>
class Table
{
    protected:
        map<T, D> TableMap;
        //string str;
    public:
        virtual map<T, D> BuildTable() = 0;
};

#endif // TABLE_H_INCLUDED
