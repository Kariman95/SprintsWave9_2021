#include "Port.h"
#include "DIO.h"
#include "MCU.h"


int main(void)
{
    //MCU_Init(&astrMCUConfigParameters[0]);
    //MCU_InitClock(MOSC);
    RCGCGPIO.B.R5 = HIGH;
    Port_Init(&astrPortConfigParameters[0]);
    DIO_WriteChannel(PF1, PIN_HIGH);
    while(1)
    {
    }
	return 0;
}
