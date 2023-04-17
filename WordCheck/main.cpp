#include "Header.h"

int main() {
    string name = "inputFile.txt";
    ifstream inputFile(name);
    string inputLine;
    string word;

    if (inputFile) {
        getline(inputFile, inputLine);

        cout << "Your file contents are: " << "'" << inputLine << "'" << endl;
        extraChar(inputLine);
        swears(inputLine);
        checkUpper(name);

        cout << "Enter a word from the file you want to randomly replace: ";
        cin >> word;
        replaceWithRandom(name, word);

    }
    else {
        cout << "Could not open the provided file\n";
    }
}