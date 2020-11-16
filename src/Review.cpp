#include <iostream>
#include <string>
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

  unsigned int Review::get_rating() const
  {
      return rating;
  }

 //mutator functions
