// Implementation of HashTable template
//Zuoyu Wang & Huiyang Liu
#include <sstream>

template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
    slots = numSlots;
    table = new List<KeyType>[numSlots];
}

template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType> &h)
{
    copy(h);
}

template <class KeyType>
HashTable<KeyType>::~HashTable()
{
    destroy();
}

template <class KeyType>
KeyType *HashTable<KeyType>::get(const KeyType &k) const
{
    int slot = k.hash() % slots;
    List<KeyType> &l = table[slot];
    for (int i = 0; i < l.length(); i++)
    {
        KeyType *p = l[i];
        if (*p == k)
            return p;
    }
    throw KeyError();
    return nullptr;
}

template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{
    int slot = k->hash() % slots;
    table[slot].append(k);
}

template <class KeyType>
void HashTable<KeyType>::remove(const KeyType &k)
{
    int slot = k.hash() % slots;
    List<KeyType> &l = table[slot];
    int len = l.length();
    l.remove(k);
    if (len == l.length())
        throw KeyError();
}

template <class KeyType>
HashTable<KeyType> &HashTable<KeyType>::operator=(const HashTable<KeyType> &h)
{
    if (this != &h)
    {
        destroy();
        copy(h);
    }
    return *this;
}

template <class KeyType>
std::string HashTable<KeyType>::toString(int slot) const
{
    std::stringstream ss;
    List<KeyType> &l = table[slot];
    if (l.length() == 0)
    {
        ss << "[]";
    }
    else
    {
        ss << "[";
        for (int i = 0; i < l.length() - 1; i++)
            ss << *l[i] << ", ";
        ss << *(l[l.length() - 1]) << "]";
    }
    return ss.str();
}

template <class KeyType>
void HashTable<KeyType>::copy(const HashTable<KeyType> &h)
{
    slots = h.slots;
    table = new List<KeyType>[slots];
    for (int i = 0; i < slots; i++)
        table[i] = h.table[i];
}

template <class KeyType>
void HashTable<KeyType>::destroy()
{
    if (table)
    {
        delete[] table;
        table = nullptr;
    }
}
