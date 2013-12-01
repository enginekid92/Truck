#include <Arduino.h>
#include <Function.h>

//Inputs digital
int nHatch = 8;
int nLeftDoor = 12;
int nRightDoor = 13;
int nIgnAcc = 2;
int nIgnOn = 4;
int nIgnStart = 7;

//Inputs analog
int nLightSensor = 0;

//Outputs
int nHeadLights = 3;
int nParkingLights = 5;
int nDomeLight = 6;
int nAccPower = 9;

//Timing
unsigned long ulPrevTime = 0;

//Intial setup, runs when microcontroller powers on
void setup()
{
    //Inputs
    pinMode(nHatch, INPUT);
    pinMode(nLeftDoor, INPUT);
    pinMode(nRightDoor, INPUT);
    pinMode(nIgnAcc, INPUT);
    pinMode(nIgnOn, INPUT);
    pinMode(nIgnStart, INPUT);

    //Outputs
    pinMode(nHeadLights, OUTPUT);
    pinMode(nParkingLights, OUTPUT);
    pinMode(nAccPower, OUTPUT);

    //Other
    Serial.begin(9600);
}

//Main
void loop()
{
    //Timing
    unsigned long ulTime = millis();

    //If the ignition is on
    if (digitalRead(nIgnOn) == HIGH)
    {
        HeadLights(nHeadLights);
        ParkLights(analogRead(nLightSensor), ulTime, nParkingLights);
        DomeLight(ulTime, 1, nHatch, nLeftDoor, nRightDoor, nDomeLight);
        digitalWrite(nAccPower, HIGH);
    }

    //If the ignition is off
    else if(digitalRead(nIgnOn) == LOW)
    {
        Timer1(0);
        DomeLight(ulTime, 0, nHatch, nLeftDoor, nRightDoor, nDomeLight);
        AccPower(nHatch, nLeftDoor, nRightDoor, nAccPower);
        digitalWrite(nHeadLights, LOW);
        digitalWrite(nParkingLights, LOW);
    }
}
