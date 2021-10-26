#include "DIO.h"


#define GPIO_PORT_NO(PIN_NO)                            (PIN_NO / 8)
#define GPIO_PIN_NO(PIN_NO)                             (PIN_NO % 8)
#define GPIO_PORT_MASK                                  0xFF
#define ASSIGN_BIT(REG, BIT_NO, VALUE)                  (REG = ((REG & ~(1 << BIT_NO)) | (VALUE << BIT_NO)))


enuDIOLevelType_t DIO_ReadChannel(enuPortPinType_t enuPortPinType)
{
    enuDIOLevelType_t enuDIOLevelType;

    enuDIOLevelType = (enuDIOLevelType_t)GPIODATA(GPIO_PORT_NO(enuPortPinType), GPIO_PIN_NO(enuPortPinType)).R;
    return enuDIOLevelType;
}

void DIO_WriteChannel(enuPortPinType_t enuPortPinType, enuDIOLevelType_t enuDIOLevelType)
{
    ASSIGN_BIT(GPIODATA(GPIO_PORT_NO(enuPortPinType), GPIO_PIN_NO(enuPortPinType)).R, GPIO_PIN_NO(enuPortPinType), enuDIOLevelType);
}

uint8_t DIO_ReadPort(enuDIOPortType_t enuDIOPortType)
{
    uint8_t u8DIOPortLevelType;

    u8DIOPortLevelType = (enuDIOLevelType_t)GPIODATA(enuDIOPortType, GPIO_PORT_MASK).R;
    return u8DIOPortLevelType;
}

void DIO_WritePort(enuDIOPortType_t enuDIOPortType, uint8_t u8PortLevel)
{
    GPIODATA(enuDIOPortType, GPIO_PORT_MASK).R = u8PortLevel;
}

enuDIOLevelType_t DIO_FlipChannel(enuPortPinType_t enuPortPinType)
{
    enuDIOLevelType_t enuDIOLevelType;

    enuDIOLevelType = (enuDIOLevelType_t)GPIODATA(GPIO_PORT_NO(enuPortPinType), GPIO_PIN_NO(enuPortPinType)).R;
    GPIODATA(GPIO_PORT_NO(enuPortPinType), GPIO_PIN_NO(enuPortPinType)).R = ~enuDIOLevelType;
    return enuDIOLevelType;
}



