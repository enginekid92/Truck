#include <Arduino.h>

void ParkLights(int nLightSensor, unsigned long ulTime, int nParkingLights)
{

    //Timing
    static unsigned long ulPrevTime = 5000;
    int nCheckInterval = 5000;

    //If time between checks has passed
    if ((ulTime - ulPrevTime) > nCheckInterval)
    {
        //Turn on parking lights if the ambiant light is low
        if (nLightSensor < 380)
        {
            digitalWrite(nParkingLights, HIGH);
        }
        //Turn off parking lights if the ambiant light is high
        else if (nLightSensor > 700)
        {
            digitalWrite(nParkingLights, LOW);
        }

        //Timing
        ulPrevTime = ulTime;
    }
}

