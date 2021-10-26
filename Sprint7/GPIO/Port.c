#include "Port.h"


#define GPIO_PORT_NO(PIN_NO)                            (PIN_NO / 8)
#define GPIO_PIN_NO(PIN_NO)                             (PIN_NO % 8)

void Port_Init(const strPortConfigType_t* pstrPortConfigType)
{
    GPIOCR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    GPIOLOCK(5) = 0x4C4F434B;

    /* Pin Mode */
    if(pstrPortConfigType->enuPortPinModeType == ANALOG)
    {
        GPIOAMSEL(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else if(pstrPortConfigType->enuPortPinModeType == DIGITAL)
    {
        GPIODEN(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else
    {
        /* EXT INT */
    }
    /* Direction */
    if(pstrPortConfigType->enuPortPinDirectionType == PIN_INPUT)
    {
        GPIODIR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else
    {
        GPIODIR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    /* Internal Attach */
    if(pstrPortConfigType->enuPortPinInternalAttachType == PIN_PULL_UP)
    {
        GPIOPUR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else if(pstrPortConfigType->enuPortPinInternalAttachType == PIN_PULL_DOWN)
    {
        GPIOPDR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else if(pstrPortConfigType->enuPortPinInternalAttachType == PIN_OPEN_DRAIN)
    {
        GPIOODR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else
    {
        GPIOPUR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
        GPIOPDR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
        GPIOODR(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    /* Output Current */
    if(pstrPortConfigType->enuPortPinOutputCurrentType == CURRENT_2MA)
    {
        GPIODR2R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else if(pstrPortConfigType->enuPortPinOutputCurrentType == CURRENT_4MA)
    {
        GPIODR4R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else if(pstrPortConfigType->enuPortPinOutputCurrentType == CURRENT_8MA)
    {
        GPIODR8R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R |= (1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
    else
    {
        GPIODR2R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
        GPIODR4R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
        GPIODR8R(GPIO_PORT_NO(pstrPortConfigType->enuPortPinType)).R &= ~(1 << GPIO_PIN_NO(pstrPortConfigType->enuPortPinType));
    }
}
