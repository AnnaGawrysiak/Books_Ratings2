/*

Iteracja 4.
Dodaj do powyższego panelu opcję
e) szczęśliwy traf
Czyli wylosuj dla użytkownika książkę do czytania
*/
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
void userChoice(int choice);
//bool operator==(Review const & lhs, Review const & rhs);
//bool operator==(unsigned int other, Review const& r);
//bool operator==(Review const& r, unsigned int other);

int main()
{
     srand(time(NULL));

    vector<Review> books;

	string title;

	unsigned int rating = 0;

    int choice = 0;
    //userChoice(choice);
    cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book ,(6) exit "<< endl;
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

                //userChoice(choice);

                cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                cin >> choice;

                break;
            }

        case 2:
            {
                string mytitle;
                cin.ignore();
                cout<<"Which book would you like to remove? Type in title: ";
                getline(cin, mytitle);
                auto it = find_if(books.begin(), books.end(), [&mytitle](const Review& obj) {return obj.get_title() == mytitle;});

                if (it != books.end())
                    {
                      // found element. it is an iterator to the first matching element.

                      auto index = std::distance(books.begin(), it);
                      books.erase(books.begin() + index);
                    }

                cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                cin >> choice;
                break;
            }

        case 3:
            {
               //b) w kolejnoœci alfabetycznej

                // przy uzyciu wyrazenia lambda:

                std::sort(books.begin(),
                          books.end(),
                          [](const Review & lhs, const Review & rhs)
                          {return lhs.get_title() < rhs.get_title();});

                cout << "Books in alphabetical order: ";

                for(int unsigned i = 0; i < books.size(); i++)
                    {
                        ShowReview(books[i]);
                    }

                cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book , (6) exit "<< endl;
                cin >> choice;

                break;
            }

        case 4:
            {
                //c) w kolejnoœci ocen malejaco

                    std::sort(books.begin(), books.end(),
                    [](const Review & lhs_, const Review & rhs_)
                    {
                        return lhs_.get_rating() > rhs_.get_rating();
                    });

                    cout << "The highest rated books: ";
                    for(int unsigned i = 0; i < books.size(); i++)
                        {
                            ShowReview(books[i]);
                        }

                cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                cin >> choice;
                break;
            }

        case 5:
            {
                int randomIndex = rand() % books.size();
                Review random_book = books.at(randomIndex);
                cout << random_book.get_title() << " " << random_book.get_rating() << endl;
                cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                cin >> choice;
                break;
            }

            default:
                {
                    cout << "wrong entry. " <<
                    endl << "Restarting program.";
                    cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                    cin >> choice;
                    //userChoice(choice); //Calls/restarts the function
                    break;
                }

        }


    } while(choice != 6);

//a) w kolejnosci podanej przez uzytkownika
cout << "You entered the following:\n";
	for(int unsigned i = 0; i < books.size(); i++)
    {
        ShowReview(books[i]);
    }

//d) w kolejnoœci losowej

cout << "Randomly chosen books: " << endl;

random_shuffle(books.begin(), books.end());

for(int unsigned i = 0; i < books.size(); i++)
    {
        ShowReview(books[i]);
    }

	return 0;
}

void ShowReview(const Review & rr)
{
        cout << rr.get_title();
        cout << " ";
        cout << rr.get_rating() << endl;
}

void userChoice(int choice)
{
    cout << "Which do you want to do? (1) add a book title, (2)remove a book title,(3) display in alphabetical order, (4) display in ranking order, (5) pick a randomly chosen book, (6) exit "<< endl;
                cin >> choice;
}

//bool operator==(Review const & lhs, Review const & rhs)
//{

   // return lhs.get_title() == rhs.get_title();
//}

//bool operator==(unsigned int other, Review const& r) { return r.get_serial_number() == other; }
//bool operator==(Review const& r, unsigned int other) { return r.get_serial_number() == other; }
