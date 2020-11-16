#include <iostream>
#include <string>

using namespace std;

class Review
{
    public:
        Review();
        Review(string title_, unsigned int rating_);
        virtual ~Review();

        string get_title() const;
        unsigned int get_rating() const;

    private:
        string title;
        unsigned int rating;
};
