
#include "Std_Types.h"
#include "IntCrtl.h"
#include "Mcu_Hw.h"

void IntrCtrl_Init(void)
{
	/* Set Priority Group and SubGroup */
	APINT.R = (APINT_VECTKEY << 16) | IntrCtrl_GROUP_SUBGROUP;
	
	#asm
	//switch to privileged
	
		//set primask
		__asm(" CPSIE I");
		//set faultmask
		__asm(" CPSIE F");
	#endasm
	 
	for(uint8 i=0; i<IntrCtrl_GROUP_NUM; i++)
	{
		/* Set priority for each interrupt */
		IPRx[i] = strINTCTRLConfigParameters[i].u8Priority<<5;
		
		if((strINTCTRLConfigParameters[i].enuIntCtrlNumber>=0)&&(strINTCTRLConfigParameters[i].enuIntCtrlNumber<=31))
		{
			if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_ENABLE)
			{
				/* Enable Interrupt */
				EN0_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
			else if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_DISABLE)
			{
				/* Disable Interrupt */
				DIS0_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
		}
		else if((strINTCTRLConfigParameters[i].enuIntCtrlNumber>=32)&&(strINTCTRLConfigParameters[i].enuIntCtrlNumber<=63))
		{
			if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_ENABLE)
			{
				/* Enable Interrupt */
				EN1_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
			else if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_DISABLE)
			{
				/* Disable Interrupt */
				DIS1_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
		}
		else if((strINTCTRLConfigParameters[i].enuIntCtrlNumber>=64)&&(strINTCTRLConfigParameters[i].enuIntCtrlNumber<=95))
		{
			if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_ENABLE)
			{
				/* Enable Interrupt */
				EN2_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
			else if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_DISABLE)
			{
				/* Disable Interrupt */
				DIS2_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
		}
		else if((strINTCTRLConfigParameters[i].enuIntCtrlNumber>=96)&&(strINTCTRLConfigParameters[i].enuIntCtrlNumber<=127))
		{
			if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_ENABLE)
			{
				/* Enable Interrupt */
				EN3_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
			else if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_DISABLE)
			{
				/* Disable Interrupt */
				DIS3_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
		}
		else if((strINTCTRLConfigParameters[i].enuIntCtrlNumber>=128)&&(strINTCTRLConfigParameters[i].enuIntCtrlNumber<=138))
		{
			if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_ENABLE)
			{
				/* Enable Interrupt */
				EN4_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
			else if(strINTCTRLConfigParameters[i].enuIntrCtrlStatus==IntrCtrl_DISABLE)
			{
				/* Disable Interrupt */
				DIS4_R=(1<<(strINTCTRLConfigParameters[i].enuIntCtrlNumber));
			}
		}
	}
	
}