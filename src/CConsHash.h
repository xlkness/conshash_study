#ifndef _CCONSHASH
#define _CONNSHASH

#include "CHashFun.h"
#include "CNode.h"
#include "CVirtualNode.h"
#include "CMap.h"

class CConsHash
{
public:
    CConsHash(CHashFun *pFunc);
    void setFunc(CHashFun *pFunc);
    int addNode(CNode *pNode);
    int delNode(CNode *pNode);
    CNode *lookupNode(const char *object);
    int getVNode();
private:
    CHashFun *func;
    int vNodes;
    CMap<CVirtualNode> *rbtree;
};

#endif
