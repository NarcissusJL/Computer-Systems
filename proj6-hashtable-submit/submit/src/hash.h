// hash.h
// This is the interface of the HashTable template
//Zuoyu Wang & Huiyang Liu
#ifndef HASH_H
#define HASH_H

#include "list.h"
#include <exception>
#include <string>

template <class KeyType>
class HashTable
{
public:
    HashTable(int numSlots);
    HashTable(const HashTable<KeyType> &h);
    ~HashTable();

    // return a pointer to the object in the hash table that contains the desired key
    KeyType *get(const KeyType &k) const;
    // insert a KeyType pointer to the hash table
    void insert(KeyType *k);
    // delete first item with key equal to k
    void remove(const KeyType &k);

    HashTable<KeyType> &operator=(const HashTable<KeyType> &h);

    // return string representation of the items in the given slot
    std::string toString(int slot) const;

protected:
    int slots;
    List<KeyType> *table; // an array of List<KeyType>'s

private:
    void copy(const HashTable<KeyType> &h);
    void destroy();
};

class KeyError : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "KeyError Exception";
    }
};

#include "hash.cpp"

#endif
