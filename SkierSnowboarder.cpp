//
// Created by Lauren Paicopolis on 2/14/20.
//

#include "SkierSnowboarder.h"

/************* SkierSnowboarder class ******************/

// Default Constructor
SkierSnowboarder::SkierSnowboarder() {
    distance = expensiveLevel = hardWayDown = easyWayDown = userMountains = 0;
    totalGuessesPrice = totalGuessesDistance = totalGuessesBlacks = totalGuessesGreens = 0;
    winterSport = "";
}

// Setters
void SkierSnowboarder::setEasyWayDown(int easy) {
    if (easy < 1 or easy > 4)
        easyWayDown = 1;
    else
        easyWayDown = easy;
}
void SkierSnowboarder::setHardWayDown(int hard) {
    if (hard < 1 or hard > 4)
        hardWayDown = 1;
    else
        hardWayDown = hard;
}
void SkierSnowboarder::setExpensiveLevel(int expensive) {
    if (expensive < 1 or expensive > 4)
        expensiveLevel = 1;
    else
        expensiveLevel = expensive;
}
void SkierSnowboarder::setDistance(int userDistance) {
    if (userDistance < 1 or userDistance > 4)
        distance = 1;
    else
        distance = userDistance;
}
void SkierSnowboarder::setUserMountains(int mountains) {
    if (mountains < 1 or mountains > 15)
        userMountains = 0;
    else
        userMountains = mountains;
}
void SkierSnowboarder::setWinterSport(string sport) {
    winterSport = sport;
}
void SkierSnowboarder::setVTMountain(VTMountain object){
    mountaintoFind = object;
}

//Getters
int SkierSnowboarder::getEasyWayDown() {
    return easyWayDown;
}
int SkierSnowboarder::getHardWayDown() {
    return hardWayDown;
}
int SkierSnowboarder::getExpensiveLevel() {
    return expensiveLevel;
}
int SkierSnowboarder::getDistance() {
    return distance;
}
int SkierSnowboarder::getUserMountains() {
    return userMountains;
}
string SkierSnowboarder::getWinterSport() {
    return winterSport;
}
VTMountain SkierSnowboarder::getVTMountain() {
    return mountaintoFind;
}

// Makes sure random number has not been used already
bool SkierSnowboarder::checkRandomNumber(int randomNum) {
    if (randomNum < 0)
        return false;
    if (randomNum > 14)
        return false;

    // Adding first random number to vector of random numbers used
    if (count == 0) {
        randomNumbersUsed.push_back(randomNum);
        count++;
        return true;
    }

    for (int i = 0; i < randomNumbersUsed.size(); i++){
        if (randomNumbersUsed[i] == randomNum) {
            return false;
        }
    }

    randomNumbersUsed.push_back(randomNum);
    return true;
}

// Generate random number
int SkierSnowboarder::generateRandomNumber() {
    int randomNum;
    bool doneAlready;

    // Out of 14 mountains in VT
    randomNum = rand() % 14;
    doneAlready = checkRandomNumber(randomNum);

    // Do it again if random number not already used
    while (!doneAlready) {
        randomNum = rand() % 14;
        doneAlready = checkRandomNumber(randomNum);
    }
    return randomNum;
}

// Pushes back mountains user can guess between to vectors
void SkierSnowboarder::selectMountains() {
    int randomNum;
    srand(time(0));
    for (int i = 0; i < userMountains; i++) {
        randomNum = generateRandomNumber();
        mountaintoFind = mountaintoFind.find_mountain(randomNum);
        guessingMountainsGreen.push_back(mountaintoFind);
        guessingMountainsBlack.push_back(mountaintoFind);
        guessingMountainsDistance.push_back(mountaintoFind);
        guessingMountainsPrice.push_back(mountaintoFind);
    }
    printGuessingMountains(guessingMountainsGreen);
}

// Prints user mountains to guess between
void SkierSnowboarder::printGuessingMountains(vector<VTMountain> &mountains) {
    cout << endl << "Guessing Number: " << endl;
    if (!mountains.empty()) {
        for (int i = 0; i < mountains.size(); i++) {
            cout << i << " " << mountains[i].getName() << endl;
        }
    }
    else
        cout << "Passed test case: There are no mountains for you to guess between! We are sorry!" << endl;
}

// Allows user to enter in mountain guess
void SkierSnowboarder::guessingGame() {
    int priceRange;
    int userDistance;
    int userGreens;
    int userBlacks;

    // Guess for Price
    while (totalGuessesPrice < (userMountains - 1) & count1 < 1) {
        cout << endl << "Criteria number: " << getExpensiveLevel();
        cout << endl << "Out of the mountains above, which one matches your price range? ";
        cin >> priceRange;
        priceRange = validateGuess(priceRange);
        totalGuessesPrice++;
        correctGuessPrice(priceRange);
    }

    // Guess for Distance
    while (totalGuessesDistance < (userMountains - 1) & count1 < 2) {
        if (totalGuessesDistance == 0)
            printGuessingMountains(guessingMountainsDistance);
        cout << endl << "Criteria number: " << getDistance();
        cout << endl <<"Out of the mountains above, which one matches your distance? ";
        cin >> userDistance;
        userDistance = validateGuess(userDistance);
        totalGuessesDistance++;
        correctGuessDistance(userDistance);
    }

    // Guess for Green Trails
    while (totalGuessesGreens < (userMountains - 1) & count1 < 3) {
        if (totalGuessesGreens == 0)
            printGuessingMountains(guessingMountainsGreen);
        cout << endl << "Criteria number: " << getEasyWayDown();
        cout << endl << "Out of the mountains above, which one matches your range of green circle trails? ";
        cin >> userGreens;
        userGreens = validateGuess(userGreens);
        totalGuessesGreens++;
        correctGreens(userGreens);
    }

    // Guess for Black Trails
    while (totalGuessesBlacks < (userMountains - 1) & count1 < 4) {
        if (totalGuessesBlacks == 0)
            printGuessingMountains(guessingMountainsBlack);
        cout << endl << "Criteria number: " << getHardWayDown();
        cout << endl << "Out of the mountains above, which one matches your range of black diamond trails? ";
        cin >> userBlacks;
        userBlacks = validateGuess(userBlacks);
        totalGuessesBlacks++;
        correctBlacks(userBlacks);
    }
}

// Asks if user wants to continue or sees if they ran out of guesses
void SkierSnowboarder::playAgain(int totalGuesses) {
    string answer;

    if (totalGuesses < 0)
        totalGuesses = 0;
    else if (totalGuesses > (userMountains - 1))
        totalGuesses = userMountains - 1;

    // ran out of guesses
    else if ((userMountains - 1) - totalGuesses == 0) {
        cout << "You are all out of guesses! Move on to the next category!" << endl;
        count1++;
    }

    // Guess again
    else if (count1 != 4) {
        cout << endl << "Would you like to guess again? You have " << ((userMountains - 1) - totalGuesses) << " guesses left!"
             << endl;
        cout << "Enter 'y' or 'Y' for yes, and 'n' or 'N' for no: ";
        cin >> answer;
        while (answer != "Y" & answer != "y" & answer != "n" & answer != "N") {
            cout << "Please enter a valid answer (y/n): ";
            cin >> answer;
        }
        if (answer == "n" or answer == "N") {
            totalGuessesGreens = totalGuessesBlacks = totalGuessesDistance = totalGuessesPrice = 0;
            count1++;
        }
        if (count1 != 4) {
            guessingGame();
        }
    }
}

// Adds corresponding points to user score
void SkierSnowboarder::addPoints(int totalGuesses, vector<VTMountain> &mountains) {

    if (!mountains.empty()) {
        if (totalGuesses < 0)
            totalGuesses = 0;

        else if (totalGuesses > (userMountains - 1))
            totalGuesses = userMountains - 1;

        else if (totalGuesses == 1) {
            points = 3 + points;
            printGuessingMountains(mountains);
            setPoints(points);
            playAgain(totalGuesses);
        }
        else if (totalGuesses == 2) {
            points = 2 + points;
            printGuessingMountains(mountains);
            setPoints(points);
            playAgain(totalGuesses);
        }
        else if (totalGuesses <= (userMountains - 1)) {
            points = 1 + points;
            if (totalGuesses != 0 && count1 != 4) {
                printGuessingMountains(mountains);
            }
            setPoints(points);
            playAgain(totalGuesses);
        }
    }
    else
        cout << "Passed Test case! There are no mountains for you to guess between! We are sorry!" << endl;
}

// Checks to see if mountain selected matches user criteria for Green Trails
void SkierSnowboarder::correctGreens(int guess) {
    if (guess < 0 or guess > userMountains - 1)
        cout << "Passed test case! Your guess was too big or too small, you don't get to play again!" << endl;
    else if (25 <= guessingMountainsGreen[guess].getGreenTrails()) {
        if (getEasyWayDown() != 1){
            cout << guessingMountainsGreen[guess].getName() << " has more or less green trails then you wanted!" << endl;
            playAgain(totalGuessesGreens);
        }
        else {
            cout << guessingMountainsGreen[guess].getName() << " has the number of green trails you wanted! Nice guess!" << endl;
            guessingMountainsGreen.erase(guessingMountainsGreen.begin()+guess);
            addPoints(totalGuessesGreens, guessingMountainsGreen);
        }
    }
    else if (15 <= guessingMountainsGreen[guess].getGreenTrails()) {
        if (getEasyWayDown() != 2){
            cout << guessingMountainsGreen[guess].getName() << " has more or less green trails then you wanted!" << endl;
            playAgain(totalGuessesGreens);
        }
        else {
            cout << guessingMountainsGreen[guess].getName() << " has the number of green trails you wanted! Nice guess!" << endl;
            guessingMountainsGreen.erase(guessingMountainsGreen.begin()+guess);
            addPoints(totalGuessesGreens, guessingMountainsGreen);
        }
    }
    else if (10 <= guessingMountainsGreen[guess].getGreenTrails()) {
        if (getEasyWayDown() != 3){
            cout << guessingMountainsGreen[guess].getName() << " has more or less green trails then you wanted!" << endl;
            playAgain(totalGuessesGreens);
        }
        else {
            cout << guessingMountainsGreen[guess].getName() << " has the number of green trails you wanted! Nice guess!" << endl;
            guessingMountainsGreen.erase(guessingMountainsGreen.begin()+guess);
            addPoints(totalGuessesGreens, guessingMountainsGreen);
        }
    }
    else if (0 <= guessingMountainsGreen[guess].getGreenTrails()) {
        if (getEasyWayDown() != 4){
            cout << guessingMountainsGreen[guess].getName() << " has more or less green trails then you wanted!" << endl;
            playAgain(totalGuessesGreens);
        }
        else {
            cout << guessingMountainsGreen[guess].getName() << " has the number of green trails you wanted! Nice guess!" << endl;
            guessingMountainsGreen.erase(guessingMountainsGreen.begin()+guess);
            addPoints(totalGuessesGreens, guessingMountainsGreen);
        }
    }
}

// Checks to see if mountain selected matches user criteria for Black Trails
void SkierSnowboarder::correctBlacks(int guess) {
    if (guess < 0 or guess > userMountains - 1)
        cout << "Passed test case! Your guess was too big or too small, you don't get to play again!" << endl;
    else if (29 <= guessingMountainsBlack[guess].getBlackTrails()) {
        if (getHardWayDown() != 1){
            cout << guessingMountainsBlack[guess].getName() << " has more or less black trails then you wanted!" << endl;
            playAgain(totalGuessesBlacks);
        }
        else {
            cout << guessingMountainsBlack[guess].getName() << " has the number of black trails you wanted! Nice guess!" << endl;
            guessingMountainsBlack.erase(guessingMountainsBlack.begin()+guess);
            addPoints(totalGuessesBlacks, guessingMountainsBlack);
        }
    }
    else if (19 <= guessingMountainsBlack[guess].getBlackTrails()) {
        if (getHardWayDown() != 2){
            cout << guessingMountainsBlack[guess].getName() << " has more or less black trails then you wanted!" << endl;
            playAgain(totalGuessesBlacks);
        }
        else {
            cout << guessingMountainsBlack[guess].getName() << " has the number of black trails you wanted! Nice guess!" << endl;
            guessingMountainsBlack.erase(guessingMountainsBlack.begin()+guess);
            addPoints(totalGuessesBlacks, guessingMountainsBlack);
        }
    }
    else if (10 <= guessingMountainsBlack[guess].getBlackTrails()) {
        if (getHardWayDown() != 3){
            cout << guessingMountainsBlack[guess].getName() << " has more or less black trails then you wanted!" << endl;
            playAgain(totalGuessesBlacks);
        }
        else {
            cout << guessingMountainsBlack[guess].getName() << " has the number of black trails you wanted! Nice guess!" << endl;
            guessingMountainsBlack.erase(guessingMountainsBlack.begin()+guess);
            addPoints(totalGuessesBlacks, guessingMountainsBlack);
        }
    }
    else if (0 <= guessingMountainsBlack[guess].getBlackTrails()) {
        if (getHardWayDown() != 4){
            cout << guessingMountainsBlack[guess].getName() << " has more or less black trails then you wanted!" << endl;
            playAgain(totalGuessesBlacks);
        }
        else {
            cout << guessingMountainsBlack[guess].getName() << " has the number of black trails you wanted! Nice guess!" << endl;
            guessingMountainsBlack.erase(guessingMountainsBlack.begin()+guess);
            addPoints(totalGuessesBlacks, guessingMountainsBlack);
        }
    }
}

// Checks to see if mountain selected matches user criteria for Distance
void SkierSnowboarder::correctGuessDistance(int guess) {
    if (guess < 0 or guess > userMountains - 1)
        cout << "Passed test case! Your guess was too big or too small, you don't get to play again!" << endl;
    else if (guessingMountainsDistance[guess].getDistance() <= 56){
        if (getDistance() != 1){
            cout << guessingMountainsDistance[guess].getName() << " is not in your distance range!" << endl;
            playAgain(totalGuessesDistance);
        }
        else {
            cout << guessingMountainsDistance[guess].getName() << " is in your distance!" << endl;
            guessingMountainsDistance.erase(guessingMountainsDistance.begin()+guess);
            addPoints(totalGuessesDistance, guessingMountainsDistance);
        }
    }
    else if (guessingMountainsDistance[guess].getDistance() <= 103){
        if (getDistance() != 2){
            cout << guessingMountainsDistance[guess].getName() << " is not in your distance range!" << endl;
            playAgain(totalGuessesDistance);
        }
        else {
            cout << guessingMountainsDistance[guess].getName() << " is in your distance!" << endl;
            guessingMountainsDistance.erase(guessingMountainsDistance.begin()+guess);
            addPoints(totalGuessesDistance, guessingMountainsDistance);
        }
    }
    else if (guessingMountainsDistance[guess].getDistance() <= 141){
        if (getDistance() != 3){
            cout << guessingMountainsDistance[guess].getName() << " is not in your distance range!" << endl;
            playAgain(totalGuessesDistance);
        }
        else {
            cout << guessingMountainsDistance[guess].getName() << " is in your distance!" << endl;
            guessingMountainsDistance.erase(guessingMountainsDistance.begin()+guess);
            addPoints(totalGuessesDistance, guessingMountainsDistance);
        }
    }
    else if (guessingMountainsDistance[guess].getDistance() <= 180){
        if (getDistance() != 4){
            cout << guessingMountainsDistance[guess].getName() << " is not in your distance range!" << endl;
            playAgain(totalGuessesDistance);
        }
        else {
            cout << guessingMountainsDistance[guess].getName() << " is in your distance!" << endl;
            guessingMountainsDistance.erase(guessingMountainsDistance.begin()+guess);
            addPoints(totalGuessesDistance, guessingMountainsDistance);
        }
    }
    else {
        cout << "Something went wrong, oops!" << endl;
    }
}

// Checks to see if mountain selected matches user criteria for Price
void SkierSnowboarder::correctGuessPrice(int guess) {
    if (guess < 0 or guess > userMountains - 1)
        cout << "Passed test case! Your guess was too big or too small, you don't get to play again!" << endl;
    else if (guessingMountainsPrice[guess].getSeasonPass() < 300)  {
        if (getExpensiveLevel() != 4) {
            cout << guessingMountainsPrice[guess].getName() << " is not in your price range!" << endl;
            playAgain(totalGuessesPrice);
        }
        else {
            cout << guessingMountainsPrice[guess].getName() << " is in your price range!" << endl;
            guessingMountainsPrice.erase(guessingMountainsPrice.begin()+guess);
            addPoints(totalGuessesPrice, guessingMountainsPrice);
        }
    }
    else if (guessingMountainsPrice[guess].getSeasonPass() < 400) {
        if (getExpensiveLevel() != 3) {
            cout << guessingMountainsPrice[guess].getName() << " is not in your price range!" << endl;
            playAgain(totalGuessesPrice);
        }
        else {
            cout << guessingMountainsPrice[guess].getName() << " is in your price range!" << endl;
            guessingMountainsPrice.erase(guessingMountainsPrice.begin()+guess);
            addPoints(totalGuessesPrice, guessingMountainsPrice);
        }
    }
    else if (guessingMountainsPrice[guess].getSeasonPass() < 439) {
        if (getExpensiveLevel() != 2) {
            cout << guessingMountainsPrice[guess].getName() << " is not in your price range!" << endl;
            playAgain(totalGuessesPrice);
        }
        else {
            cout << guessingMountainsPrice[guess].getName() << " is in your price range!" << endl;
            guessingMountainsPrice.erase(guessingMountainsPrice.begin()+guess);
            addPoints(totalGuessesPrice, guessingMountainsPrice);
        }
    }
    else if (guessingMountainsPrice[guess].getSeasonPass() < 500) {
        if (getExpensiveLevel() != 1) {
            cout << guessingMountainsPrice[guess].getName() << " is not in your price range!" << endl;
            playAgain(totalGuessesPrice);
        }
        else {
            cout << guessingMountainsPrice[guess].getName() << " is in your price range!" << endl;
            guessingMountainsPrice.erase(guessingMountainsPrice.begin()+guess);
            addPoints(totalGuessesPrice, guessingMountainsPrice);
        }
    }
    else {
        cout << "Something went wrong, oops!" << endl;
    }
}

// Validates user mountain guess selection
int SkierSnowboarder::validateGuess(int guess) {
    while (!cin) {
        cout << "Invalid input, please enter a number: ";
        cin.clear();
        cin.ignore();
        cin >> guess;

        while (guess > (userMountains - 1) or guess < 0) {
            cout << "Please enter a number between 0 and " << userMountains - 1 << ": ";
            cin.clear();
            cin.ignore();
            cin >> guess;
        }
    }

    while (guess > (userMountains - 1) or guess < 0) {
        cout << "Please enter a number between 0 and " << userMountains - 1 << ": ";
        cin.clear();
        cin.ignore();
        cin >> guess;

        while (!cin) {
            cout << "Invalid input, please enter a number: ";
            cin.clear();
            cin.ignore();
            cin >> guess;
        }
    }
    return guess;
}