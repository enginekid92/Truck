#ifndef Functions_h
#define Functions_h

void ParkLights(int nLightSensor, unsigned long ulTime, int nParkingLights);
void HeadLights(int nHeadLights);
void DomeLight(unsigned long ulTime, int nIgnState, int nHatch, int nLeftDoor, int nRightDoor, int nDomeLight);
void AccPower(int nHatch, int nLeftDoor, int nRightDoor, int nACCPower);
int Timer1(int nIgnState);

#endif 