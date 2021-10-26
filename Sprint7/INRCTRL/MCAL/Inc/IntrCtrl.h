#ifndef IntCtrl_H_
#define IntCtrl_H_ 



typedef struct
{
	uint8_t					u8Priority;
	enuIntCtrlNumber_t		enuIntCtrlNumber;
	enuIntrCtrlStatus_t		enuIntrCtrlStatus;
	
}strINTCTRLConfigParameters_t;

extern strINTCTRLConfigParameters_t strINTCTRLConfigParameters;

void IntrCtrl_Init(void);


#endif /* IntCtrl_H_ */