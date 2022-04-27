#include<time.h>
#include "heap.h"
using namespace std;

clock_t lst;
int get_time()
{
    int tmp = lst;
    lst = clock();
    return lst - tmp;
}

void insert_sort(int A[], int n)
{
    int *B = new int[n];
    for(int i = 0; i < n; i++)
        B[i] = A[i];
    for(int i = 0; i < n; i++)
    {
        int buf = B[i];
        for(int j = i - 1; j >= 0; j--)
        if(B[j] > buf)
            B[j + 1] = B[j];
        else
        {
            B[j + 1] = buf;
            break;
        }
    }
    delete []B;
}

void merge_sort(int A[], int n)
{
    if(n <= 1)
        return;
    int m = n / 2;
    merge_sort(A, m);
    merge_sort(A + m, n - m);
    int *B = new int[n];
    for(int i = 0, j = m, t = 0;;)
    {
        if(i >= m && j >= n)
            break;
        if(i >= m)
            B[t++] = A[j++];
        else if(j >= n)
            B[t++] = A[i++];
        else if(A[i] < A[j])
            B[t++] = A[i++];
        else
            B[t++] = A[j++];
    }
    for(int i = 0; i < n; i++)
        A[i] = B[i];
    delete []B;
}

int main()
{
    srand(time(0));
    double nn = 30;
    for(int t = 0; t < 100; t++)
    {
        int n = (t + 1) * 5000;
        cerr << t << " " << n << endl;
        cout << n << " ";
        int *A = new int[n];
        int *B = new int[n];
        for(int i = 0; i < n; i++)
            A[i] = (rand() << 15) + rand();
        get_time();
        MinHeap<int> heap(A, n);
        heap.heapSort(B);
        cout << get_time() << " ";
        insert_sort(A, n);
        cout << get_time() << " ";
        merge_sort(A, n);
        cout << get_time() << endl;
        delete []A;
        delete []B;
    }
}