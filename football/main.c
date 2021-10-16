#include "Header.h"

int main() {
    char file[80];
    char homeTeamName[20];
    char visitingTeamName[20];
    int HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR, prediction;
    double predictions[5];
    FILE* fp;
    int i, j = 0;
    printf("%s", "Specify the name of the input file: ");
    scanf("%s", file);
    fp = fopen(file, "r");
    while (!feof(fp)) {
        input(fp, homeTeamName, &HTO, &HTD, &HTS, &HTH, &HTC, visitingTeamName, &VTO, &VTD,&VTS, &VTR);
        compute(HTO, HTD, HTS, HTH, HTC, VTO, VTD, VTS, VTR, predictions);
        prediction = score(predictions[0], predictions[1], predictions[2], predictions[3], predictions[4]);
        output(homeTeamName,visitingTeamName, prediction);
        i++;
        if (prediction >= 0) {
            j++;
        }
    }
    printf("\nOf %d games, %.1f%% were won by the home team\n", i, 100.0*j/i);
    fclose(fp);
}
