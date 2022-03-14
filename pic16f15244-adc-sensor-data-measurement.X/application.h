/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef APPLICATION_H
#define	APPLICATION_H

#include <xc.h>                                                              // Include processor files - each processor file is guarded.  
#include "mcc_generated_files/system/system.h"

/* 
 *      USER DEFINED VALUES
 */
#define BIT_SET             (1)
#define BIT_RESET           (0)
#define SETTLING_TIME       (2)
#define WAIT_TIME           (5000)
#define MAX_THRESHOLD       (800)
#define MIN_THRESHOLD       (300)
#define AVERAGE             (200)
#define ADC_CHANNEL         (0x0F)
#define BUZZER_ON_TIME      (3000)
#define READ_COUNT          (8)

/* 
 *      USER DEFINED FUNCTIONS
 */

/**
   @Param
    none
   @Returns
    none
   @Description
    Performs the alcohol detection functionality  
   @Example
    none
 */
void Sensor_Application(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Sets the timer flag when the 15 secs active period is completed, and interrupt occurs
   @Example
    none
 */

void TMR2_UserInterruptHandler(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Initialize the timer configuration for switch de-bouncing 
   @Example
    none
 */
void Init_TMR2_for_Debouncing(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Initialize the timer configuration for PWM 
   @Example
    none
 */
void Init_TMR2_for_PWM(void); 

/**
   @Param
    none
   @Returns
    none
   @Description
    Enables the PWM peripheral
   @Example
    none
 */
void PWM_Enable(void);

/**
   @Param
    none
   @Returns
    none
   @Description
    Disables the PWM peripheral
   @Example
    none
 */
void PWM_Disable(void);

#endif	/* APPLICATION_H */

