#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Review
{
    public:
        Review();
        Review(string title_, unsigned int rating_);
        virtual ~Review();
        //Review& operator=( const Review& b );
       //bool operator<(Review& p1, Review& p2);
        // overloading the < operator enables functions like std::sort to compare objects to order them accordingly

        string get_title() const;
        unsigned int get_rating() const;

    private:
        string title;
        unsigned int rating;
        vector<Review> myvector;
};
