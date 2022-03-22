/*
 * File:   application.c
 * Author: I62418
 *
 * Created on July 1, 2021, 10:26 AM
 */


#include <xc.h>                                                              // Include processor files - each processor file is guarded.
#include "mcc_generated_files/system/system.h"
#include "application.h"

/*
 ***********************************************************
 *                                                         *
 *              User Defined Structure                     *
 *                                                         *
 ***********************************************************
*/

typedef enum {
    RELEASED,
    PRESSED,
    STATE_READ
}buttonState_t;
buttonState_t button = STATE_READ;

/*
 ***********************************************************
 *                                                         *
 *              User Defined Variables                     *
 *                                                         *
 ***********************************************************
*/

bool timer_flag;
uint16_t sensor_value;

/*
 ***********************************************************
 *                                                         *
 *          User Defined Function Definitions              *
 *                                                         *
 ***********************************************************
*/

void Sensor_Application(void) 
{
    if (button == PRESSED)
    {
        button = STATE_READ;                                                 // Reset the switch mode to STATE_READ
        printf("\n\t Device has woke up from sleep mode");
        printf("\n\t Place the cotton ball in front of the alcohol sensor");
        __delay_ms(SETTLING_TIME);
        timer_flag = true;
    }
    if(timer_flag)
    {
        Init_TMR2_for_PWM();                                                 // Initialize TMR2 for PWM functionality
        __delay_ms(WAIT_TIME);
        sensor_value = ADC_GetConversion(ADC_CHANNEL);
        if(sensor_value > MIN_THRESHOLD)                                     // Check if the alcohol presence is in excess
        {
            printf("\n\t Value is = %d", sensor_value);
            PWM_Enable();
            printf("\n\t Alcohol Presence detected\n");
            __delay_ms(BUZZER_ON_TIME);
            PWM_Disable();  
        }
        else      // Default test to deny the alcohol presence
        {
            printf("\n\t Value is = %d", sensor_value);
            printf("\n\t No alcohol presence detected\n");
            __delay_ms(SETTLING_TIME);
        }        
        timer_flag = false;
        Init_TMR2_for_Debouncing();                                          // Re-initialize timer for switch de-bouncing
        SLEEP();
    }
}

void Init_TMR2_for_Debouncing(void)                                          // Initialize Timer 2 for switch de-bouncing, period 100 ms
{
    // Set TMR2 to the options selected in the User Interface
    
    // T2CS LFINTOSC;
    T2CLKCON = 0x04;                                                         
    
    // T2PSYNC Not Synchronized; T2MODE Starts on rising edge on TMR2_ers; T2CKPOL Rising Edge; T2CKSYNC Not Synchronized;
    T2HLT = 0x11;                                                           
    
    // T2RSEL T2INPPS pin;
    T2RST = 0x00;              
    
    // T2PR 11;
    T2PR = 0x0B;  
    
    // TMR2 0;
    T2TMR = 0x00;                                                             
    
    // Clearing IF flag before enabling the interrupt
    PIR1bits.TMR2IF = 0;                             
    
    // Enabling TMR2 interrupt
    PIE1bits.TMR2IE = 1;                                                     
    
    // Set Default Interrupt Handler
    Timer2_OverflowCallbackRegister(TMR2_UserInterruptHandler);                     
    
    // T2CKPS 1:128; T2OUTPS 1:1; TMR2ON on;
    T2CON = 0xF0;                                                             
}

void Init_TMR2_for_PWM(void)                                                 // Set TMR2 to the options selected below for initializing it for PWM
{
    Timer2_Initialize();                                                       // Initialize timer to default settings
    PIE1bits.TMR2IE = BIT_RESET;                                             // Disable Interrupt as PWM does not require interrupt
}

void PWM_Enable(void)
{
    PWM3CONbits.EN = BIT_SET;                                             
}

void PWM_Disable(void)
{
    PWM3CONbits.EN = BIT_RESET;                                     
}

void TMR2_UserInterruptHandler(void)                                         // User defined interrupt function to detect switch press
{
    button = PRESSED;
}