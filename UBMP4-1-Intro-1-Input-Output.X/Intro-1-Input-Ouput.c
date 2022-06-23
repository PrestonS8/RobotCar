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

/*
June 1, 2022:
We searched for parts that we needed such as servos, motors, a battery, etc. However, we only found a couple servos that we could use. 
June 2, 2022:
We found multiple vehicles that we could use. We spent this day looking for parts that were useful for what we were trying to build.
June 3, 2022:
We found another vehicle that had four wheels, four motors, a motor driver, some random wires, and a battery. This also had a large enough chassis to fit our box on. This would be the vehicle that we would continue to use.
June 4, 2022:
We did nothing.
June 5, 2022:
We did nothing.
June 6, 2022:
We tried to figure out how to code the motor driver in an attempt to make the wheels move. As we did it we figured out some information such as we need certain wires. So, we decided to figure out how to code the servo as it will be easier. We also found a better vehicle to use that only had two wheels. So, we decided to keep using this one.
June 7, 2022:
We found a forked repository about servos and tried to understand what it meant. But we got confused.
June 8, 2022:
We played around with the servo code trying to code it so that it will be able to open and close our box. Then we found out how to code the servo so that it will open and close the box.
June 9, 2022:
We found a box that was large enough to hold a servo, but small enough to fit on our chassis. We then attached the servo to the box so that it would be able to open and close the box. But since the servo’s “arm” wasn't long enough we had to tape on a screw. 
June 10, 2022:
Since we finished up with the box we decided to continue searching for the parts for our car. We found most of the wires we will need, but we just have a female to female 2 pin wire.
June 11, 2022:
We did nothing
June 12, 2022:
 We did nothing.
June 13, 2022:
We found the last part we needed, but we didn’t start wiring it yet. We decided to work on the code first.
June 14, 2022:
We got lost trying to code and wire the vehicle. This day was wasted.
June 15, 2022:
Same as yesterday.

June 16, 2022:
We learned about H1OUT, H2OUT etc. We also learned how to move the car left, right, forwards, and backwards. We also found out that our right wheel doesn’t turn backwards for some reason.
June 17, 2022:
We thought it was a coding problem and tried to fix it, however, it did not work. This day was spent trying to figure out the problem.
June 18, 2022:
We did nothing
June 19, 2022:
We did nothing.
June 20. 2022:
We figured out that it couldn’t go backwards or turn right because one of the pins wasn't soldered properly. Once it was soldered on we could turn the car backwards and right.
June 21, 2022:
We tried to code the other board as a remote but we didn’t have enough time. So, as we did not have a remote we decided to code it so that when you press a button it continues going that direction for a certain amount of time.

 */


