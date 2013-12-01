#include <Arduino.h>

void AccPower(int nHatch, int nLeftDoor, int nRightDoor, int nAccPower)
{
    //If a door is opened, turn off ACC power
    if (digitalRead(nHatch) || digitalRead(nLeftDoor) || digitalRead(nRightDoor) == HIGH)
    {
        digitalWrite(nAccPower, LOW);
    }
}
