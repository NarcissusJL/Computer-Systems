// Unit tests for the MinPriorityQueue
//Huiyang Li and Zuoyu Wang

#include "pq.h"
#include <assert.h>

using namespace std;

int main()
{
    MinPriorityQueue<int> pq;
    int a[] = {96, 83, 27, 38, 11, 9};
    for (int i = 0; i < 6; i++)
    {
        pq.insert(&a[i]);
    }

    cout << pq << endl;

    int *min = pq.minimum();
    assert(*min == 9);
    assert(!pq.empty());
    assert(pq.length() == 6);

    min = pq.extractMin();
    assert(*min == 9);
    assert(pq.length() == 5);

    min = pq.extractMin();
    assert(*min == 11);

    min = pq.extractMin();
    assert(*min == 27);

    min = pq.extractMin();
    assert(*min == 38);

    int v = 81;
    pq.decreaseKey(1, &v);
    min = pq.extractMin();
    assert(*min == 81);

    min = pq.extractMin();
    assert(*min == 83);

    assert(pq.empty());

    cout << pq << endl;

    return 0;
}
