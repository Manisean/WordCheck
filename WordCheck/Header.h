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
    vector<string> words;
    string swear;
    string word;
    int chk = 0;

    ifstream swearsFile("C:\\Users\\markh\\source\\repos\\WordCheck\\WordCheck\\swears.txt");
    stringstream ss(inputLine);

    while (swearsFile >> swear) {
        swears.push_back(swear);
    }
    swearsFile.close();

    while (ss >> word) {
        words.push_back(word);
    }

    for (int i = 0; i < swears.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (swears[i] == words[j]) {
                cout << "Your file contains the naughty word: " 
                     << words[j] << ". Please consider removing it." << endl;
                chk++;
            }
        }
    }

    if (chk > 0) {
        return true;
    }
    else {
        cout << "Your file is naughty word free! congrats!\n";
        return false;
    }
}

// extra char func for test
bool extraChar(string inputLine) {
    ifstream wordsFile("C:\\Users\\markh\\source\\repos\\WordCheck\\WordCheck\\words.txt");
    char c = 'x';
    vector<string> words;
    string word;
    int chk = 0;

    while (wordsFile >> word) {
        words.push_back(word);
    }

    wordsFile.close();

    for (int i = 0; i < words.size(); i++) {
        if (inputLine.find(words[i] + c) != string::npos) {
            cout << "Your typo is: " << words[i] << c << " it should be: " << words[i] << endl;
            chk++;
        }
    }

    if (chk > 0) {
        return true;
    }
    else {
        return false;
    }
}

bool checkUpper(string file) {
    ifstream input(file);
    string line;
    vector<string> vec;
    int chk = 0;

    while (getline(input, line, ' ')) {
        vec.push_back(line);
    }
    
    for (int i = 0; i < vec.size(); i++) {
        string word = vec[i];
        for (int j = 0; j < word.length(); j++) {
            if (!isupper(word[j])) {
                chk++;
            }
        }
    }

    input.close();

    if (chk == 0) {
        cout << "This string is all uppercase letter, weird.\n";
        return true;
    }
    else {
        cout << "This string has a couple lowercase letters, cool.\n";
        return false;
    }

    
}


void replaceWithRandom(string fileName, string word) {
    ifstream input(fileName);
    ifstream wordsFile("C:\\Users\\markh\\source\\repos\\WordCheck\\WordCheck\\words.txt");
    string line;
    vector<string> vec;
    vector<string> words;
    string item;
    int chk = 0;

    

    while (getline(input, line, ' ')) {
        vec.push_back(line);
    }

    while (wordsFile >> item) {
        words.push_back(item);
    }

    int r = rand() % words.size();
    wordsFile.close();
    input.close();
    ofstream output(fileName);

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == word) {
            vec[i] = words[r];
            chk++;
        }
    }

    for (int j = 0; j < vec.size(); j++) {
        output << " " << vec[j];
    }

    
    output.close();

}