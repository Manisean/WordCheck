#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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

    vector<string> words;
    stringstream ss(inputLine);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < swears.size(); j++) {
            if (words[i] == swears[j]) {
                return true;
            }
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