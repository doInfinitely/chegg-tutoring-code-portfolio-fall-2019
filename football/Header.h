#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define OFFENSIVE_FACTOR 1.15
#define SPECIAL_TEAMS_FACTOR 1.22
#define HOME_FIELD_ADVANTAGE 1.2
#define OVERALL_FACTOR 1.15
#define OFFENSIVE_WORTH 0.30
#define DEFENSIVE_WORTH 0.24
#define SPECIAL_WORTH 0.17
#define HOME_WORTH 0.11
#define OVERALL_WORTH 0.13

// Prototypes

void input(FILE* fp, char[], int*, int*, int*, int*, int*, char[], int*, int*, int*, int*);
void compute(int, int, int, int, int, int, int, int, int, double[]);
int score(double, double, double, double, double);
void output(char[], char[], int);
