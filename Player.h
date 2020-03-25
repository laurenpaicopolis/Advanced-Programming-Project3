// Created by Lauren Paicopolis on 2/14/20.
//

#ifndef LP_PROJECT3_PLAYER_H
#define LP_PROJECT3_PLAYER_H
#include "vector"
#include <iostream>
#include <iomanip>
using namespace std;

class Player {
protected:
    // fields
    string name;
    int points;
    int highScore;

public:
    // Default Constructor
    Player();

    //Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    string getName();
    int getPoints();
    int getHighscore();

    // Setters
    // Requires: String and non-negative integer input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setName(string Name);
    void setPoints(int points);
    void setHighscore(int score);

    // calculateHighScore
    // Requires: not negative integer and string
    // Modifies: playerName, playerPoints, playerHighscore
    // Effects: Reads highscore.csv and figures out if player has new high score for game, writes player information to
    // file if so
    void calculateHighScore(int score, string playerName, string playerSport);

};

#endif //LP_PROJECT3_PLAYER_H
