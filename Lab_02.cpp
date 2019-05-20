// 2.1 Reading the Push Buttons
#include <msp430fr6989.h>
#define redLED BIT0 // Red LED at P1.0
#define greenLED BIT7 // Green LED at P9.7
#define BUT1 BIT1 // Button S1 at P1.1
void main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Enable the GPIO pins
// Configure and initialize LEDs
    P1DIR |= redLED; // Direct pin as output
    P9DIR |= greenLED; // Direct pin as output
    P1OUT &= ~redLED; // Turn LED Off
    P9OUT &= ~greenLED; // Turn LED Off
// Configure buttons
    P1DIR &= ~BUT1; // Direct pin as input
    P1REN |= BUT1; // Enable built-in resistor
    P1OUT |= BUT1; // Set resistor as pull-up
// Polling the button in an infinite loop
    for(;;) {
// button pressed if statement
        if ( (P1IN & BUT1) == 0 ){
            P1OUT |= redLED; // Turn red LED on
        }
        else P1OUT &= ~redLED; // Turn red LED off
    }
}

// 2.2 Using two Push Buttons
#include <msp430fr6989.h>
#define redLED BIT0 // Red LED at P1.0
#define greenLED BIT7 // Green LED at P9.7
#define BUT1 BIT1 // Button S1 at P1.1
#define BUT2 BIT2 // Button S1 at P1.2
void main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Enable the GPIO pins
// Configure and initialize LEDs
    P1DIR |= redLED; // Direct pin as output
    P9DIR |= greenLED; // Direct pin as output
    P1OUT &= ~redLED; // Turn LED Off
    P9OUT &= ~greenLED; // Turn LED Off
// Configure button 1
    P1DIR &= ~(BUT1); // Direct pin as input
    P1REN |= (BUT1); // Enable built-in resistor
    P1OUT |= (BUT1); // Set resistor as pull-up
//Configure button 2
    P1DIR &= ~(BUT2); // Direct pin as input
    P1REN |= (BUT2); // Enable built-in resistor
    P1OUT |= (BUT2); // Set resistor as pull-up
// Polling the button in an infinite loop
    for(;;) {
// button pressed if statement
        if ( (P1IN & BUT1) == 0 )
            P1OUT |= redLED; // Turn red LED on
        else
            P1OUT &= ~redLED; //turn off LED
        if ( (P1IN & BUT2) == 0 )
            P9OUT |= greenLED; // Turn green LED on
        else
            P9OUT &= ~greenLED; // Turn off LED
    }
}

// 2.3 Using two Buttons with Exclusive Access
#include <msp430fr6989.h>
#define redLED BIT0 // Red LED at P1.0
#define greenLED BIT7 // Green LED at P9.7
#define BUT1 BIT1 // Button S1 at P1.1
#define BUT2 BIT2 // Button S1 at P1.2
void main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Enable the GPIO pins
// Configure and initialize LEDs
    P1DIR |= redLED; // Direct pin as output
    P9DIR |= greenLED; // Direct pin as output
    P1OUT &= ~redLED; // Turn LED Off
    P9OUT &= ~greenLED; // Turn LED Off
// Configure button 1
    P1DIR &= ~(BUT1); // Direct pin as input
    P1REN |= (BUT1); // Enable built-in resistor
    P1OUT |= (BUT1); // Set resistor as pull-up
//Configure button 2
    P1DIR &= ~(BUT2); // Direct pin as input
    P1REN |= (BUT2); // Enable built-in resistor
    P1OUT |= (BUT2); // Set resistor as pull-up
// Polling the button in an infinite loop
    for(;;) {
// check for button 1 pressed
        while ((BUT1 & P1IN) == 0){
            P1OUT |= redLED; // light red LED by itself
        }
        P1OUT &= ~redLED; // Turn off LED
// check for button 2 pressed
        while ((BUT2 & P1IN) == 0){
            P9OUT |= greenLED; // light green led by itself
        }
        P9OUT &= ~greenLED; // Turn off LED
    }
}

// 2.4 User Design
#include <msp430fr6989.h>
#define redLED BIT0 // Red LED at P1.0
#define greenLED BIT7 // Green LED at P9.7
#define BUT1 BIT1 // Button S1 at P1.1
#define BUT2 BIT2 // Button S1 at P1.2
void main(void) {
    volatile unsigned int i;
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Enable the GPIO pins
    // Configure and initialize LEDs
    P1DIR |= redLED; // Direct pin as output
    P9DIR |= greenLED; // Direct pin as output
    P1OUT &= ~redLED; // Turn LED Off
    P9OUT &= ~greenLED; // Turn LED Off
// Configure button 1
    P1DIR &= ~(BUT1); // Direct pin as input
    P1REN |= (BUT1); // Enable built-in resistor
    P1OUT |= (BUT1); // Set resistor as pull-up
//Configure button 2
    P1DIR &= ~(BUT2); // Direct pin as input
    P1REN |= (BUT2); // Enable built-in resistor
    P1OUT |= (BUT2); // Set resistor as pull-up
// Polling the button in an infinite loop
    for(;;) {
//check for button 1 pressed
        while ((BUT1 & P1IN) == 0){
            P9OUT |= greenLED; //light red led by itself
//if button 2 is pressed, flash red LED
            while ((BUT2 & P1IN) == 0){
                P1OUT ^= redLED;
                for (i=0;i<65000;i++){}
            }
            P1OUT &= ~redLED; // Turn off LED
        }
        P9OUT &= ~greenLED; // Turn off LED
//check for button 2 pressed
        while ((BUT2 & P1IN) == 0){
            P1OUT |= redLED; //light green led by itself
//if button 1 is pressed, flash green LED
            while ((BUT1 & P1IN) == 0){
                P9OUT ^= greenLED;
                for (i=0;i<65000;i++){}
            }
            P9OUT &= ~greenLED; // Turn off green LED
        }
        P1OUT &= ~redLED; // Turn off red LED
    }
}

