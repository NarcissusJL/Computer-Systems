all: test_hash test_dict query_movies
test_hash: hash.h hash.cpp test_hash.cpp
	g++ test_hash.cpp -o test_hash -g
test_dict: hash.h hash.cpp dict.h dict.cpp test_dict.cpp
	g++ test_dict.cpp -o test_dict -g
query_movies: hash.h hash.cpp dict.h dict.cpp movie.h query_movies.cpp
	g++ query_movies.cpp -o query_movies -g
clean:
	rm test_hash test_dict query_movies