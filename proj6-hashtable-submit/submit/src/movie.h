// Define the class to represent a movie
//Zuoyu Wang & Huiyang Liu
#include <string>

class Movie
{
public:
    Movie(std::string title)
    {
        this->title = title;
    }

    Movie(std::string title, std::string cast)
    {
        this->title = title;
        this->cast = cast;
    }

    // Implement the operators
    bool operator<(const Movie &obj) const
    {
        return title < obj.title;
    }

    bool operator>(const Movie &obj) const
    {
        return title > obj.title;
    }

    bool operator==(const Movie &obj) const
    {
        return title == obj.title;
    }

    // The hash function
    int hash() const
    {
        int value = 0;
        for (int i = 0; i < title.size(); i++)
            value += title[i] * (i + 1);
        return value;
    }

    std::string title;
    std::string cast;
};

// Overload the << operator
std::ostream &operator<<(std::ostream &stream, const Movie &m)
{
    stream << m.title;
    return stream;
}
