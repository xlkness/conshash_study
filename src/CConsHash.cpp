#include <iostream>
#include <string>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "CConsHash.h"
#include "CMap.cpp"

CConsHash::CConsHash(CHashFun *pFunc)
{
    assert(pFunc != NULL);
    this->func = pFunc;
    this->vNodes = 0;
    rbtree = new CMap<CVirtualNode>();
}
int CConsHash::addNode(CNode *pNode)
{
    if ( pNode == NULL ) return -1;
    int vCount = pNode->getVNodeCount();
    if ( vCount <= 0 ) return -1;
    CVirtualNode *virtualNode;
    char str[1000];
    char num[10];
    strcpy(str, pNode->getIden());
    long hash = 0;
	cout << " add node : " << str << endl;
    for ( int i = 0; i < vCount; i++ ) {
        virtualNode = new CVirtualNode(pNode);
        sprintf(num, "%d", i);
        strcat(str, num);
        hash = func->getHashVal(str);
        virtualNode->setHash(hash);
		cout << "\t vnode hash " << i << ":" << hash << endl;
        if ( !rbtree->search(hash) ) {
            rbtree->insert(hash, virtualNode);
            this->vNodes++;
        }
    }
    return 0;
}
int CConsHash::delNode(CNode *pNode)
{
    if ( pNode == NULL ) return -1;
    char str[1000];
    char num[10];
    strcpy(str, pNode->getIden());
    int vCount = pNode->getVNodeCount();
    long hash = 0;
    CVirtualNode *node = NULL;
    for ( int i = 0; i < vCount; i++ ) {
        sprintf(num, "%d", i);
        strcat(str, num);
        hash = func->getHashVal(str);
        CVirtualNode *node = rbtree->search(hash);
        if ( node != NULL ) {
            if ( node->getNode() == pNode && node->getHash() == hash ) {
                this->vNodes--;
                rbtree->delete1(hash);
                delete node;
            }
        }
    }
}
CNode *CConsHash::lookupNode(const char *object) 
{
    if ( object == NULL || this->vNodes == 0 ) return NULL;
    int key = this->func->getHashVal(object);
    CVirtualNode *node = rbtree->lookup(key);
    if ( node != NULL ) {
		cout << "lookup " << key << " ret:" << node->getNode() << endl;
        return (node->getNode());
	}
	cout << "lookup " << key << " ret:" << "null" << endl;
    return NULL;
}
int CConsHash::getVNode()
{
    return this->vNodes;
}
