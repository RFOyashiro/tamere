#include <iostream>
#include <vector>
#include <math.h>
#include "Wave.hpp"

#define FREQECHANT 44100.0
#define TEMPS      6
#define SIZE       TEMPS * 44100

using namespace std;

namespace {

    void NoteCreate(unsigned char* Data, double Frequence, double Min, double Max) {
        double FrequenceNum = Frequence / (double) FREQECHANT;

        for (unsigned i (0); i < SIZE; ++i){
            Data[i] = (unsigned char) ((255.0 / (Max - Min)) * (sin(2.0 * M_PI * FrequenceNum * (double) i) - Min));
        }
    }
}

int main() {
    unsigned char Data[SIZE];

    NoteCreate(Data, 440.0, 0.0, 255.0);

    cout << Data[2] << endl;

    Wave(Data, SIZE, 1, FREQECHANT).write("la.wav");
    return 0;
}
