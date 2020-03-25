//
// Created by Lauren Paicopolis on 2/14/20.
//

#ifndef LP_PROJECR3_VTMOUNTAIN_H
#define LP_PROJECR3_VTMOUNTAIN_H

#include <fstream>
#include <experimental/optional>
#include <optional>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::experimental::optional;
using std::experimental::nullopt;
typedef optional<string> optMountain;
/*
 * This program contains:
 * VTMountain class which includes:
 * findMountain with function to find the user specified mountain
 * compareMountain with function to compare two mountains
 * displayUserinterface which explains program to user and prompts user to for input
 * userValidation which validates the users input
 * readMountainsFromFile which reads a csv file into a vector
 */

class VTMountain {
private:
    // Fields
    string mountainName;
    int seasonPass;
    int numTrails;
    int distance;
    optMountain nightSkiing;
    string mountainNumber;
    int blueTrails;
    int greenTrails;
    int blackTrails;
    int doubleBlackTrails;
    vector<VTMountain> mountains;

public:
    // Default Constructor
    VTMountain ();
    // Constructor
    // Requires: a string and non negative inputs for integers
    // Modifies: mountainName, numTrails, seasonPass, greens, blues, blacks, doubleBlacks, distance
    // Effects: Sets fields to default values
    VTMountain (string mountainNumber, string mountainName, string nightSkiing, int numTrails, int seasonPass, int greens, int blues, int blacks, int doubleBlacks, int distance);

    // Setters
    // Requires: String and non-negative integer input
    // Modifies: The field being set
    // Effects: Assigns the input value to the field
    void setMountainNumber(string mountainNumber);
    void setName(string mountainName);
    void setTrails(int numTrails);
    void setPass(int seasonPass);
    void setGreens(int greenTrails);
    void setBlues(int blueTrails);
    void setBlacks(int blackTrails);
    void setDoubleBlacks(int doubleBlackTrails);
    void setDistance(int distance);
    void setNightSkiing(string nightSkiing);

    //Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value of the field
    string getMountainNumber() const;
    optMountain getNightSkiing() const;
    string getName() const;
    int getBlackTrails() const;
    int getDoubleBlackTrails() const;
    int getGreenTrails() const;
    int getBlueTrails() const;
    int getTotalTrails() const;
    int getSeasonPass() const;
    int getDistance() const;

    // Requires: vector of mountain object and ostream
    // Modifies: Nothing
    // Effects: Returns the formatted data collected on mountain selected
    friend ostream& operator << (ostream& outs, const VTMountain &mountain);

    // Requires: string csv filename and a vector for mountain objects
    // Modifies: vector<VTMountain> mountains
    // Effects: Reads in csv file and creates mountain objects placed inside mountains vector
    void readMountainsFromFile(string fileName);

    // Requires: Non-negative integer
    // Modifies: nothing
    // Effects: finds user selected mountain in vector mountains and returns it
    VTMountain find_mountain(int mountain_num);

};

#endif //LP_PROJECR3_VTMOUNTAIN_H
