#include "IntrCtrl.h"

#define IntrCtrl_GROUP_NUM	(2u)


const strINTCTRLConfigParameters_t strINTCTRLConfigParameters[IntrCtrl_GROUP_NUM]=
{
	{,GPIO_Port_A, IntrCtrl_ENABLE},
	{,GPIO_Port_B, IntrCtrl_ENABLE}
};