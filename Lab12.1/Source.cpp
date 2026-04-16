#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void pressEnterToContinue();

int main() {
    cout << "Lab 12: Word and Character Counter" << endl;

    string path;
    cout << "Enter the file path: ";
    getline(cin, path);
    cin.ignore();

    ifstream inFile(path);
    if (!inFile.is_open()) {
        cout << "Error: could not open file \"" << path << "\"" << endl;
        pressEnterToContinue();
        return 1;
    }

    int wordCount = 0;
    int charCount = 0;  // non-whitespace characters (punctuation included)
    string word;

    while (inFile >> word) {           // >> splits on whitespace
        wordCount++;
        charCount += (int)word.length();   // every char in the token
    }

    inFile.close();

    cout << "Words:      " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    pressEnterToContinue();
    return 0;
}

void pressEnterToContinue() {
    cout << "Press enter to continue..." << endl;
    cin.clear();
    while (cin.get() != '\n') continue;
}