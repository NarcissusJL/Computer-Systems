// heap.cpp
// written by Zuoyu Wang and Huiyang Li
#include <sstream>

// Implement heap methods here.

template <class KeyType>
MinHeap<KeyType>::MinHeap(int n)
{
    A = new KeyType *[n];
    capacity = n;
    heapSize = 0;
}

template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType initA[], int n)
{
    A = new KeyType *[n];
    for (int i = 0; i < n; i++)
        A[i] = &initA[i];
    heapSize = capacity = n;
    buildHeap();
}
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType> &heap)
{
    copy(heap);
}
template <class KeyType>
MinHeap<KeyType>::~MinHeap()
{
    destroy();
}

template <class KeyType>
MinHeap<KeyType> &MinHeap<KeyType>::operator=(const MinHeap<KeyType> &heap)
{
    copy(heap);
}
template <class KeyType>
void MinHeap<KeyType>::heapify(int index)
{
    if (index >= heapSize)
        return;
    heapify(leftChild(index));
    heapify(rightChild(index));
    heapifyR(index);
}
template <class KeyType>
void MinHeap<KeyType>::heapifyR(int index)
{
    if (index >= heapSize)
        return;

    int lc = leftChild(index), rc = rightChild(index);

    if (lc<heapSize &&*(A[index])> * (A[lc]) && (rc >= heapSize || *(A[lc]) <= *(A[rc])))
    {
        swap(index, lc);
        heapifyR(lc);
        return;
    }
    if (rc<heapSize &&*(A[index])> * (A[rc]) && (*(A[lc]) > *(A[rc])))
    {
        swap(index, rc);
        heapifyR(rc);
        return;
    }
}
template <class KeyType>
void MinHeap<KeyType>::heapifyI(int index)
{
    if (index >= heapSize)
        return;

    while (index < heapSize)
    {
        int lc = leftChild(index), rc = rightChild(index);

        if (lc < heapSize && *(A[index]) < *(A[lc]) && (rc >= heapSize || *(A[lc]) <= *(A[rc])))
        {
            swap(index, lc);
            index = lc;
            continue;
        }
        if (rc < heapSize && *(A[index]) < *(A[rc]) && (*(A[lc]) > *(A[rc])))
        {
            swap(index, rc);
            index = rc;
            continue;
        }
        break;
    }
}

template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2)
{
    KeyType *buf = A[index1];
    A[index1] = A[index2];
    A[index2] = buf;
}

template <class KeyType>
void MinHeap<KeyType>::buildHeap()
{
    heapify(0);
}
template <class KeyType>
void MinHeap<KeyType>::destroy()
{
    if (A != NULL)
        delete[] A;
    heapSize = capacity = 0;
}
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType *sorted[])
{
    int _heapSize = heapSize;
    for (int i = 0; i < _heapSize; i++)
    {
        sorted[i] = A[0];
        swap(0, heapSize - 1);
        heapSize--;
        heapifyR(0);
    }
    heapSize = _heapSize;
    buildHeap();
}

// Use the following toString() for testing purposes.

template <class KeyType>
std::string MinHeap<KeyType>::toString() const
{
    std::stringstream ss;

    if (capacity == 0)
        ss << "[ ]";
    else
    {
        ss << "[";
        if (heapSize > 0)
        {
            for (int index = 0; index < heapSize - 1; index++)
                ss << *(A[index]) << ", ";
            ss << *(A[heapSize - 1]);
        }
        ss << " | ";
        if (capacity > heapSize)
        {
            for (int index = heapSize; index < capacity - 1; index++)
                ss << *(A[index]) << ", ";
            ss << *(A[capacity - 1]);
        }
        ss << "]";
    }
    return ss.str();
}

template <class KeyType>
std::ostream &operator<<(std::ostream &stream, const MinHeap<KeyType> &heap)
{
    return stream << heap.toString();
}
