//
// Created by Lauren Paicopolis on 2/21/20.
//

#ifndef LP_PROJECR3_CRITIC_H
#define LP_PROJECR3_CRITIC_H

#include <iostream>
#include <iomanip>
using namespace std;

class critic {
    // Fields
    string criticName;
    int stars;
    string criticCategory;
    string review;

public:
    // Default Constructor
    critic();
    // Constructor
    // Requires: a string and non negative input for integer
    // Modifies: criticName, criticCategory, and stars
    // Effects: Sets fields to input values
    critic(string name, int rating, string category);

    //Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    string getReview();
    string getName();
    string getCategory();
    int getStars();

    // Setters
    // Requires: String and non-negative integer input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setReview(string criticReview);
    void setName(string name);
    void setCategory(string category);
    void setStars(int rating);

    // writeReview
    // Requires: nothing
    // Modifies: criticCategory, criticName, stars, and reviews
    // Effects: Allows user to become a game critic and critique VTMountain game, entering in review, 5 stars, their name
    // writes above data to gamecritics.csv file
    void writeReview();
};
#endif //LP_PROJECR3_CRITIC_H
