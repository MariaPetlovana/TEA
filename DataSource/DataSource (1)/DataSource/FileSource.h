#ifndef FILESOURCE_H_INCLUDED
#define FILESOURCE_H_INCLUDED

#include "DataSource.h"

using namespace std;

class FileSource : public DataSource
{
public:
    FileSource (char* NameString);
    ~FileSource ();
    bool HasNext()
    {
        //char ch;
        if(!fi.eof())
        {
            fi.get(ch);
            ++CountByte;
            return 1;
        }
        return 0;
    }
    char ReturnByte()
    {
        if(HasNext()) return ch;
    }

protected:
    ifstream fi;
    virtual vector<uint32_t> ReadSource();
};

#endif // FILESOURCE_H_INCLUDED
