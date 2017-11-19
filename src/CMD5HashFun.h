#ifndef _CMD5HASHFUN_H
#define _CMD5HASHFUN_H
#include "CMD5HashFun.h"
#include "CHashFun.h"

class CMD5HashFun : public CHashFun
{
public:
    virtual long getHashVal(const char * );
};

#endif
