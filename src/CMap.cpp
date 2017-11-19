#include "CMap.h"
#include <iostream>

using namespace std;

template<typename T>
CMap<T>::CMap()
{
    rbtree = new map<int, T*>();   
}
template<class T>
CMap<T>::~CMap()
{
    //typename map<int, T*>::iterator it;
    //typename map<int, T*>::iterator temp;
    //it = rbtree->begin();
    //while ( it != rbtree->end() ) {
    //    temp = it;
    //    delete it->second;
    //    it++;
    //    rbtree->erase(temp);
    //}
    delete rbtree;
}

template<class T>
int CMap<T>::insert(int key, T *data)
{
    rbtree->insert(pair<int, T*>(key, data));
    return 0;
}
template<class T>
int CMap<T>::delete1(int key)
{
    rbtree->erase(key);
    return 0;
}
template<class T>
T *CMap<T>::search(int key)
{
    typename map<int, T*>::iterator iter;
    iter = rbtree->find(key);
    if ( iter != rbtree->end() ) {
        return iter->second;
    }
    return NULL;
}
template<class T>
T *CMap<T>::lookup(int key)
{
    typename map<int, T*>::iterator it;
    it = rbtree->lower_bound(key);
    if ( it != rbtree->end() )
        return it->second;
    return min();
}
template<class T>
T *CMap<T>::min()
{
    if ( isempty() )
        return NULL;
    return rbtree->begin()->second;
}
template<class T>
T *CMap<T>::max()
{
    if ( isempty() )
        return NULL;
    return rbtree->end()->second;
}
template<class T>
int CMap<T>::isempty()
{
    if ( rbtree->begin() != rbtree->end() )
        return 0;
    else 
        return 1;
}
template<class T>
int CMap<T>::size()
{
    return rbtree->size();
}
#if 0
int main(int argc, char **argv)
{
    CMap<string> a;
    string s1 = "likun";
    string s2 = "cpp";
    string s3 = "chash";
    a.insert(2, &s1);
    a.insert(3, &s2);
    a.insert(4, &s3);
    string *it = a.search(4);
    if ( it ) {
        cout << "find key 4:" << it->c_str() << endl;
    } else {
        cout << " not find key 4!" << endl;
    }

    return 0;
}

#endif
