#ifndef _CVIRTUALNODE_H
#define _CVIRTUALNODE_H
#include "CNode.h"
class CVirtualNode
{
public:
    CVirtualNode();
    CVirtualNode(CNode *pNode);
    void setNode(CNode *pNode);
    CNode *getNode();
    void setHash(long pHash);
    long getHash();
private:
    long hash;
    CNode *node;
};

#endif
