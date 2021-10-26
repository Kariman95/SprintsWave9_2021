#ifndef DIO_H_
#define DIO_H_

#include "Port.h"
#include "TM4C123GH6PM_HW.h"

typedef enum {PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F} enuDIOPortType_t;
typedef enum {PIN_LOW, PIN_HIGH} enuDIOLevelType_t;

enuDIOLevelType_t DIO_ReadChannel(enuPortPinType_t enuPortPinType);
void DIO_WriteChannel(enuPortPinType_t enuPortPinType, enuDIOLevelType_t enuDIOLevelType);
uint8_t DIO_ReadPort(enuDIOPortType_t enuDIOPortType);
void DIO_WritePort(enuDIOPortType_t enuDIOPortType, uint8_t u8PortLevel);
enuDIOLevelType_t DIO_FlipChannel(enuPortPinType_t enuPortPinType);

#endif /* DIO_H_ */
