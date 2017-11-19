#include "CNode.h"
#include <string.h>
#include <assert.h>

CNode::CNode()
{
    vNodeCount = 0;
}
CNode::CNode(const char *pIden, int pVNodeCount, void *pData)
{
    setCNode(pIden, pVNodeCount, pData);
}
void CNode::setCNode(const char *pIden, int pVNodeCount, void *pData)
{
    assert(pIden != NULL && pVNodeCount > 0);
    strcpy(iden, pIden);
    vNodeCount = pVNodeCount;
    data = pData;
}
const char *CNode::getIden()
{
    return iden;
}
int CNode::getVNodeCount()
{
    return vNodeCount;
}
void CNode::setData(void *pData)
{
    this->data = pData;
}
void *CNode::getData()
{
    return this->data;
}
