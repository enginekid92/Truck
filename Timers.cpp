#include <Arduino.h>

int Timer1(int nIgnState)
{
    //Setup
    static unsigned long ulPrevTime = 0;
    static unsigned long ulRuntime = 0;
    unsigned long ulTime = millis();

    //Incroment timer by 1 every second if Ign is on
    if (nIgnState == 1)
    {
        if (ulTime - ulPrevTime > 1000)
        {
        ulRuntime++;
        ulPrevTime = ulTime;
        }
    }

    //Reset timer to 0 if Ign is off
    if (nIgnState == 0)
    {
        ulRuntime = 0;
    }

    return ulRuntime;
}

int Timer2(int nReset)
{
    //Setup
    static unsigned long ulPrevTime = 0;
    static unsigned long ulRuntime = 0;
    unsigned long ulTime = millis();

    //Incroment timer by 1 every second if Ign is on
    if (nReset == 0)
    {
        if (ulTime - ulPrevTime > 1000)
        {
        ulRuntime++;
        Serial.println(ulRuntime);
        ulPrevTime = ulTime;
        }
    }

    //Reset timer to 0 if Ign is off
    if (nReset == 1)
    {
        ulRuntime = 0;
    }

    return ulRuntime;
}
