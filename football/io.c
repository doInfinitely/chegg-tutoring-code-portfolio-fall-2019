#include "Header.h"

void input(FILE* fp, char homeTeamName[], int* HTO, int* HTD, int* HTS, int* HTH, int* HTC, char visitingTeamName[], int* VTO, int* VTD, int* VTS, int* VTR) {
    fscanf(fp, "%s %d %d %d %d %d %s %d %d %d %d", homeTeamName, HTO, HTD, HTS, HTH,HTC, visitingTeamName, VTO, VTD, VTS, VTR);
}

void output(char homeTeamName[], char visitingTeamName[], int prediction) {
    if (prediction > 0) {
        printf("%s beat %s by %d\n", homeTeamName, visitingTeamName, prediction);
    } else if (prediction < 0) {
        printf("%s beat %s by %d\n",visitingTeamName, homeTeamName, -1*prediction);
    } else {
        printf("The %s and the %s tied\n", visitingTeamName, homeTeamName);
    }
}
