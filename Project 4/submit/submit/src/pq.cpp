// pq.cpp

// These 3 constructors just call the corresponding MinHeap constructors.  That's all.

//Zuoyu Wang and Huiyang Li
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue() // : MinHeap<KeyType>()
{
}

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n) : MinHeap<KeyType>(n)
{
}

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType> &pq) : MinHeap<KeyType>(pq)
{
}

template <class KeyType>
KeyType *MinPriorityQueue<KeyType>::minimum() const
{
    if (empty())
        return nullptr;
    return A[0];
}

template <class KeyType>
KeyType *MinPriorityQueue<KeyType>::extractMin()
{
    if (empty())
        return nullptr;
    KeyType *min = minimum();
    swap(0, heapSize - 1);
    heapSize--;
    heapify(0);
    return min;
}

template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType *key)
{
    if (index >= heapSize || !key)
        return;
    A[index] = key;
    heapify(0);
}

template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType *key)
{
    A[heapSize++] = key;
    heapify(0);
}

template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
    return heapSize == 0;
}

template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
{
    return heapSize;
}

template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
    std::stringstream ss;

    if (heapSize == 0)
    {
        ss << "[ ]";
    }
    else
    {
        ss << "[";
        for (int index = 0; index < heapSize - 1; index++)
            ss << *(A[index]) << ", ";
        ss << *(A[heapSize - 1]) << "]";
    }
    return ss.str();
}

template <class KeyType>
std::ostream &operator<<(std::ostream &stream, const MinPriorityQueue<KeyType> &pq)
{
    stream << pq.toString();

    return stream;
}
