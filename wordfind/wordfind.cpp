#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

enum direction {LEFT_RIGHT, RIGHT_LEFT, DOWN, UP, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};
int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
direction dirEnum[8] = {DOWN, LEFT_RIGHT, UP, RIGHT_LEFT, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};
string dirStr[8] = {"down", "right", "up", "left", "right/down", "right/up", "left/down", "left_up"};

const int MAX = 50;

struct wordGame {
    int version;
    int numberRows;
    int numberColumns;
    char puzzle[MAX][MAX];
};

struct wordFind {
    string word;
    bool found;
    int row;
    int column;
    direction where;
    int dirNum;
    int foundCount;

};

// function prototypes go here
bool readPuzzle(wordGame &game, string inputFileName) {
    int n;
    int m;
    string temp;
    ifstream inputFile(inputFileName);
    if (inputFile.is_open()) {
        inputFile >> temp;
        n = stoi(temp);
        inputFile >> temp;
        m = stoi(temp);
        int j = 0;
        while (!inputFile.eof()) {
            inputFile >> temp;
            for (int i = 0; i < m; i++) {
                game.puzzle[j][i] = temp[i];
            }
            j++;
        }
        game.numberRows = n;
        game.numberColumns = m;
    } else {
        return false;
    }
    return true;
}
void displayPuzzle(wordGame &game) {
    for (int i = 0; i < game.numberRows; i++) {
        for (int j = 0; j < game.numberColumns; j++) {
            cout << game.puzzle[i][j];
        }
        cout << endl;
    }
}
void findWord(wordGame &game, wordFind &theFind) {
   for (int i = 0; i < game.numberRows; i ++){
       for (int j = 0; j < game.numberColumns; j++) {
           for (int k = 0; k < 8; k++) {
               int x = 0;
               int y = 0;
               bool found = true;
               for (int m = 0; m < theFind.word.length(); m++) {
                   if(i+x >= game.numberRows || j+y >= game.numberColumns || game.puzzle[i+x][j+y] != theFind.word[m]) {
                       
                       found = false;
                       break;
                   }
                   x += dir[k][1];
                   y += dir[k][0];
               }
               if (found) {
                   theFind.found = true;
                   theFind.row = i;
                   theFind.column = j;
                   theFind.dirNum = k;
                   theFind.where = dirEnum[k];
                   theFind.foundCount++;
               }
           }
       }
   }
}

void displayFind(wordFind theFind) {
    if (theFind.foundCount == 0) {
        cout << "The word " << theFind.word << " was not found" << endl;
    } else if (theFind.foundCount == 1) {
        cout << "The word " << theFind.word << " was found at (" << theFind.row + 1 << "," << theFind.column + 1 << ")" << " - "<< dirStr[theFind.dirNum] << endl;
    } else {
        cout << "The word " << theFind.word << " was found " << theFind.foundCount << " times" << endl;
    }
}

int main() {
    string temp;
    string puzzleFile;// = "puzzle1.txt";
    string wordFile;// = "words1.txt";
    cout << "Please enter the puzzle file:" << endl;
    cin >> puzzleFile;
    cout << "Please enter the word file:" << endl;
    cin >> wordFile;
    struct wordGame game;
    if(!readPuzzle(game, puzzleFile)) {
        cout << "The puzzle file " << puzzleFile << " could not be opened or is invalid";
    }
    displayPuzzle(game);
    ifstream inputFile(wordFile);
    if (inputFile.is_open()) {
        while (!inputFile.eof()) {
            wordFind theFind;
            theFind.found = false;
            theFind.foundCount = 0;
            inputFile >> theFind.word;
            if (theFind.word.length() > 0) {
                findWord(game, theFind);
                displayFind(theFind);
            }
        }
    } else {
        cout << "The puzzle file " << wordFile << " could not be opened or is invalid";
    }
    return 0;
}

