#include "Header.h"

int main() {
    ifstream inputFile("inputFile.txt");
    string inputLine;

    if (inputFile) {
        getline(inputFile, inputLine);

        extraChar(inputLine);
        swears(inputLine);

    }
    else {
        cout << "Could not open the provided file\n";
    }
}