#include <Arduino.h>

//Import Timer
int Timer1(int nIgnState);

void HeadLights(int nHeadLights)
{
    //Turn on headlights when Ign has been on for 10 seconds
    if (Timer1(1) >= 10)
        digitalWrite(nHeadLights, HIGH);

    //Safeguard, make sure headlights are off until Ign has been on for 10 seconds
    else
        digitalWrite(nHeadLights, LOW);
}
