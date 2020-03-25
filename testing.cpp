//
// Created by Lauren Paicopolis on 2/21/20.
//

#include "SkierSnowboarder.h"
#include "VTMountain.h"
#include "Player.h"
#include "critic.h"
#include <iostream>
#include <string>
using namespace std;

// Test Helpers
void testHelper1();
void testHelper2();
void testHelper3();
void testHelper4();

int main() {
    testHelper1();
    testHelper2();
    testHelper3();
    testHelper4();
    return 0;
}

// Tests Player Class
void testHelper1(){
    Player playertest;
    playertest.setHighscore(-1);
    if (playertest.getHighscore() != 0)
        cout << "Test case failed! Was expecting high score to be 0, instead got " << playertest.getHighscore();
    playertest.setPoints(-1);
    if (playertest.getPoints() != 0)
        cout << "Test case failed! Was expecting points to be 0, instead got " << playertest.getPoints();
    playertest.calculateHighScore(-1, "", "Skier");
    if (playertest.getHighscore() == -1)
        cout << "Test case failed! Was expecting high score to be 0, instead got " << playertest.getHighscore() << endl;
    if (playertest.getName() != "Unknown Player")
        cout << "Test case failed! Was expecting Unknown Player and got " << playertest.getName();
    cout << endl << "Passed test cases above, did not crash Player Class" << endl;
}

// Tests SkierSnowboarder Class
void testHelper2() {
    SkierSnowboarder tester;
    tester.setEasyWayDown(0);
    if (tester.getEasyWayDown() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getEasyWayDown() << endl;
    tester.setEasyWayDown(5);
    if (tester.getEasyWayDown() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getEasyWayDown() << endl;
    tester.setHardWayDown(0);
    if (tester.getHardWayDown() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getHardWayDown() << endl;
    tester.setHardWayDown(5);
    if (tester.getHardWayDown() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getHardWayDown() << endl;
    tester.setDistance(0);
    if (tester.getDistance() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getDistance() << endl;
    tester.setDistance(5);
    if (tester.getDistance() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getDistance() << endl;
    tester.setExpensiveLevel(0);
    if (tester.getExpensiveLevel() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getExpensiveLevel() << endl;
    tester.setExpensiveLevel(5);
    if (tester.getExpensiveLevel() != 1)
        cout << "Test case failed! Was expecting 1 and got " << tester.getExpensiveLevel() << endl;
    tester.setUserMountains(0);
    if (tester.getUserMountains() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getUserMountains() << endl;
    tester.setUserMountains(16);
    if (tester.getUserMountains() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getUserMountains() << endl;
    if (tester.checkRandomNumber(-1))
        cout << "Test case failed! Was expecting false and got true after passing in -1" << endl;
    if (tester.checkRandomNumber(15))
        cout << "Test case failed! Was expecting false and got true after passing in 15" << endl;
    vector<VTMountain> mountains = {};

    tester.printGuessingMountains(mountains);
    tester.playAgain(-1);
    tester.addPoints(6, mountains);
    tester.addPoints(-1, mountains);
    tester.correctGreens(-1);
    tester.correctBlacks(-1);
    tester.correctGuessDistance(-1);
    tester.correctGuessPrice(-1);
    cout << endl << "Passed all these test cases above, did not crash SkierSnowboarder Class" << endl << endl;
}

// Tests VTMountain class
void testHelper3() {
    VTMountain tester;
    tester.setDistance(-1);
    if (tester.getDistance() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getDistance() << endl;
    tester.setPass(-1);
    if (tester.getSeasonPass() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getSeasonPass() << endl;
    tester.setBlacks(-1);
    if (tester.getBlackTrails() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getBlackTrails() << endl;
    tester.setGreens(-1);
    if (tester.getGreenTrails() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getGreenTrails() << endl;
    tester.setBlues(-1);
    if (tester.getBlueTrails() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getBlueTrails() << endl;
    tester.setTrails(-1);
    if (tester.getTotalTrails() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getTotalTrails() << endl;
    tester.setDoubleBlacks(-1);
    if (tester.getDoubleBlackTrails() != 0)
        cout << "Test case failed! Was expecting 0 and got " << tester.getDoubleBlackTrails() << endl;
    tester.readMountainsFromFile("randomfile.txt");
    tester.readMountainsFromFile("VermontSkiMountains.csv");
    VTMountain returnedValue = tester.find_mountain(-1);
    if (returnedValue.getDoubleBlackTrails() != 0) {
        cout << "Failed test case! Was expecting the default mountain and got the wrong mountain!" << endl;
    }

    cout << endl << "Passed test cases above for VTMountain class, did not crash!" << endl;
}

// Tests Critic class
void testHelper4() {
    critic tester;
    tester.setReview("");
    if (tester.getReview() != "No critic review written")
        cout << "Failed test case! Was expecting no critic review written and got " << tester.getReview() << endl;
    tester.setStars(-1);
    if (tester.getStars() != 1)
        cout << "Failed test case! Was expecting 1 and got " << tester.getStars() << endl;
    tester.setStars(5);
    if (tester.getStars() != 1)
        cout << "Failed test case! Was expecting 1 and got " << tester.getStars() << endl;
    tester.setCategory("");
    if (tester.getCategory() != "None")
        cout << "Failed test case! Was expecting None and got " << tester.getCategory() << endl;
    tester.setCategory("Blankets");
    if (tester.getCategory() != "None")
        cout << "Failed test case! Was expecting None and got " << tester.getCategory() << endl;

    cout << endl << "Passed all test cases for critic class!" << endl;
}

