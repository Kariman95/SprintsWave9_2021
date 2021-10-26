#ifndef PORT_H_
#define PORT_H_

#include "Port_Cfg.h"
#include "TM4C123GH6PM_HW.h"

typedef enum {PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7,
              PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7,
              PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7,
              PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7,
              PE0, PE1, PE2, PE3, PE4, PE5,
              PF0 = 40, PF1, PF2, PF3, PF4} enuPortPinType_t;
//typedef enum {IO, ALTERNATE_FUNCTION} enuPortPinType_t;
typedef enum {PIN_INPUT, PIN_OUTPUT} enuPortPinDirectionType_t;
typedef enum {DIGITAL, ANALOG, EXTERNAL_INTERRUPT} enuPortPinModeType_t;
typedef enum {PIN_DEFAULT, PIN_PULL_UP, PIN_PULL_DOWN, PIN_OPEN_DRAIN} enuPortPinInternalAttachType_t;
typedef enum {CURRENT_DEFAULT, CURRENT_2MA, CURRENT_4MA, CURRENT_8MA} enuPortPinOutputCurrentType_t;

typedef struct
{
    enuPortPinType_t enuPortPinType;
    enuPortPinModeType_t enuPortPinModeType;
    enuPortPinDirectionType_t enuPortPinDirectionType;
    enuPortPinInternalAttachType_t enuPortPinInternalAttachType;
    enuPortPinOutputCurrentType_t enuPortPinOutputCurrentType;
} strPortConfigType_t;

extern const strPortConfigType_t astrPortConfigParameters[PORT_GROUPS_NO];

void Port_Init(const strPortConfigType_t* pstrPortConfigType);

#endif /* PORT_H_ */
