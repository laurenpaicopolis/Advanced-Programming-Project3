//
// Created by Lauren Paicopolis on 2/14/20.
//
#include "SkierSnowboarder.h"
#include "critic.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/******************** Global function prototypes ***********************/

// Requires: nothing
// Modifies: greenTrails, blackTrails, price, distance
// Effects: Prints game instructions and gets user ranking for different criteria
void displayUserInterface();

// Requires: non negative integer and istream object
// Modifies: input
// Effects: Makes sure user ranking is between 1-4 for each category
int userValidation(int input, istream& in);

// Requires: non negative integer istream object
// Modifies: mountainNum
// Effects: Makes sure user total mountains to guess between is between 1-14
int userValidation2(int mountainNum, istream& in);

// Requires: nothing
// Modifies: nothing
// Effects: Sees if user wants to play game again
bool playGameAgain();

// Requires: string
// Modifies: nothing
// Effects: Sees if user wants to become a critic and critique VTMountain Game
void criticTime(string criticName);

/***************** Global function definitions *****************/

int main() {
    displayUserInterface();
    return 0;
}

void displayUserInterface() {
    cout << endl
         << "Welcome to the Mountain Game! You will select your preferences for skiing or snowboarding from a scale of 1-4."
         << endl << endl;
    cout << "These preferences are the number of black trails, number of green trails, the price you are willing to pay"
         << endl <<
         "for a season pass at the mountain, and the distance from UVM you are willing to drive. You will then be given "
         << endl <<
         "the option to select out of 14 possible ski mountains in Vermont how many you are willing to guess between"
         << endl <<
         "based on your preferences above." << endl << endl;

    cout
            << "Your guesses will be on which mountain(s) meet your criteria. So whichever mountain you think is closest to the"
            << endl <<
            "ranking you gave based on the criteria is the one you should choose!" << endl;

    cout << endl
         << "If you guess the correct mountain on the first try, you earn 3 points, on the second try you earn 2 points,"
         << endl <<
         "and every try afterwards you earn one point. " << endl;

    cout << endl
         << "Remember there can be multiple mountains which fit into your criteria or none at all! So choose wisely, as you"
         << endl <<
         "only have a limited number of guesses based on the total number of mountains you have decided to guess between."
         << endl;

    // User wants to keep playing
    bool keepGoing = true;
    while (keepGoing) {
        string name;
        string winterSport;
        int greenTrails;
        int blackTrails;
        int price;
        int travel;
        int mountainsToGuess;

        SkierSnowboarder player1;
        cout << endl << "Please enter your name: ";
        cin >> name;
        player1.setName(name);

        cout << endl << "Do you ski or snowboard? Enter Skier or Snowboarder: ";
        cin >> winterSport;
        while (winterSport != "Skier" & winterSport != "Snowboarder") {
            cout << "Please enter a valid sport (Skier/Snowboarder): ";
            cin >> winterSport;
        }
        player1.setWinterSport(winterSport);

        // Gets user ranking on price
        cout << endl << "Mountain Pricing: " << endl;
        cout << "Less than $300 = 4" << endl;
        cout << "Greater then $300 and less than $400 = 3" << endl;
        cout << "Greater then $400 and less than $439 = 2" << endl;
        cout << "Greater then $439 and less than $500 = 1" << endl << endl;
        cout << "Please enter the price you are willing to pay from 1-4 (1 being most expensive to 4 being least): ";
        cin >> price;
        userValidation(price, cin);
        player1.setExpensiveLevel(price);

        // Gets user ranking on Green Trails
        cout << endl << "Green Trails: " << endl;
        cout << "Less than 10 = 4" << endl;
        cout << "10 or greater and less than 15 = 3" << endl;
        cout << "15 or greater and less than 25 = 2" << endl;
        cout << "25 or greater = 1" << endl << endl;
        cout << "Please enter how many green trails you would like from 1-4 (1 being the most and 4 being the least): ";
        cin >> greenTrails;
        userValidation(greenTrails, cin);
        player1.setEasyWayDown(greenTrails);

        // Gets user ranking on Black Trails
        cout << endl << "Black Trails: " << endl;
        cout << "Less than 10 = 4" << endl;
        cout << "10 or greater and less than 19 = 3" << endl;
        cout << "19 or greater and less than 29 = 2" << endl;
        cout << "29 or greater = 1" << endl << endl;
        cout << "Please enter how many black trails you would like from 1 to 4 (1 being the most and 4 being the least): ";
        cin >> blackTrails;
        userValidation(blackTrails, cin);
        player1.setHardWayDown(blackTrails);

        // Gets user ranking on Distance
        cout << endl << "Distance Trails: " << endl;
        cout << "2 hours and 21 min or greater = 4" << endl;
        cout << "1 hour and 35 min or greater and less than 2 hours and 20 min = 3" << endl;
        cout << "57 min or greater and less than 1 hour and 35 min = 2" << endl;
        cout << "56 min or less = 1" << endl << endl;
        cout << "Please enter the distance you are willing to travel from 1-4 (1 being the least distance to 4 being most): ";
        cin >> travel;
        userValidation(travel, cin);
        player1.setDistance(travel);

        // User selects how many mountains to guess between
        cout << "Please enter the total number of mountains you would like to guess between (4-14): ";
        cin >> mountainsToGuess;
        mountainsToGuess = userValidation2(mountainsToGuess, cin);
        player1.setUserMountains(mountainsToGuess);

        player1.selectMountains();
        player1.guessingGame();

        keepGoing = playGameAgain();

        // Calculate if user has new high score when they are done wanting to play
        if (!keepGoing) {
            cout << endl << "Thanks for playing the Mountain Guessing Game! " << player1.getName() << "'s score was "
                 << player1.getPoints() << " point(s)!" << endl;
                player1.calculateHighScore(player1.getPoints(), player1.getName(), player1.getWinterSport());
                criticTime(player1.getName());
        }
    }
}

// Can become a critic of game
void criticTime(string criticName) {
    string criticAnswer;
    string criticCategory;
    critic userCritic;

    cout << endl << "If you are either a Food, Movies, Game, or Music critic and would like to critique"
    << endl << "the Vermont Mountain Game, please enter 'yes', otherwise click any key to end!" << endl;
    cout << "Enter here (yes or any key to end): ";
    cin >> criticAnswer;

    if (criticAnswer == "yes") {
        cout << endl << "Please enter in category (Food, Music, Movies, or Games): ";
        cin >> criticCategory;
        while (criticCategory != "Food" & criticCategory != "Movies" & criticCategory != "Games" &&
               criticCategory != "Music") {
            cout << "Please enter in valid critic category listed above: ";
            cin >> criticCategory;
        }

        userCritic.setCategory(criticCategory);
        userCritic.setName(criticName);
        userCritic.writeReview();
    }
}

// Validates user ranking (1-4)
    int userValidation(int input, istream &in) {
        // input is not an integer
        while (!cin) {
            cout << "Invalid input, please enter a number: ";
            cin.clear();
            cin.ignore();
            cin >> input;

            while (input > 4 or input < 1) {
                cout << "Please enter a number between 1 and 4: ";
                cin.clear();
                cin.ignore();
                cin >> input;
            }
        }

        while (input > 4 or input < 1) {
            cout << "Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore();
            cin >> input;

            while (!cin) {
                cout << "Invalid input, please enter a number: ";
                cin.clear();
                cin.ignore();
                cin >> input;
            }

        }
        return input;
    }

// Validates user mountains to guess between (1-14)
int userValidation2(int mountainNum, istream &in) {
    // mountainNum is not an integer
    while (!cin) {
        cout << "Invalid input, please enter a number between 4 and 14: ";
        cin.clear();
        cin.ignore();
        cin >> mountainNum;

        // mountainNum is too big or too small
        while (mountainNum > 14 or mountainNum <= 3) {
            cout << "Invalid input for mountain chosen, please enter a number between 4 and 14: ";
            cin.clear();
            cin.ignore();
            cin >> mountainNum;
        }
    }

    // mountainNum is too big or too small
    while (mountainNum > 14 or mountainNum <= 3) {
        cout << "Invalid input for mountain chosen, please enter a number between 4 and 14: ";
        cin.clear();
        cin.ignore();
        cin >> mountainNum;

        // mountainNum is not an integer
        while (!cin) {
            cout << "Invalid input, please enter a number between 4 and 14: ";
            cin.clear();
            cin.ignore();
            cin >> mountainNum;
        }
    }
    return mountainNum;
}

// Play game again
bool playGameAgain() {
    string userPlayAgain;
    bool keepPlaying = false;
    cout
            << "If you would like to play Mountain Guesser again, enter 'y' or 'Y', otherwise enter any letter to end: ";
    cin >> userPlayAgain;

    while (!cin) {
        cout << "Invalid input, please enter either 'y' or 'Y' to play again, or any letter to end: ";
        cin.clear();
        cin.ignore();
        cin >> userPlayAgain;
    }

    if (userPlayAgain == "y" or userPlayAgain == "Y") {
        keepPlaying = true;
    }
    return keepPlaying;
}




