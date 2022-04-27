// Implementation of the Dictionary template
//Zuoyu Wang & Huiyang Liu
template <class KeyType>
Dictionary<KeyType>::Dictionary(int numSlots) : HashTable<KeyType>(numSlots)
{
}

template <class KeyType>
bool Dictionary<KeyType>::empty() const
{
    int count = 0;
    for (int i = 0; i < slots; i++)
    {
        count += table[i].length();
    }
    return count == 0;
}

template <class KeyType>
KeyType *Dictionary<KeyType>::get(const KeyType &k) const
{
    return HashTable<KeyType>::get(k);
}

template <class KeyType>
void Dictionary<KeyType>::insert(KeyType *k)
{
    KeyType *key = nullptr;
    try
    {
        key = HashTable<KeyType>::get(*k);
    }
    catch (KeyError &ke)
    {
    }
    if (key)
    {
        throw KeyError();
    }
    HashTable<KeyType>::insert(k);
}

template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType &k)
{
    HashTable<KeyType>::remove(k);
}
