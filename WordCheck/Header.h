#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// swear filter func for test
bool swears(string inputLine) {

    vector<string> swears;
    string swear;
    ifstream swearsFile("swears.txt");
    while (swearsFile >> swear) {
        swears.push_back(swear);
    }
    swearsFile.close();

    for (int i = 0; i < swears.size(); i++) {
        string w = swears[i];
        if (inputLine.find(w) != string::npos) {
            return true;
        }
    }
   
    return false;
}

// extra char func for test
bool extraChar(string inputLine) {

    return false;
}

bool checkUpper(string file) {


    return false;
}


bool replaceWithRandom(string fileName, string word) {

    return false;
}