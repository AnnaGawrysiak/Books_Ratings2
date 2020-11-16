#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "Review.h"

Review::Review()
{
    //ctor
}

Review::Review(string title_, unsigned int rating_)
{
    title = title_;
    rating = rating_;
}

Review::~Review()
{
    //dtor
}

//accessor functions
 string Review::get_title() const
 {
     return title;
 }

 //bool operator<(Review& p1, Review& p2)
   // {
    //    return p1.get_title() < p2.get_title(); // order by title
   // }

  unsigned int Review::get_rating() const
  {
      return rating;
  }

 //mutator functions
