#include <Arduino.h>

//Import Timer
int Timer2 (int nReset);

void DomeLight(unsigned long ulTime, int nIgnState, int nHatch, int nLeftDoor, int nRightDoor, int nDomeLight)
{
    //Timing
    static unsigned long ulPrevTime = 0;
    int nDimRate = 6;

    //Setup
    static int nDomeLightBrightness = 0;

    //If the ignition is on
    if (nIgnState == 1)
    {
        //If one or more doors are opened
        if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == HIGH)
        {
            //Turn dome lamp on
            if ((ulTime - ulPrevTime) > nDimRate)
            {
                if (nDomeLightBrightness < 255)
                {
                    nDomeLightBrightness++;
                    analogWrite(nDomeLight, nDomeLightBrightness);
                }
                //Timing
                ulPrevTime = ulTime;
            }
        }
        //If one or more doors are closed
        if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == LOW)
        {
            //Turn dome lamp off
            if ((ulTime - ulPrevTime) > nDimRate)
            {
                if (nDomeLightBrightness > 0)
                {
                    nDomeLightBrightness--;
                    analogWrite(nDomeLight, nDomeLightBrightness);
                }
                //Timing
                ulPrevTime = ulTime;
            }
        }
    }

    //If the ignition is off
    if (nIgnState == 0)
    {
        //If one or more doors are opened
        if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == HIGH)
        {
            //Turn dome lamp on
            if ((ulTime - ulPrevTime) > nDimRate)
            {
                if (nDomeLightBrightness < 255)
                {
                    nDomeLightBrightness++;
                    analogWrite(nDomeLight, nDomeLightBrightness);
                }
                //Timing
                ulPrevTime = ulTime;
            }
            //Keep delay timer at 0 while doors are open
            if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == HIGH)
                Timer2(1);
        }

        //If one or more doors are closed
        if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == LOW)
        {
            //If doors have been closed longer than 30 seconds
            if (Timer2(0) >= 30)
            {
                //Turn dome lamp off
                if ((ulTime - ulPrevTime) > nDimRate)
                {
                    if (nDomeLightBrightness > 0)
                    {
                        nDomeLightBrightness--;
                        analogWrite(nDomeLight, nDomeLightBrightness);
                    }
                    //Timing
                    ulPrevTime = ulTime;
                }
            }
        }
    }
}
