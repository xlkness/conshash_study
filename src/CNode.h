#ifndef _CNODE_H
#define _CNODE_H

class CNode
{
public:
    CNode();
    CNode(const char *pIden, int pVNodeCount,void *pData);
    const char *getIden();
    int getVNodeCount();
    void setData(void *data);
    void *getData();
private:
    void setCNode(const char *pIden, int pVNodeCount, void *pData);
    char iden[100];
    int vNodeCount;
    void *data;
};

#endif
