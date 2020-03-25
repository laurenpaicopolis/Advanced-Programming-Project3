//
// Created by Lauren Paicopolis on 2/14/20.
//

#ifndef LP_PROJECR3_SKIERSNOWBOARDER_H
#define LP_PROJECR3_SKIERSNOWBOARDER_H

#include "Player.h"
#include "VTMountain.h"
#include <cstdlib>
#include "vector"

class SkierSnowboarder: public Player {
    // fields
    int easyWayDown;
    int hardWayDown;
    int expensiveLevel;
    int distance;
    int userMountains;
    int totalGuessesDistance;
    int totalGuessesGreens;
    int totalGuessesBlacks;
    int totalGuessesPrice;
    int count = 0;
    int count1 = 0;
    string winterSport = "";
    VTMountain mountaintoFind;
    vector<VTMountain> guessingMountainsPrice;
    vector<VTMountain> guessingMountainsGreen;
    vector<VTMountain> guessingMountainsBlack;
    vector<VTMountain> guessingMountainsDistance;
    vector<int> randomNumbersUsed;

public:
    // Default Constructor
    SkierSnowboarder();

    // Setters
    void setEasyWayDown(int easy);
    void setHardWayDown(int hard);
    void setExpensiveLevel(int expensive);
    void setDistance(int userDistance);
    void setUserMountains(int mountains);
    void setWinterSport(string sport);
    void setVTMountain(VTMountain object);

    // Getters
    int getEasyWayDown();
    int getHardWayDown();
    int getExpensiveLevel();
    int getDistance();
    int getUserMountains();
    string getWinterSport();
    VTMountain getVTMountain();

    // selectMountains
    // Requires: nothing
    // Modifies: guessingMountainsPrice, guessingMountainsBlack, guessingMountainsGreen, guessingMountainsDistance
    // Effects: Selects random number based on user decision on numbers they want to guess, loads the vectors with
    // random mountains generated for user to guess between in game
    void selectMountains();

    // checkRandomNumber
    // Requires: non negative integer
    // Modifies: randomNum
    // Effects: Checks if randomNum has already been used, returns false if used true if not used so that users
    // cannot get the same mountain twice to guess between
    bool checkRandomNumber(int randomNum);

    // generateRandomNumber
    // Requires: nothing
    // Modifies: randomNum
    // Effects: Generates random number between 1 and 15
    int generateRandomNumber();

    // printGuessingMountains
    // Requires: vector of mountain objects
    // Modifies: nothing
    // Effects: prints mountains user can guess between
    void printGuessingMountains(vector<VTMountain> &mountains);

    // printGuessingMountains
    // Requires: nothing
    // Modifies: priceRange, userDistance, userGreens, userBlacks, totalGuessesBlack, totalGuessesGreen, totalGuessesPrice
    // totalGuessesDistance
    // Effects: User can guess which mountain meets their criteria, only have a limited number of guesses
    void guessingGame();

    // validateGuess
    // Requires: userGuess
    // Modifies: guess
    // Effects: Makes sure user guess is between 1 and userMountains
    int validateGuess(int guess);

    // correctGuessPrice
    // Requires: non negative integer
    // Modifies: nothing
    // Effects: Checks if user guess of mountain matches the price range they selected
    void correctGuessPrice(int guess);

    // addPoints
    // Requires: non negative integer anf vector of mountain objects
    // Modifies: points
    // Effects: Adds corresponding point value to user total score based on guesses
    void addPoints(int totalGuesses, vector<VTMountain> &mountains);

    // playAgain
    // Requires: non negative integer
    // Modifies: nothing
    // Effects: Checks if user wants to play again or if they are out of guesses
    void playAgain(int totalGuesses);

    // correctGuessDistance
    // Requires: non negative integer
    // Modifies: nothing
    // Effects: Checks if user guess of mountain matches the distance range they selected
    void correctGuessDistance(int guess);

    // correctGuessGreens
    // Requires: non negative integer
    // Modifies: nothing
    // Effects: Checks if user guess of mountain matches the green trail range they selected
    void correctGreens(int guess);

    // correctGuessBlacks
    // Requires: non negative integer
    // Modifies: nothing
    // Effects: Checks if user guess of mountain matches the black trail range they selected
    void correctBlacks(int guess);
};

#endif //LP_PROJECR3_SKIERSNOWBOARDER_H
