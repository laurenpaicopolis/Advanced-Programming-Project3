//
// Created by Lauren Paicopolis on 2/21/20.
//
#include "critic.h"
#include <fstream>
#include <iostream>

/************* critic class ******************/

// Default Constructor
critic::critic() {
    criticName = "";
    stars = 0;
    criticCategory = "";
    review = "";
}

// Constructor
critic::critic(string name, int rating, string category) {
    criticName = name;
    criticCategory = category;
    stars = rating;
}

//Getters
string critic::getReview() {
    return review;
}
string critic::getName() {
    return criticName;
}
string critic::getCategory() {
    return criticCategory;
}
int critic::getStars() {
    return stars;
}

// Setters
void critic::setReview(string criticReview) {
    if (criticReview.empty())
        review = "No critic review written";
    else
        review = criticReview;
}
void critic::setStars(int rating) {
    if (rating < 1 or rating > 4)
        stars = 1;
    else
        stars = rating;
}
void critic::setName(string name) {
    if (name.empty())
        criticName = "Unknown name";
    else
        criticName = name;
}
void critic::setCategory(string category) {
    if (category != "Food" & category != "Movies" & category != "Games" && category != "Music")
        criticCategory = "None";
    else
        criticCategory = category;
}

// Write and rank VTMountain Game
void critic::writeReview() {
    cout << "Please share your critique of the Vermont Mountain Guessing Game!" << endl;
    char criticReview[150];

    int rating;
    cout << endl << "Enter your rating out of 5 stars here: ";
    cin >> rating;

    while (rating <= 0 or rating > 5) {
        cout << "Invalid star rating! Needs to be between 1 and 5 stars!" << endl;
        cout << "Reenter stars here (1-5): ";
        cin >> rating;
    }

    setStars(rating);
    cin.ignore();
    cout << "Enter your review here: ";
    cin.getline(criticReview,150);
    setReview(criticReview);

    // Writes review and stars to file
    ofstream outFile;
    outFile.open("../gamecritics.csv",  ios::app);
    cout << "Thanks for the game review!" << endl;
    setReview(criticReview);
    if (outFile) {
        outFile << criticCategory << " Critic" << endl;
        outFile << "Name: " << criticName << endl;
        outFile << "Stars: " << stars << endl;
        outFile << "Review: " << review << endl;
    }
    else {
        cout << "Something went wrong with writing to a file" << endl;
    }
    outFile.close();
}
