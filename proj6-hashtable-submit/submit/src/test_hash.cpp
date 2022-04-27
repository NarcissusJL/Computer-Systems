// Unit tests for the HashTable template
//Zuoyu Wang & Huiyang Liu
#include "hash.h"
#include "movie.h"
#include <assert.h>
#include <iostream>

using namespace std;

int main()
{
    Movie *m = new Movie("A Woman Named Jackie");
    Movie *m2 = new Movie("Favorite Son");
    HashTable<Movie> h(1);

    // test insert()
    h.insert(m);
    h.insert(m2);
    cout << h.toString(0) << endl;

    // test get()
    Movie q("A Woman Named Jackie");
    Movie *r = h.get(q);
    assert(r == m);

    // test copy constructor
    HashTable<Movie> h2 = h;
    cout << h2.toString(0) << endl;

    // test assignment operator
    HashTable<Movie> *h3 = new HashTable<Movie>(1);
    h3->insert(m);
    h2 = *h3;
    cout << h2.toString(0) << endl;

    // test ~HashTable()
    delete h3;

    // test remove()
    h.remove(q);
    cout << h.toString(0) << endl;

    return 0;
}
