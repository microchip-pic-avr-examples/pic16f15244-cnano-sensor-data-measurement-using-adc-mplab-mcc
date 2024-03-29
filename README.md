<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Sensor Data Measurement using PIC16F15244 Microcontroller

This example demonstrates sensor data measurement i.e. acquiring and processing the sensor raw data using the built in Analog-to-Digital Converter (ADC) and timer peripherals of the PIC^®^ microcontroller.

## Introduction

The PIC16F152xx family of microcontrollers are equipped with ADCs with 10-bit resolution and option to provide up to 28 external and two internal channels, an 8-bit timer with hardware limit timer and two Capture/Compare/PWM (CCP) modules with 10-bit resolution Pulse Width Modulation (PWM) mode and Enhanced Universal Synchronous Asynchronous Receiver Transmitter (EUSART). This example describes the implementation of an alcohol sensor data measurement using the ADC peripheral of PIC16F15244 MCU. The EUSART peripheral is used to display the test results on the terminal window. On performing the sensor data measurement, the alcohol detection, the result on the terminal window, if the presence of alcohol is detected. PWM is used to enable the buzzer along with the result on terminal window if presence of alcohol is detected.

## Related Links

- [PIC16F15244 Product Page](https://www.microchip.com/wwwproducts/en/PIC16F15244 "PIC16F15244 Product Page")
- [PIC16F15244 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples "PIC16F15244 Code Examples on GitHub")
- [PIC16F152xx MCU Family Video](https://youtu.be/nHLv3Th-o-s "PIC16F15244 MCU Family Video")
- [PIC16F152xx MCU Product Family Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f15244 "PIC16F15244 Product Family Page")
- [TB3250 - Using PWM to Generate an Analog Output](https://ww1.microchip.com/downloads/en/Appnotes/90003250A.pdf "TB3250 - Using PWM to Generate an Analog Output")

## Description

In real time applications, ADC is required to convert the analog sensor data to digital value and analyze the data readings. Most of the environmental parameters such as temperature, sound, pressure, light, gas levels, etc., are measurable in analog form only. In the alcohol detection system, analog signal from the alcohol sensor is acquired using ADC and analyzed for alcohol presence.

<p align="center">
  <img width=600 height=auto src="images/blk_diag.png">
  <br>Figure 1: System Block Diagram <br>
</p>

* In this example, PIC16F15244 Curiosity Nano board, Alcohol Click and BUZZ 2 Click from MikroElektronika are used for demonstrating sensor data measurement using the ADC peripheral
* MCU sleep feature is used to demonstrate low-power usage 
* Press the switch to start the ADC measurement. THE HLT mode of the timer is used for switch debouncing.
* The data from the sensor is acquired in terms of analog values, which is then compared with the threshold values. If the sensor output detected exceed the threshold value, then alcohol presence is detected. 
* The results of the test are displayed on the terminal window, along with buzzer indication using PWM. After completing the cycle, the MCU enters Sleep mode again.

## Alcohol Detection

Alcohol Click has a high sensitivity to alcohol and it can be used to detect alcohol in concentrations from 0.04 to 4mg/l. Alcohol Click carries an MQ-3 Semiconductor sensor for alcohol. The gas sensing layer on the sensor unit is made of Tin dioxide (SnO2), an inorganic compound which has lower conductivity in clean air. The conductivity increases as the levels of alcohol gas rise. Alcohol Click has a small potentiometer that allows to adjust the load resistance of the sensor circuit.

The Alcohol Click communicates with the microcontroller through the AN pin. The input is provided to the internal ADC of the MCU. The data acquired from the sensor is compared with the threshold levels. If the analog signal from the Alcohol Click is above threshold, then alcohol presence is detected.

<p align="center">
  <img width=100 height=150 src="images/alcohol_click.png">
  <br>Figure 2: Alcohol Click <br>
</p>

The buzzer is used as an indicator for alcohol detection. PWM is required to turn on the buzzer for indication. The Timer2 is used for addressing two different functionalities: for implementing switch debounce and as a time base for PWM.

<p align="center">
  <img width=100 height=150 src="images/buzz_2_click.png">
  <br>Figure 3: Buzz 2 Click <br>
</p>

## Software Used

Microchip’s free IDE, compiler and graphical code generators are used throughout the application firmware development. Following are the tools used for this demo application:

* [MPLAB^®^ X IDE](https://www.microchip.com/mplab/mplab-x-ide) v6.15.0 or newer
* [XC8 Compiler](https://www.microchip.com/mplab/compilers) v2.41.0 or newer
* [MPLAB Code Configurator (MCC)](https://www.microchip.com/mplab/mplab-code-configurator) v5.3.7
* [Microchip PIC16F1xxxx Series Device Support](https://packs.download.microchip.com/) 1.20.366 or newer
* TMR2 MCC Melody Driver 4.0.16
* EUSART MCC Melody Driver 7.1.4
* PWM MCC Melody Driver 4.2.10
* ADC MCC Melody Driver 3.0.10


***Note: For running the demo, the installed tool versions should be the same or later. This example is not tested with the previous versions.***

## Hardware Used

* [PIC16F15244 Curiosity Nano](https://www.microchip.com/en-us/product/PIC16F15244)
* [Curiosity Nano Base for Click boards](https://www.microchip.com/developmenttools/ProductDetails/AC164162)
* [Alcohol Click](https://www.mikroe.com/alcohol-click)
* [BUZZ 2 Click](https://www.mikroe.com/buzz-2-click)

## Hardware Setup

The following figure consists of Alcohol Click, BUZZ 2 Click, Curiosity Nano Adapter Board and PIC16F15244 Curiosity Nano Evaluation kit. The figure shows the detailed information about the hardware setup. The Alcohol Click and BUZZ 2 click are interfaced with PIC16F15244 MCU using the Curiosity Nano Adaptor slot 1 and 2, respectively.

<p align="center">
  <img width=600 height=auto src="images/setup.png">
  <br>Figure 4: Hardware Setup <br>
</p>

MQ-3 sensor and the Click board with a pot for adjustable resistance is visible in the image below.

<p align="center">
  <img width=600 height=auto src="images/mq_sensor.png">
  <br>Figure 5: MQ-3 Sensor & Click Board <br>
</p>

## Operation

* Make the hardware connections as shown in the Hardware Setup section. Power up the Curiosity Nano board using a micro-USB cable.
* Download the firmware available from the github page link
* Build the project using the latest versions of tools, as mentioned in the Software Tools section, and load the generated hexadecimal file in to the PIC16F15244 MCU
* After running the program, the Data Visualizer will display the project name as shown in the figure below

<p align="center">
  <img width=600 height=auto src="images/default_window.png">
  <br>Figure 6: Default Display Screen <br>
</p>

* To wake up the device and perform the alcohol detection test, press the on-board switch. As soon as you press it, the terminal window pops up with the next commands as shown in the below figure

<p align="center">
  <img width=600 height=auto src="images/switch_press.png">
  <br>Figure 7: Post switch press Display Screen <br>
</p>

* Dip the cotton ball/bud in the liquid containing alcohol and hold it in front of the sensor for five seconds
* After five seconds, the result of the alcohol test will be displayed on the terminal window as shown in below figure. The buzzer starts ringing if the alcohol presence is detected.

<p align="center">
  <img width=600 height=auto src="images/output_window.png">
  <br>Figure 8: Result Screen <br>
</p>

* The device goes into Sleep mode after the alcohol detection test is performed. For repeating the alcohol detection test press the  on-board switch.

## Conclusion

The usage of the ADC peripheral along with the Sleep mode feature are showcased through the analog data measurement with the alcohol sensor.

## Appendix

MPLAB^®^ Code Configurator (MCC) is a graphical is a graphical programming environment that generates seamless, easy to understand C code to give a head start to the project, saving the designer’s time to initialize and configure all the modules, and to go through the data sheets. Using an instructive interface, it enables and configures all peripherals and functions specific to the application requirements.

* Start by creating a new Project and open MCC
* Go to File > New Project
* Select Microchip Embedded > Standalone Project
* Enter the device name. In this case we are using the PIC16F15244
* Name the project
* Open the MCC by clicking on MCC logo

## System Configuration

Open Clock Control, under the System dropdown menu, in the **Project Resources** tab

* Set "Clock Source" as "HFINTOSC"
* Set "HF Internal Clock" as "4_MHz"

The system configuration window of MCC is used for the MCU oscillator, the Watchdog Timer and the low voltage programming configuration. The Watchdog Timer is disabled in the application.
The following figure shows the system configuration setting in MCC tool.

<p align="center">
  <img width=600 height=auto src="images/clock_config.png">
  <br>Figure 9: System Clock Configuration <br>
</p>

## Timer2 Configuration

Part 1: The timer is configured for PWM setup, which will dynamically switch to HLT mode for switch debouncing.

* Select Timer – Timer2
* Control Mode – Roll over pulse
* Start/Reset Option – Software Control
* Clock Source – FOSC/4
* Polarity – Rising Edge, Prescaler – 1:128, Postscaler – 1:1
* Time Period – 32 ms, Enable Timer Interrupt checkbox

<p align="center">
  <img width=600 height=auto src="images/timer_config.png">
  <br>Figure 10: Timer2 Configuration - PWM Setup <br>
</p>

Part 2: Generate one more project with Timer in HLT mode for debouncing with following configuration.

* Select Timer checkbox
* Control Mode – Monostable
* Ext Reset – T2INPPS
* Star/Reset Option – Start on rising edge on TMR2_ers
* Clock Source – LFINTOSC
* Polarity – Rising Edge, Prescaler – 1:128, Postscaler – 1:1
* Time Period – 50 ms, Enable Timer Interrupt checkbox

<p align="center">
  <img width=600 height=auto src="images/timer_config_1.png">
  <br>Figure 11: Timer2 Configuration - HLT Mode Setup <br>
</p>

## EUSART Configuration
EUSART is used for displaying the alcohol detection test results and debugging.

* Set EUSART Mode to Asynchronous
* Enable EUSART, Transmit checkbox
* Set Baud Rate – 9600
* Set Transmission and Reception bits – 8bit
* Select checkbox for Redirect STDIO to USART

<p align="center">
  <img width=600 height=auto src="images/eusart_config.png">
  <br>Figure 12: EUSART Configuration <br>
</p>

## PWM Configuration

* Select a Timer - Timer2
* Select Duty Cycle – 50%
* PWM Polarity – active_hi

<p align="center">
  <img width=600 height=auto src="images/pwm_config.png">
  <br>Figure 13: PWM Configuration <br>
</p>

## ADC Configuration

* Enable ADC 
* Result alignment - right
* Positive reference - V~DD~
* Clock source - Fosc/4

<p align="center">
  <img width=600 height=auto src="images/adc_config.png">
  <br>Figure 14: ADC Configuration <br>
</p>

## Pin Mapping

<p align="center">
  <img width=600 height=auto src="images/pin_config.png">
  <br>Figure 15: Pin Configuration <br>
</p>

* The pin mapping highlights the Timer2 and switch with the same pin mapped, as HLT mode is used.
* The ADC channel selection is highlighted as it takes input from RA5 pin (CHS value : 000101).
* PWM provides output to the buzzer, which uses Timer2.