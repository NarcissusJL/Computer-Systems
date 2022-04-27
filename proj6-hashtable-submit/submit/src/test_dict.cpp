// Unit tests for the Dictionary template
//Zuoyu Wang & Huiyang Liu
#include "dict.h"
#include "movie.h"
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Dictionary<Movie> dict(3);
    vector<string> v = {"A Woman Named Jackie",
                        "Favorite Son",
                        "American Masters",
                        "American Playhouse",
                        "Caraibi"};
    Movie *movies[v.size()];

    // test empty()
    assert(dict.empty());

    // test insert()
    for (int i = 0; i < v.size(); i++)
    {
        movies[i] = new Movie(v.at(i));
        dict.insert(movies[i]);
    }
    assert(!dict.empty());

    // test duplicate insertion
    try
    {
        dict.insert(new Movie("Caraibi"));
    }
    catch (KeyError &ke)
    {
        cout << ke.what() << endl;
    }

    // test get()
    Movie q("American Masters");
    assert(dict.get(q) == movies[2]);

    // test remove()
    q.title = "Favorite Son";
    dict.remove(q);
    try
    {
        dict.get(q);
    }
    catch (KeyError &ke)
    {
        cout << ke.what() << endl;
    }

    return 0;
}
