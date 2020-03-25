//
// Created by Lauren Paicopolis on 2/14/20.
//

#include "Player.h"
#include <fstream>
#include <iostream>

/************* Player class ******************/

// Constructor
Player::Player() {
    name = "";
    points = 0;
    highScore = 0;
}

// Setters
void Player::setName(string playerName) {
    name = playerName;
}
void Player::setPoints(int userPoints) {
    if (userPoints < 0)
        points = 0;
    else
        points = userPoints;
}
void Player::setHighscore(int score) {
    if (score < 0)
        highScore = 0;
    else
        highScore = score;
}

// Getters
string Player::getName() {
    return name;
}
int Player::getHighscore() {
    return highScore;
}
int Player::getPoints() {
    return points;
}

// Calculates high score
void Player::calculateHighScore(int score, string playerName, string playerSport) {
    if (score < 0) {
        score = 0;
    }

    if (playerName.empty()) {
        playerName = "Unknown Player";
    }

    ifstream highscoreFile;
    int savedHighscore = 0;
    string oldName = "";
    string sport = "";
    string sport2 = "";

    // Read high score.csv and load in previous high scores
    highscoreFile.open("../highscore.csv");

    while (highscoreFile && highscoreFile.peek() != EOF) {
        char comma = ',';
        int pastHighscore;

        getline(highscoreFile, sport, ',');
        getline(highscoreFile, oldName, ',');

        highscoreFile >> pastHighscore;
        if (sport != "\n")
            sport2 = sport;
        if (!highscoreFile) {
            // The file is not in a good state
            // There was not a float for highscoreFile
            pastHighscore = 0;
            highscoreFile.clear();
        }

        if (savedHighscore <= pastHighscore) {
            savedHighscore = pastHighscore;
        }
        highscoreFile >> comma;
    }
    highscoreFile.close();

    // Write to file if player has new high score
    ofstream outputFile;
    outputFile.open("../highscore.csv");
    if (score >= savedHighscore) {
        cout << endl << "The original high score was " << sport2 << " " << oldName << " with " << savedHighscore
             << " points" << endl;
        setHighscore(score);
        setName(playerName);
        cout << "Congrats " << playerSport << " " << playerName << " you have the new high score of " << score
             << " point(s)!" << endl;
        outputFile << playerSport << "," << playerName << "," << score << "," << endl;
        outputFile.close();
    }
    outputFile.close();
}


