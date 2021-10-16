#include <fstream>
#include <iostream>
#include "Verifier.h"

using namespace std;

void Verifier::readGrid(const char *filename) {
    ifstream File;
    File.open(filename);
    if (!File) {
        cerr << "Unable to open grid file" << endl;
        exit(1);
    }
    int x;
    int i = 0;
    while (File >> x) {
        grid[i/9][i%9] = x;
	i++;
    }
}

void Verifier::printGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool Verifier::verifySolution() {
    int count[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            count[i] = 0;
        }
        for (int j = 0; j < 9; j++) {
            count[grid[i][j]]++;
        }
        for (int j = 0; j < 9; j++) {
            if (count[j] != 1) {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            count[i] = 0;
        }
        for (int j = 0; j < 9; j++) {
            count[grid[j][i]]++;
        }
        for (int j = 0; j < 9; j++) {
            if (count[j] != 1) {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            count[i] = 0;
        }
        for (int j = 0; j < 9; j++) {
            count[grid[i*3/9 + j/3][i*3%9 + j%3]]++;
        }
        for (int j = 0; j < 9; j++) {
            if (count[j] != 1) {
                return false;
            }
        }
    }
    return true;
}
