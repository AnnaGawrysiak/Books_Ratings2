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
#include "Review.h"

using namespace std;

bool operator<(const Review& r1, const Review& r2);
bool WorseThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

int main()
{
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
                cout << "Type in title of a book: ";
                getline(cin, title);

                cout << "How do you rate this book in scale from 1 to 10? Type in: ";
                cin >> rating;

                books.push_back(Book);
            }

        case 2: cout << "Whatever2";

        case 3: cout << "Whatever3";

        case 4: cout << "Whatever4";

        }

    } while(choice != 5);

	return 0;
}

bool FillReview(Review& rr);
