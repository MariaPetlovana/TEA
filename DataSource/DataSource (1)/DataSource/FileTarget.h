#ifndef FILETARGET_H_INCLUDED
#define FILETARGET_H_INCLUDED

#include "DataTarget.h"

using namespace std;

class FileTarget : public DataTarget
{
public:
    FileTarget (char* NameString);
    ~FileTarget ();

protected:
    ofstream fo;
    virtual void PutTarget (vector<uint32_t> v);
};

#endif // FILETARGET_H_INCLUDED
