/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    March 1, 2022
 
 This example UBMP4.1 input and output program demonstrates pushbutton input,
 LED (bit) output, port latch (byte) output, time delay functions, and simple
 'if' condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP410.h"         // Include UBMP4.1 constant and function definitions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

#define EnableA H1OUT
#define EnableB H6OUT
#define Aforward H3OUT
#define Abackward H2OUT
#define Bforward H4OUT
#define Bbackward H5OUT
#define forward SW3
#define backward SW2
#define left SW4
#define right SW5
unsigned char Speed = 255;


// The main function is required, and the program begins executing from here.

int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	TRISC = 0b0000000;
    // Code in this while loop runs repeatedly.
    while(1)
	{
       if(forward == 0)
       {
           EnableA = 1;
           EnableB = 1;
           Aforward = 1;
           Bforward = 1;
           __delay_ms(2000);
           EnableA = 0;
           EnableB = 0;
           Aforward = 0;
           Bforward = 0;
           
       }
         else if(backward == 0)
       {
           EnableA = 1;
           EnableB = 1;
           Abackward = 1;
           Bbackward = 1;
           __delay_ms(2000);
           EnableA = 0;
           EnableB = 0;
           Abackward = 0;
           Bbackward = 0;
       }
         else if(left == 0)
       {
           EnableA = 1;
           EnableB = 1;
           Aforward = 1;
           Bbackward = 1;
           __delay_ms(500);
            EnableA = 0;
           EnableB = 0;
           Aforward = 0;
           Bbackward = 0;
       }
          else if(right == 0)
       {
           EnableA = 1;
           EnableB = 1;
           Abackward = 1;
           Bforward = 1;
           __delay_ms(500);
           EnableA = 0;
           EnableB = 0;
           Abackward = 0;
           Bforward = 0;
       }
       else
       {
            EnableA = 0;
           EnableB = 0;
           Aforward = 0;
           Bforward = 0;
           Abackward = 0;
           Bbackward = 0;
           forward = 0;
           backward = 0;
           left = 0;
           right = 0;
       }

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}




