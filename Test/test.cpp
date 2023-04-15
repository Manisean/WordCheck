#include "pch.h"
//replace with path to Header.h
#include "C:\Users\markh\source\repos\WordCheck\WordCheck\Header.h"

// Test to make sure everything is working correctly

// Test to check for all upper case words in text file
TEST(WordCheckTest, UpperTest) {

	string line, word;
	ifstream file("inputFile.txt");

	if (!file.is_open()) {
		cout << "Error Opening File,\n";
		FAIL();
	}

	while (getline(file, line)) {
		istringstream ss(line);
		while (ss >> word) {
			for (int i = 0; i < word.length(); i++) {
				EXPECT_TRUE(isupper(word[i]));
			}
		}
	}

	file.close();

}

// Test for a provided word to be replaced with a random word from a separate text file
TEST(WordCheckTest, RandomTest) {

	string word = "WORD";
	string line, line2, word2;
	bool check = false;
	int wordCount = 0;
	ifstream file("inputFile.txt");
	ifstream file2("words.txt");

	while (file2 >> word) {
		wordCount++;
	}

	srand(time(NULL));
	int randomNumber = rand() % wordCount + 1;

	if (!file.is_open()) {
		cout << "Error Opening File\n";
		FAIL();
	}

	if (!file2.is_open()) {
		cout << "Error Opening File2\n";
		FAIL();
	}

	while (getline(file, line)) {
		istringstream ss(line);
		while (ss >> word) {
			if (word == "WORD") {
				while (getline(file2, line2)) {
					istringstream ss2(line2);
					while (ss2 >> word2) {
						if (wordCount == randomNumber) {
							word = word2;
							SUCCEED();
						}
					}
				}
			}
		}
	}

	FAIL();

	file.close();
}

// check if words in given file have an extra letter
TEST(WordCheckTest, ExtraCharTrue) {
	ifstream inputFile("spellingTrue.txt");
	string inputLine;

	getline(inputFile, inputLine);

	if (extraChar(inputLine)) {
		SUCCEED();
	}
	else {
		FAIL();
	}

	inputFile.close();
}

// check if words in given file are real, no extra letter
TEST(WordCheckTest, ExtraCharFalse) {
	ifstream inputFile("spellingFalse.txt");
	string inputLine;

	getline(inputFile, inputLine);

	if (!extraChar(inputLine)) {
		SUCCEED();
	}
	else {
		FAIL();
	}

	inputFile.close();
}

// check if file has swear words
TEST(WordCheckTest, SwearPresent) {
	ifstream inputFile("swearTest.txt");
	string inputLine;

	getline(inputFile, inputLine);

	if (swears(inputLine)) {
		SUCCEED();
	}
	else {
		FAIL();
	}

	inputFile.close();
}

// check if file is free of swear words
TEST(WordCheckTest, NoSwearPresent) {
	ifstream inputFile("noSwearsTest.txt");
	string inputLine;

	getline(inputFile, inputLine);

	if (!swears(inputLine)) {
		SUCCEED();
	}
	else {
		FAIL();
	}

	inputFile.close();
}