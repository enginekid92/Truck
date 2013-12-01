#include <Arduino.h>

void setup()
{
    //Inputs
    pinMode(nHatch, INPUT);
    pinMode(nIgnAcc, INPUT);
    pinMode(nIgnOn, INPUT);
    pinMode(nIgnStart, INPUT);

    //Outputs

    Serial.begin(9600);
}
