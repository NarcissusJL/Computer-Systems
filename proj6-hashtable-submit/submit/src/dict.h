// dict.h
// This Dictionary template inherites from the HashTable template
//Zuoyu Wang & Huiyang Liu
#ifndef DICT_H
#define DICT_H

#include "hash.h"

template <class KeyType>
class Dictionary : public HashTable<KeyType>
{
public:
    Dictionary(int numSlots);
    bool empty() const;                   // return true if empty; false o/w
    KeyType *get(const KeyType &k) const; // return first item with key equal to k
    void insert(KeyType *k);              // insert k into the tree
    void remove(const KeyType &k);        // delete first item with key equal to k

    using HashTable<KeyType>::slots;
    using HashTable<KeyType>::table;
};

#include "dict.cpp"

#endif
