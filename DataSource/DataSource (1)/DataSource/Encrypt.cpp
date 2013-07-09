#include "Encrypt.h"

void Encrypt::engine (DataSource* MyDataSource, DataTarget* MyTarget, uint32_t* pswd, const bool CryptMode)
{
    vector<uint32_t> MyVector = MyDataSource->GetData();
    vector<uint32_t> result;

    for(int j = 0; j < MyVector.size(); )
    {
        vec[0] = MyVector[j];
        ++j;

        if(j >= MyVector.size())
        {
            vec[1] = vec[0];
            vec[0] = 0;
            ++j;
        }
        else
        {
            vec[1] = MyVector[j];
            ++j;
        }

        if(!CryptMode) sum = 0;
        else sum = 0xC6EF3720;


        for(int i = 0; i < 4; i++)
        {
            key[i] = pswd[i];
        }

        for(i=0; i<32; i++)
        {
            if(!CryptMode) sum+=delta;
            vec[CryptMode] += (1-2*CryptMode) * (((vec[1-CryptMode]<<4) + key[CryptMode*2]) ^ (vec[1-CryptMode] + sum) ^ ((vec[1-CryptMode]>>5) + key[CryptMode*2+1]));
            vec[1-CryptMode] += (1-2*CryptMode) * (((vec[CryptMode]<<4) + key[(1-CryptMode)*2]) ^ (vec[CryptMode] + sum) ^ ((vec[CryptMode]>>5) + key[(1-CryptMode)*2+1]));
            if(CryptMode) sum-=delta;
        }

        result.push_back(vec[0]);
        result.push_back(vec[1]);
    }

    MyTarget->PutData(result);

    return;
}
