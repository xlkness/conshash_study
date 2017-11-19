#include "CVirtualNode.h"
#include <iostream>
#include <assert.h>

CVirtualNode:: CVirtualNode()
{
    node = NULL;
}

CVirtualNode::CVirtualNode(CNode *pNode)
{
    setNode(pNode);
}

void CVirtualNode::setNode(CNode *pNode)
{
    assert(pNode != NULL);
    node = NULL;
}

CNode *CVirtualNode::getNode()
{
    return node;
}

void CVirtualNode::setHash(long pHash)
{
    hash = pHash;
}

long CVirtualNode::getHash()
{
    return hash;
}
