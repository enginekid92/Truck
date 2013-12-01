#include <Arduino.h>

void ParkLights(int nLightSensor, unsigned long ulTime)
{

    //Timing
    static unsigned long ulPrevTime = 0;
    int nCheckInterval = 5000;

    //Setup
    static int nParkingLights = 13;
    pinMode(nParkingLights, OUTPUT);

    //Function
    if ((ulTime - ulPrevTime) > nCheckInterval)
    {
        if (nLightSensor < 380) //check if outside light level is low enough to turn on head lights
        {
            digitalWrite(nParkingLights, HIGH); //turn on head lights
        }
        else if (nLightSensor > 700) //check if outside light level is bright enough to turn off head lights
        {
            digitalWrite(nParkingLights, LOW); //turn off head lights
        }

        //Timing
        ulPrevTime = ulTime;
    }
}
