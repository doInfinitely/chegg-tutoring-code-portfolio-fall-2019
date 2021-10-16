#include "Header.h"

void compute(int HTO, int HTD, int HTS, int HTH, int HTC, int VTO, int VTD, int VTS, int VTR, double predictions[]) {
    predictions[0] = HTO * OFFENSIVE_FACTOR - VTD;
    predictions[1] = HTD + 2 - VTO * OFFENSIVE_FACTOR;
    predictions[2] = HTS * SPECIAL_TEAMS_FACTOR - VTS;
    predictions[3] = HTH + HTC * HOME_FIELD_ADVANTAGE - VTS;
    predictions[4] = HTO * HTD * HTH * OVERALL_FACTOR - VTO * VTD * VTR;
}

int score(double predictor1, double predictor2, double predictor3, double predictor4, double predictor5) {
    double difference = predictor1 * OFFENSIVE_WORTH + predictor2 * DEFENSIVE_WORTH + predictor3 * SPECIAL_WORTH + predictor4 * HOME_WORTH + predictor5 * OVERALL_WORTH;
    return (int) difference;
}
