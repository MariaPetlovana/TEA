#ifndef ENCRYPT_H_INCLUDED
#define ENCRYPT_H_INCLUDED

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>

#include "ValueTable.h"

using namespace std;

class Encrypt
{
    public:
        void Encryption(ValueTable* Value, char* NameFileTo);
};


#endif // ENCRYPT_H_INCLUDED
