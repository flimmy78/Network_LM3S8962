/****************************************Copyright (c)****************************************************
**                   Texas Instruments Semiconductor Technologies Co.,LTD.                              **
**                                                                                                      **                                     
**                                 http://www.ti.com                                                    **
**                                                                                                      **
**--------------File Info---------------------------------------------------------------------------------
** File Name:               Target.c                                                                    ** 
** Last modified Date:      12-20-2010                                                                  **
** Last Version:            1.0                                                                         **
** Description:             Initialization of the target board                                          **
**                                                                                                      **
**--------------------------------------------------------------------------------------------------------
** Created By:              long.luo                                                                    **
** Created date:            10-04-2013                                                                  **
** Version:                 1.0                                                                         **
** Descriptions:            The original version                                                        **
**                                                                                                      **
*********************************************************************************************************/

#include <includes.h>

stCurPhysics TargetInfo;

int ADC_EndFlag_3 = 0;

/*********************************************************************************************************
** Function name:           LedInit                                                                     **
** Descriptions:            Initialize the target board's leds,support up to 4 leds                     **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/          
#if (TARGET_LED_EN > 0) || (TARGET_LED1_EN > 0) || (TARGET_LED2_EN > 0) || (TARGET_LED3_EN > 0) || (TARGET_LED4_EN > 0)
void LedInit (void)
{
    volatile unsigned long ulLoop;
    
    #if TARGET_LED_EN > 0
     	SysCtlPeripheralEnable(LED_SYSCTL);
        GPIODirModeSet(LED_GPIO_PORT, LED_PIN, GPIO_DIR_MODE_OUT);
        GPIOPadConfigSet(LED_GPIO_PORT, LED_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
    
    #if TARGET_LED1_EN > 0
		SysCtlPeripheralEnable(LED1_SYSCTL);
		GPIODirModeSet(LED1_GPIO_PORT, LED1_PIN, GPIO_DIR_MODE_OUT);
		GPIOPadConfigSet(LED1_GPIO_PORT, LED1_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
    
    #if TARGET_LED2_EN > 0
        SysCtlPeripheralEnable(LED2_SYSCTL);
        GPIODirModeSet(LED2_GPIO_PORT, LED2_PIN, GPIO_DIR_MODE_OUT);
        GPIOPadConfigSet(LED2_GPIO_PORT, LED2_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif

    #if TARGET_LED3_EN > 0
        SysCtlPeripheralEnable(LED3_SYSCTL);
        GPIODirModeSet(LED3_GPIO_PORT, LED3_PIN, GPIO_DIR_MODE_OUT);
        GPIOPadConfigSet(LED3_GPIO_PORT, LED3_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif

    #if TARGET_LED4_EN > 0
        SysCtlPeripheralEnable(LED4_SYSCTL);
        GPIODirModeSet(LED4_GPIO_PORT, LED4_PIN, GPIO_DIR_MODE_OUT);
        GPIOPadConfigSet(LED4_GPIO_PORT, LED4_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
}
#endif


/*********************************************************************************************************
** Function name:           ledOn                                                                       **
** Descriptions:            Switch on one or all of the LEDs                                            **     
** input parameters:        led: The num.of led to be switched on, 1-4 for LED1-LED4,                   **
**                          0xFF for all leds, others no actio                                          **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if (TARGET_LED_EN > 0) || (TARGET_LED1_EN > 0) || (TARGET_LED2_EN > 0) || (TARGET_LED3_EN > 0) || (TARGET_LED4_EN > 0) 
void  LedOn (INT8U  ucLed)
{
    switch (ucLed) 
    {
		case 0:
			#if TARGET_LED_EN > 0
				GPIOPinWrite(LED_GPIO_PORT, LED_PIN, ~LED_PIN);
			#endif
		break;

        case 1: 
            #if TARGET_LED1_EN > 0
				GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, ~LED1_PIN);
            #endif
            break;
      
        case 2:
            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, ~LED2_PIN);
            #endif
            break;
    
        case 3:
            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, ~LED3_PIN);
            #endif
            break;
    
        case 4:
            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, ~LED4_PIN);
            #endif
            break;
	        	
        case 0xFF:
	        #if TARGET_LED_EN > 0
	        	GPIOPinWrite(LED_GPIO_PORT, LED_PIN, ~LED_PIN);
			#endif
        
            #if TARGET_LED1_EN > 0
				GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, ~LED1_PIN);
            #endif

            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, ~LED2_PIN);
            #endif

            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, ~LED3_PIN);
            #endif

            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, ~LED4_PIN);
            #endif
            break;
       
        default:
            break;
    }
}
#endif


/*********************************************************************************************************
** Function name:           ledOff                                                                      **
** Descriptions:            Switch off one or all of the LEDs                                           **     
** input parameters:        led: The num.of led to be switched off, 1-4 for LED1-LED4,                  **
**                          0xFF for all leds, others no actio                                          **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if (TARGET_LED_EN > 0) || (TARGET_LED1_EN > 0) || (TARGET_LED2_EN > 0) || (TARGET_LED3_EN > 0) || (TARGET_LED4_EN > 0)
void  LedOff (INT8U  ucLed)
{
    switch (ucLed) 
    {
        case 0:
        	#if TARGET_LED_EN > 0
        		GPIOPinWrite(LED_GPIO_PORT, LED_PIN, LED_PIN);
        	#endif
        	break;

        case 1: 
            #if TARGET_LED1_EN > 0
      	        GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, LED1_PIN);
            #endif
            break;
      
        case 2:
            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, LED2_PIN);
            #endif
            break;
    
        case 3: 
            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, LED3_PIN);
            #endif
            break;

        case 4: 
            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, LED4_PIN);
            #endif
            break;

        case 0xFF:
	        #if TARGET_LED_EN > 0
      	        GPIOPinWrite(LED_GPIO_PORT, LED_PIN, LED_PIN);
	        #endif
        
            #if TARGET_LED1_EN > 0
      	        GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, LED1_PIN);
            #endif

            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, LED2_PIN);
            #endif

            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, LED3_PIN);
            #endif

            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, LED4_PIN);
            #endif
            break;
       
        default:
            break;
    }
}
#endif


/*********************************************************************************************************
** Function name:           ledToggle                                                                   **
** Descriptions:            Toggle one or all of the LEDs                                               **     
** input parameters:        led: The num.of led to be toggled, 1-4 for LED1-LED4,                       **
**                          0xFF for all leds, others no actio                                          **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if (TARGET_LED_EN > 0) || (TARGET_LED1_EN > 0) || (TARGET_LED2_EN > 0) || (TARGET_LED3_EN > 0) || (TARGET_LED4_EN > 0)
void  LedToggle (INT8U  ucLed)
{
    unsigned long PinVal =0;

    switch (ucLed) 
    {
       	case 0:
            #if TARGET_LED_EN > 0
    	        GPIOPinWrite(LED_GPIO_PORT, LED_PIN, ~GPIOPinRead(LED_GPIO_PORT, LED_PIN));
	        #endif
            break;

        case 1: 
            #if TARGET_LED1_EN > 0
				GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, ~GPIOPinRead(LED1_GPIO_PORT, LED1_PIN));
            #endif
            break;
      
        case 2:
            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, ~GPIOPinRead(LED2_GPIO_PORT, LED2_PIN));
            #endif
            break;
    
        case 3:
            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, ~GPIOPinRead(LED3_GPIO_PORT, LED3_PIN));
            #endif
            break;

        case 4:
            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, ~GPIOPinRead(LED4_GPIO_PORT, LED4_PIN));
            #endif
            break;
            
        case 0xFF:
	        #if TARGET_LED_EN > 0
    	        GPIOPinWrite(LED_GPIO_PORT, LED_PIN, ~GPIOPinRead(LED_GPIO_PORT, LED_PIN));
	        #endif
        
            #if TARGET_LED1_EN > 0
	  	        GPIOPinWrite(LED1_GPIO_PORT, LED1_PIN, ~GPIOPinRead(LED1_GPIO_PORT, LED1_PIN));
            #endif

            #if TARGET_LED2_EN > 0
                GPIOPinWrite(LED2_GPIO_PORT, LED2_PIN, ~GPIOPinRead(LED2_GPIO_PORT, LED2_PIN));
            #endif

            #if TARGET_LED3_EN > 0
                GPIOPinWrite(LED3_GPIO_PORT, LED3_PIN, ~GPIOPinRead(LED3_GPIO_PORT, LED3_PIN));
            #endif

            #if TARGET_LED4_EN > 0
                GPIOPinWrite(LED4_GPIO_PORT, LED4_PIN, ~GPIOPinRead(LED4_GPIO_PORT, LED4_PIN));
            #endif
            break;
          
        default:
            break;
    }
}
#endif


/*********************************************************************************************************
** Function name:           BuzInit                                                                     **
** Descriptions:            Initialize the target board's buzzer                                        **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if TARGET_BUZ_EN > 0
void BuzInit (void)
{	
	SysCtlPeripheralEnable(BUZ_SYSCTL);
    GPIODirModeSet(BUZ_GPIO_PORT, BUZ_PIN, GPIO_DIR_MODE_OUT);
    GPIOPadConfigSet(BUZ_GPIO_PORT, BUZ_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    BuzOff();
}
#endif


/*********************************************************************************************************
** Function name:           BuzOn                                                                       **
** Descriptions:            Switch on the buzzer                                                        **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if TARGET_BUZ_EN > 0
void  BuzOn (void)
{
    GPIOPinWrite(BUZ_GPIO_PORT, BUZ_PIN, ~BUZ_PIN);
}
#endif


/*********************************************************************************************************
** Function name:           BuzOff
** Descriptions:            Switch off the buzzer 
** Input parameters:        None 
** Output parameters:       None 
** Returned value:          None 
** Created by:              long.luo
** Created Date:            2013.04.12
*********************************************************************************************************/
#if TARGET_BUZ_EN > 0
void  BuzOff (void)
{
    GPIOPinWrite(BUZ_GPIO_PORT, BUZ_PIN, BUZ_PIN);
}
#endif


/*********************************************************************************************************
** Function name:           BuzToggle                                                                   **
** Descriptions:            Toggle the buzzer                                                           **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if TARGET_BUZ_EN > 0
void BuzToggle (void)    
{
    GPIOPinWrite(BUZ_GPIO_PORT, BUZ_PIN, ~GPIOPinRead(BUZ_GPIO_PORT, BUZ_PIN));
}
#endif


/*********************************************************************************************************
** Function name:           BuzFrequency                                                                **
** Descriptions:            Set the buzzer's Frequency                                                  **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          none                                                                        **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            12-04-2013                                                                  **
*********************************************************************************************************/
#if TARGET_BUZ_EN > 0
void BuzFrequency (INT32U ulFrequency)
{	
	//TargetInfo.stPWM.ulFrequency = ulFrequency;
	SetPWMFrequency(ulFrequency);
}
#endif


/*********************************************************************************************************
** Function name:           PWMInit                                                                     **
** Descriptions:            Initialize the target board's PMW                                           **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            14-04-2013                                                                  **
*********************************************************************************************************/
#if TARGET_PWM_EN > 0
void PWMInit(void)
{	
    // Enable the PWM generator.
    SysCtlPeripheralEnable(PWM_SYSCTL);
    
    // Configure the PWM generator for count down mode with immediate updates
    // to the parameters.
    PWMGenConfigure(PWM_BASE, PWM_GEN_0,
                    PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

	// Divide the PWM clock by 4.
    SysCtlPWMClockSet(SYSCTL_PWMDIV_4); 

	// Get the PWM clock.
	TargetInfo.stPWM.ulPWMClock = SysCtlClockGet() / 4;

	// Start the timers in generator 0.
    PWMGenEnable(PWM_BASE, PWM_GEN_0);
}
#endif


/************************************************************************************
** Function: SetPWMState()
** Routine Description: - 
**      Enable or disable the PWM1 output.  
** Input parameters: - 
**    NONE 
** Output parameters: NONE
** Returned Value: NONE
** Remarks:
** 
** Date created: 23:12:17,27/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_PWM_EN > 0
void SetPWMState(tBoolean bOn)
{
    // Enable or disable the PWM1 output. 
	PWMOutputState(PWM_BASE, PWM_OUT_1_BIT, bOn); 
}
#endif


/************************************************************************************
** Function: SetPWMFrequency()
** Routine Description: - 
**     Set PWM Frequency 
** Input parameters: unsigned long Frequency
** Output parameters: NONE
** Returned Value: NONE
** Remarks:
** 
** Date created: 21:13:03,21/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_PWM_EN > 0
void SetPWMFrequency(INT32U ulFrequency)
{
	// Set the global frequency
	TargetInfo.stPWM.ulFrequency = ulFrequency;

	// Set the period.
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, TargetInfo.stPWM.ulPWMClock / TargetInfo.stPWM.ulFrequency);

	// Set the pulse width of PWM1
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, 
				((TargetInfo.stPWM.ulPWMClock * TargetInfo.stPWM.ulDutyCycle) / 100) / TargetInfo.stPWM.ulFrequency);	
}
#endif


/************************************************************************************
** Function: SetPWMDutyCycle()
** Routine Description: - 
**     Set PWM Duty Cycle 
** Input parameters: unsigned long ulDutyCycle
** Output parameters: NONE
** Returned Value: NONE
** Remarks:
** 
** Date created: 21:52:28,21/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_PWM_EN > 0
void SetPWMDutyCycle(INT32U ulDutyCycle)
{
	// Set the global duty cycle
	TargetInfo.stPWM.ulDutyCycle = ulDutyCycle;

	// Set the period.
	PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, TargetInfo.stPWM.ulPWMClock / TargetInfo.stPWM.ulFrequency);

	// Set the pulse width of PWM1
	PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, 
				((TargetInfo.stPWM.ulPWMClock * TargetInfo.stPWM.ulDutyCycle) / 100) / TargetInfo.stPWM.ulFrequency);
}
#endif


/*********************************************************************************************************
** Function name:           keyInit                                                                     **
** Descriptions:            Initialize the target board's keys,support up to 4 keys                     **     
** input parameters:        None                                                                        **
** output parameters:       none                                                                        **
** Returned value:          8-bit unsigned char data. Bit0-bit3 stand for the status of Key1-Key4,      **
**                          bit4-Bit7 no meaning                                                        **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if (TARGET_KEY1_EN > 0) ||  (TARGET_KEY2_EN > 0) || (TARGET_KEY3_EN > 0) || (TARGET_KEY4_EN > 0)
   || (TARGET_KEY_SELECT_EN > 0) || (TARGET_KEY_UP_EN > 0) || (TARGET_KEY_DOWN_EN > 0) || (TARGET_KEY_LEFT_EN > 0) ||  (TARGET_KEY_RIGHT_EN > 0)
void keyInit (void)    
{
    #if TARGET_KEY1_EN > 0
        SysCtlPeripheralEnable(KEY1_SYSCTL);
        GPIODirModeSet(KEY1_GPIO_PORT, KEY1_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY1_GPIO_PORT, KEY1_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif  
    
    #if TARGET_KEY2_EN > 0
        SysCtlPeripheralEnable(KEY2_SYSCTL);
        GPIODirModeSet(KEY2_GPIO_PORT, KEY2_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY2_GPIO_PORT, KEY2_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif      

    #if TARGET_KEY3_EN > 0
        SysCtlPeripheralEnable(KEY3_SYSCTL);
        GPIODirModeSet(KEY3_GPIO_PORT, KEY3_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY3_GPIO_PORT, KEY3_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif    

    #if TARGET_KEY4_EN > 0
        SysCtlPeripheralEnable(KEY4_SYSCTL);
        GPIODirModeSet(KEY4_GPIO_PORT, KEY4_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY4_GPIO_PORT, KEY4_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif    
    
	#if TARGET_KEY_SELECT_EN > 0
		SysCtlPeripheralEnable(KEY_SELECT_SYSCTL);
        GPIODirModeSet(KEY_SELECT_GPIO_PORT, KEY_SELECT_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY_SELECT_GPIO_PORT, KEY_SELECT_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif	
    
	#if TARGET_KEY_UP_EN > 0
		SysCtlPeripheralEnable(KEY_UP_SYSCTL);
        GPIODirModeSet(KEY_UP_GPIO_PORT, KEY_UP_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY_UP_GPIO_PORT, KEY_UP_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
    
    #if TARGET_KEY_DOWN_EN > 0
		SysCtlPeripheralEnable(KEY_DOWN_SYSCTL);
        GPIODirModeSet(KEY_DOWN_GPIO_PORT, KEY_DOWN_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY_DOWN_GPIO_PORT, KEY_DOWN_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
    
    #if TARGET_KEY_LEFT_EN > 0
		SysCtlPeripheralEnable(KEY_LEFT_SYSCTL);
        GPIODirModeSet(KEY_LEFT_GPIO_PORT, KEY_LEFT_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY_LEFT_GPIO_PORT, KEY_LEFT_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif
    
    #if TARGET_KEY_RIGHT_EN > 0
		SysCtlPeripheralEnable(KEY_RIGHT_SYSCTL);
        GPIODirModeSet(KEY_RIGHT_GPIO_PORT, KEY_RIGHT_PIN, GPIO_DIR_MODE_IN);
        GPIOPadConfigSet(KEY_RIGHT_GPIO_PORT, KEY_RIGHT_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
    #endif        
}
#endif


/*********************************************************************************************************
** Function name:           keyRead                                                                     **
** Descriptions:            Read the status of the keys.                                                **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            11-04-2013                                                                  **
*********************************************************************************************************/
#if (TARGET_KEY1_EN > 0) ||  (TARGET_KEY2_EN > 0) || (TARGET_KEY3_EN > 0) || (TARGET_KEY4_EN > 0)
   || (TARGET_KEY_SELECT_EN > 0) || (TARGET_KEY_UP_EN > 0) || (TARGET_KEY_DOWN_EN > 0) || (TARGET_KEY_LEFT_EN > 0) ||  (TARGET_KEY_RIGHT_EN > 0)
INT8U keyRead (void)
{
    INT8U ucTemp;
    ucTemp = 0xFF;

    #if TARGET_KEY1_EN > 0
        if (!GPIOPinRead(KEY1_GPIO_PORT, KEY1_PIN)) 
        {
            ucTemp &= 0xFE;  
        }
    #endif

    #if TARGET_KEY2_EN > 0
        if (!GPIOPinRead(KEY2_GPIO_PORT, KEY2_PIN)) 
        { 
            ucTemp &= 0xFD; 
        }
    #endif
    
    #if TARGET_KEY3_EN > 0
        if (!GPIOPinRead(KEY3_GPIO_PORT, KEY3_PIN)) 
        {
            ucTemp &= 0xFB; 
        }
    #endif

    #if TARGET_KEY4_EN > 0
		if (!GPIOPinRead(KEY4_GPIO_PORT, KEY4_PIN)) 
		{
		    ucTemp &= 0xF7; 
		}
	#endif  
        
    #if TARGET_KEY_SELECT_EN > 0
        if (!GPIOPinRead(KEY_SELECT_GPIO_PORT, KEY_SELECT_PIN)) 
    	{
			//ucTemp &= 0xF7; 
		}
        #endif
     
    #if TARGET_KEY_UP_EN > 0
        if (!GPIOPinRead(KEY_UP_GPIO_PORT, KEY_UP_PIN)) 
        {
            ucTemp &= 0xF7; 
        }
    #endif

    #if TARGET_KEY_DOWN_EN > 0
        if (!GPIOPinRead(KEY_DOWN_GPIO_PORT, KEY_DOWN_PIN)) 
        {
            ucTemp &= 0xF7; 
        }
    #endif
    
     #if TARGET_KEY_LEFT_EN > 0
        if (!GPIOPinRead(KEY_LEFT_GPIO_PORT, KEY_LEFT_PIN)) 
        {
            ucTemp &= 0xF7; 
        }
    #endif
    
    #if TARGET_KEY_RIGHT_EN > 0
        if (!GPIOPinRead(KEY_RIGHT_GPIO_PORT, KEY_RIGHT_PIN)) 
        {
            ucTemp &= 0xF7; 
        }
    #endif
    
	return(ucTemp);
}
#endif


/************************************************************************************
** Function: DispInit
** Routine Description: - 
**     Init the display 
** Input parameters: 
** Output parameters: 
** Returned Value: NONE
** Remarks:
** 
** Date created: 22:07:09,21/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_DISP_EN > 0
void DispInit(INT32U ulFrequency)
{
	RIT128x96x4Init(ulFrequency);
}
#endif


/************************************************************************************
** Function: DispEnable()
** Routine Description: - 
**     display 
** Input parameters: - 
** 		ulFrequency
** Output parameters: NONE
** Returned Value: NONE
** Remarks:
** 
** Date created: 21:46:21,22/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_DISP_EN > 0
void DispEnable(INT32U ulFrequency)
{
    RIT128x96x4Enable(ulFrequency);
}
#endif


/************************************************************************************
** Function: DispDisable()
** Routine Description: - 
**     1.0 
** Input parameters: - 
** 		NONE
** Output parameters: NONE
** Returned Value: NONE
** Remarks:
** 
** Date created: 21:48:27,22/05/2012
** Author: Long.Luo
************************************************************************************/
#if TARGET_DISP_EN > 0
void DispDisable(void)
{
	RIT128x96x4Disable();
}
#endif


/*********************************************************************************************************
** Function name:           timer0AInit                                                                 **
** Descriptions:            Initialize Timer0A to 32bit timeout                                         **     
** input parameters:        Tick: Number of timeout tick                                                **
**                          Prio: Interrupt priority                                                    **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
#if TARGET_TMR0A_EN > 0
void timer0AInit (INT32U  ulTick, INT8U  ucPrio)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_32_BIT_PER);
    TimerLoadSet(TIMER0_BASE, TIMER_A, ulTick);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    IntEnable(INT_TIMER0A);
    IntPrioritySet(INT_TIMER0A, ucPrio);
    TimerEnable(TIMER0_BASE, TIMER_A);        
}
#endif


/*********************************************************************************************************
** Function name:           timer0AISR                                                                  **
** Descriptions:            Timeout interrupt handler of Timer0A                                        **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
#if TARGET_TMR0A_EN > 0
void timer0AISR (void)
{
    /*
    *  Optional Code. If you don't call any uC/OS-II's functions & variables, 
    *  this code can be cancelled.
    */ 
    #if 0
        #if OS_CRITICAL_METHOD == 3
            OS_CPU_SR cpu_sr;
        #endif 

        OS_ENTER_CRITICAL();                       
        OSIntNesting++;
        OS_EXIT_CRITICAL();
    #endif 
  
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);                 /*  Clear the interrupt flag.   */
  
    /*
     *  Add you initialization code here.
     */
    /*
     *  Optional Code. If you don't call any uC/OS-II's functions & variables, this code can be 
     *  cancelled.
     */ 
    #if 0 
        OSIntExit();
    #endif                                  
}
#endif


/*********************************************************************************************************
** Function name:           InitTick                                                                    **
** Descriptions:            Initialize uC/OS-II's tick source(system timer)��                           **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
static void InitTick(void)
{
    SysTickPeriodSet((INT32U)(SysCtlClockGet() / OS_TICKS_PER_SEC) -1 );
    SysTickEnable();
    SysTickIntEnable();
}


/*********************************************************************************************************
** Function name:           tickISRHandler                                                              **
** Descriptions:            Timeout interrupt handler of system timer                                   **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
void  tickISRHandler (void)
{
    #if OS_CRITICAL_METHOD == 3
        OS_CPU_SR cpu_sr;
    #endif 

    OS_ENTER_CRITICAL();                         
    OSIntNesting++;
    OS_EXIT_CRITICAL();

    OSTimeTick();                                                       /*  Call uC/OS-II's OSTimeTick()*/

    OSIntExit();                                 
}


/*********************************************************************************************************
** Function name:           InvertTemperature                                                           **
** Descriptions:            Invert the temperature                                                      **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            12-04-2013                                                                  **
*********************************************************************************************************/ 
#if TARGET_ADC_EN > 0
INT32U InvertTemperature(INT32U ulValue)
{
    INT32U ulTemp;
    //char cBuf[40];
    ulTemp = 151040UL - 225 * ulValue;
    
    return ulTemp;
}
#endif


/*********************************************************************************************************
** Function name:           InitADC                                                                  **
** Descriptions:            Initialize the ADC board                                                 **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
#if TARGET_ADC_EN > 0
void InitADC(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC);
    SysCtlADCSpeedSet(SYSCTL_ADCSPEED_125KSPS);
    ADCSequenceDisable(ADC_BASE,3);

    ADCSequenceConfigure(ADC_BASE,3,ADC_TRIGGER_PROCESSOR,0);
    ADCSequenceStepConfigure(ADC_BASE,3,0,ADC_CTL_TS |ADC_CTL_END|ADC_CTL_IE);

    ADCIntEnable(ADC_BASE,3);
    IntEnable(INT_ADC3);
    IntMasterEnable();

    ADCSequenceEnable(ADC_BASE,3);
}
#endif


/*********************************************************************************************************
** Function name:           ADCSample                                                                   **
** Descriptions:            Initialize the target board                                                 **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
#if TARGET_ADC_EN > 0
INT32U ADCSample(void)
{
    INT32U ulValue = 0;

    ADCProcessorTrigger(ADC_BASE,3);
    while(!ADC_EndFlag_3);
    
    ADC_EndFlag_3 = false; 
    ADCSequenceDataGet(ADC_BASE,3,&ulValue);
    
    return (ulValue);
}
#endif


/*****************************************************************************************
* Function Name   : ADC3IntHandler                                                       *
* Description     :                                                                      *
* Input Argument  :                                                                      *
* Output          :                                                                      *
* Return          :                                                                      *
==========================================================================================
** Created by:              long.luo                                                    **
** Created Date:            10-04-2013                                                  **
*****************************************************************************************/ 
#if TARGET_ADC_EN > 0
void ADC3IntHandler(void)
{
    unsigned long ulStatus;

    ulStatus = ADCIntStatus(ADC_BASE, 3, true);  // Get ADC interrupt Status
    ADCIntClear(ADC_BASE, 3);                    //  Clear Interrupt Status

    if (0 != ulStatus)
    {
        ADC_EndFlag_3 = true;
    }         
}
#endif


/*********************************************************************************************************
** Function name:           InitTarget                                                                  **
** Descriptions:            Initialize the target board                                                 **     
** input parameters:        none                                                                        **
** output parameters:       none                                                                        **
** Returned value:          noe                                                                         **
==========================================================================================================
** Created by:              long.luo                                                                    **
** Created Date:            10-04-2013                                                                  **
*********************************************************************************************************/ 
void  InitTarget (void)
{
    //uint32 i = 0;
    
    // SysCtlLDOSet(SYS_LDO);                                      /* Set LDO Output 2.50v         */  
    SysCtlLDOSet(SYSCTL_LDO_2_75V);

    #if PLL_EN == 0                                             /*  Not use PLL                         */ 
        SysCtlClockSet(CCLK_DIV | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | EXT_CLK); 
    #else                                                       /*  Use PLL                             */  
        SysCtlClockSet(CCLK_DIV | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | EXT_CLK); 
    #endif
  
    InitTick();                                                 /*  Initialize the uC/OS-II tick        */ 
                                                                /*  interrupt,using the Kernal's timer  */    

    //TargetInfo.uVcc = 0;
    //TargetInfo.uTemp = 0;

    //TargetInfo.stADC.ADC_EN = 0x00000000;
    //for (i = 0; i < MAX_ADC_CHN; i++)
    //{
    //    TargetInfo.stADC.ADC_CH[i] = 0x0000;
    //}

    
    LedInit();
    BuzInit();
    InitADC();
    //keyInit();     
}


/*********************************************************************************************************
  END FILE 
*********************************************************************************************************/

