#include "pch.h"
//replace with path to Header.h

#include "c:\users\markh\source\repos\wordcheck\WordCheck\Header.h"

// Test to make sure everything is working correctly

// Test to check for all upper case words in text file
TEST(WordCheckTest, UpperTest) {
	string filename = "C:\\Users\\markh\\source\\repos\\WordCheck\\Test\\checkUpper3.txt";

	EXPECT_TRUE(checkUpper(filename));

	remove(filename.c_str());
}



// Test for a provided word to be replaced with a random word from a separate text file
TEST(WordCheckTest, RandomTest) {
	
	string filename = "C:\\Users\\markh\\source\\repos\\WordCheck\\Test\\fox.txt";
	replaceWithRandom(filename, "fox");

	// Read the file and make sure "fox" has been replaced
	ifstream infile(filename);
	string line;
	getline(infile, line);
	infile.close();

	EXPECT_NE(line.find("fox"), std::string::npos) << "Original word not found in file.";
	EXPECT_EQ(line.find("fox"), std::string::npos) << "Replaced word found in file.";
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

	if (extraChar(inputLine) == false) {
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

	if (swears(inputLine) == false) {
		SUCCEED();
	}
	else {
		FAIL();
	}

	inputFile.close();
}