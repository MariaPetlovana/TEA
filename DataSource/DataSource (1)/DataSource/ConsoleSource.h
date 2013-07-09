#ifndef CONSOLESOURCE_H_INCLUDED
#define CONSOLESOURCE_H_INCLUDED

#include "DataSource.h"

using namespace std;

class ConsoleSource : public DataSource
{
protected:
    virtual vector<uint32_t> ReadSource();
};

#endif // CONSOLESOURCE_H_INCLUDED
