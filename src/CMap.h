#ifndef _CMAP_H
#define _CMAP_H

#include <map>
#include <string>
using namespace std;

template<typename T>
class CMap
{
    public:
        CMap();
        ~CMap();
        int insert(int key, T *data);
        int delete1(int key);
        T *search(int key);
        T *lookup(int key);
        T *min();
        T *max();
        int isempty();
        T *begin();
        T *end();
        int size();
    private:
        map<int, T*> *rbtree;
};

#endif
