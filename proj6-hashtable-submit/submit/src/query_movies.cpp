// The query_movies program to test the dictionary implementation based on hash
// table. The usage is:
// ./query_movies <the movie file>

// Comparision of hash table implementation and bst implementation:
// It takes about 52000 cpu clocks for this program to complete the whole insertion
// on the given movies_mpaa.txt file. And the number if 262000 if it is a bst
// implemention. The conclusion is that the hash table implementation provides
// a better performance. But the performance of a hash table implementation is
// affected by the number of slots. This implementation sets 1000 as the number
// of slots, and it behaves much slower if the number changed to 10.
//Zuoyu Wang & Huiyang Liu
#include "dict.h"
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "USAGE: ./query_movies <the movie file>" << endl;
        return -1;
    }

    Dictionary<Movie> movies(1000);

    ifstream is(argv[1]);
    string line, title;
    clock_t start, end;
    start = clock();
    while (getline(is, line))
    {
        stringstream ss(line);
        string cast;
        getline(ss, title, '\t');
        int end = title.find_last_of('"');
        // Extract the movie title
        title = title.substr(1, end - 1);
        // Extract the remaining string as cast
        getline(ss, cast);
        Movie *m = new Movie(title, cast);
        try
        {
            // Add movie to a dictionary
            movies.insert(m);
        }
        catch (KeyError &ke)
        {
            // Do nothing to ignore duplicate movies
        }
    }
    end = clock();
    cout << "Clocks taken to complete insertion: " << end - start << endl;

    // Start a loop to wait for queries
    while (true)
    {
        cout << "Input the movie title: ";
        getline(cin, title, '\n');
        Movie key(title);

        try
        {
            Movie *m = movies.get(key);
            cout << m->cast << endl;
        }
        catch (KeyError &ke)
        {
            cout << "No results for query" << endl;
        }
    }

    return 0;
}
