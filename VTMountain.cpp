//
// Created by Lauren Paicopolis on 2/14/20.
//

#include "VTMountain.h"

/************* VTMountain class ******************/

// Default Constructor
VTMountain::VTMountain () {
    seasonPass = numTrails = distance = blueTrails = greenTrails = blackTrails = doubleBlackTrails = 0;
    mountainNumber = "0";
    mountainName = "VTMountain";
    nightSkiing = nullopt;
}

// Constructor
VTMountain::VTMountain (string mountainNumber, string mountainName, string nightSkiing, int numTrails, int seasonPass, int greens, int blues, int blacks, int doubleBlacks, int distance) {
    setName(mountainName);
    setMountainNumber(mountainNumber);
    setNightSkiing(nightSkiing);
    setTrails(numTrails);
    setPass(seasonPass);
    setGreens(greens);
    setBlues(blues);
    setBlacks(blacks);
    setDoubleBlacks(doubleBlacks);
    setDistance(distance);
}

// Setters
void VTMountain::setMountainNumber(string mountainNumber) {
    if (mountainNumber == "") {
        this->mountainNumber = "Unnumbered mountain";
    }
    this->mountainNumber = mountainNumber;
}

void VTMountain::setName(string mountainName){
    if (mountainName == "") {
        this->mountainName = "Unnamed mountain";
    }
    else {
        this->mountainName = mountainName;
    }
}

void VTMountain::setNightSkiing(string nightSkiing) {
    if (nightSkiing == "No"){
        this->nightSkiing = nullopt;
    }
    else {
        this->nightSkiing = nightSkiing;
    }
}

void VTMountain::setTrails(int numTrails){
    this->numTrails = (numTrails < 0) ? 0 : numTrails;
}
void VTMountain::setPass(int seasonPass){
    this->seasonPass = (seasonPass < 0) ? 0 : seasonPass;
}
void VTMountain::setGreens(int greenTrails){
    this->greenTrails = (greenTrails < 0) ? 0 : greenTrails;
}
void VTMountain::setBlues(int blueTrails){
    this->blueTrails = (blueTrails < 0) ? 0 : blueTrails;
}
void VTMountain::setBlacks(int blackTrails){
    this->blackTrails = (blackTrails < 0) ? 0 : blackTrails;
}
void VTMountain::setDoubleBlacks(int doubleBlackTrails){
    this->doubleBlackTrails = (doubleBlackTrails < 0) ? 0 : doubleBlackTrails;
}
void VTMountain::setDistance(int distance){
    this->distance = (distance < 0) ? 0 : distance;
}

//Getters
string VTMountain::getMountainNumber() const {
    return mountainNumber;
}
optMountain VTMountain::getNightSkiing() const {
    return nightSkiing;
}
string VTMountain::getName() const {
    return mountainName;
}
int VTMountain::getBlackTrails() const {
    return blackTrails;
}
int VTMountain::getDoubleBlackTrails() const {
    return doubleBlackTrails;
}
int VTMountain::getGreenTrails() const {
    return greenTrails;
}
int VTMountain::getBlueTrails() const {
    return blueTrails;
}
int VTMountain::getTotalTrails() const {
    return numTrails;
}
int VTMountain::getSeasonPass() const {
    return seasonPass;
}
int VTMountain::getDistance() const {
    return distance;
}

// Reads in file into vector of mountain objects
void VTMountain::readMountainsFromFile(string fileName) {
    if (fileName == "VermontSkiMountains.csv") {
        ifstream fIn;
        // Look for the file outside of the cmake-build-debug folder
        fIn.open("../" + fileName);

        // read/get rid of header line
        if (fIn) {
            string header = "";
            getline(fIn, header);
        }

        while (fIn && fIn.peek() != EOF) {
            string nightSkiing = "";
            string mountainNumber = "";
            string mountainName = "";
            int numTrails = 0, blueTrails = 0, greenTrails = 0, blackTrails = 0, doubleBlackTrails = 0;
            int distance = 0, seasonPass = 0;
            char comma = ',';

            getline(fIn, mountainNumber, ',');
            getline(fIn, mountainName, ',');
            getline(fIn, nightSkiing, ',');
            fIn >> numTrails;
            fIn >> comma;
            fIn >> seasonPass;
            fIn >> comma;
            fIn >> greenTrails;
            fIn >> comma;
            fIn >> blueTrails;
            fIn >> comma;
            fIn >> blackTrails;
            fIn >> comma;
            fIn >> doubleBlackTrails;
            fIn >> comma;
            fIn >> distance;

            mountains.push_back(
                    VTMountain(mountainNumber, mountainName, nightSkiing, numTrails, seasonPass, greenTrails,
                               blueTrails, blackTrails,
                               doubleBlackTrails, distance));
        }
        fIn.close();
    }
    else
        cout << "Passed test case! We cannot process that file!";
}

// finds mountain at specified index
VTMountain VTMountain::find_mountain(int mountain_num) {
    readMountainsFromFile("VermontSkiMountains.csv");
    for (int i = 0; i < mountains.size(); i++)
    {
        if (i == mountain_num)
        {
            return mountains[i];
        }
    }
    // will return not_found if mountain is not in vector/csv file
    VTMountain not_found = VTMountain("0:","Wrong", "No", -1, -1, -1, -1, -1, -1, -1);
    return not_found;
}

// Overloaded << operator
ostream& operator << (ostream& outs, const VTMountain &mountain) {
    cout << endl;
    cout << mountain.getName() << endl;
    cout << "Total Trails: " << mountain.getTotalTrails() << endl;
    cout << "Season Pass Price: $" << mountain.getSeasonPass() << endl;
    cout << "Green Trails: " << mountain.getGreenTrails() << endl;
    cout << "Blue Trails: " << mountain.getBlueTrails() << endl;
    cout << "Black Trails: " << mountain.getBlackTrails() << endl;
    cout << "Double Black Trails: " << mountain.getDoubleBlackTrails() << endl;
    cout << "Minutes from UVM: " << mountain.getDistance();
    return outs;
}