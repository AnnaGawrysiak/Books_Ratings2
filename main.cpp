//Iteracja 1:
//Program ma za zadanie poprosiæ u¿ytkownika o podanie tytu³ów ksi¹¿ek i ich oceny (za³ó¿my skalê 0-10).
//Tak zebrane dane ma wyœwietliæ:
//a) w kolejnoœci podanej przez u¿ytkownika
//b) w kolejnoœci alfabetycznej
//c) w kolejnoœci ocen malej¹co
//d) w kolejnoœci losowej
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Review.h"

using namespace std;
bool WorseThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);
bool compare_by_title(const Review& lhs, const Review& rhs) {
    return lhs.get_title() < rhs.get_title();
}

int main()
{
    srand( time( NULL ) );

    vector<Review> books;

	string title;

	unsigned int rating;

    int choice;
    cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) exit "<< endl;
    cin >> choice;

    do
    {
        switch(choice)
        {
        case 1:
            {
                cin.ignore();

                cout << "Type in title of a book: ";
                getline(cin, title);

                cout << "How do you rate this book in scale from 1 to 10? Type in: ";
                cin >> rating;

                Review Book (title, rating);

                books.push_back(Book);
                break;
            }

        case 2:
            {
                cout << "Whatever2";
                break;
            }

        case 3:
            {
                cout << "Whatever2";
                break;
            }

        case 4:
            {
                cout << "Whatever2";
                break;
            }

        }

    cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) exit "<< endl;
    cin >> choice;


    } while(choice != 5);

//a) w kolejnoœci podanej przez u¿ytkownika
cout << "You entered the following:\n";
	for(int unsigned i = 0; i < books.size(); i++) //dla wyświetlenia zawartości vectora używaj unsigned int
    {
        cout << books[i].get_title();
        cout << " ";
        cout << books[i].get_rating() << endl;
    }

//b) w kolejnoœci alfabetycznej

//std::sort(books.begin(), books.end(), compare_by_title);//sort the vector
// przy uzyciu wyrazenia lambda:

std::sort(books.begin(), books.end(),
[](const Review & lhs, const Review & rhs)
{
    return lhs.get_title() < rhs.get_title();
});

cout << "Books in alphabetical order: ";
	for(int unsigned i = 0; i < books.size(); i++) //dla wyświetlenia zawartości vectora używaj unsigned int
    {
        cout << books[i].get_title();
        cout << " ";
        cout << books[i].get_rating() << endl;
    }

//c) w kolejnoœci ocen malejaco

std::sort(books.begin(), books.end(),
[](const Review & lhs_, const Review & rhs_)
{
    return lhs_.get_rating() > rhs_.get_rating();
});

cout << "The highest rated books: ";
	for(int unsigned i = 0; i < books.size(); i++) //dla wyświetlenia zawartości vectora używaj unsigned int
    {
        cout << books[i].get_title();
        cout << " ";
        cout << books[i].get_rating() << endl;
    }

//d) w kolejnoœci losowej

cout << "Randomly chosen books: " << endl;

random_shuffle(books.begin(), books.end());

for(int unsigned i = 0; i < books.size(); i++) //dla wyświetlenia zawartości vectora używaj unsigned int
    {
        cout << books[i].get_title();
        cout << books[i].get_rating() << endl;
    }

	return 0;
}
