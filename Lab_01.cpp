// 1.2 Flashing the LED
#include <msp430.h>
#define rLED BIT0 // Red LED at P1.0

void main(void) {

    volatile unsigned int i;

    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default highimpedance mode

    P1DIR |= rLED; // Direct pin as output
    P1OUT &= ~rLED; // Turn LED Off

    for(;;) {
        // Delay loop

        for(i=0; i<25000; i++) {}
        P1OUT ^= rLED; // Toggle red LED

    }
}

// 1.3 Setting a long period
#include <msp430.h>
#include <stdint.h>
#define rLED BIT0 // Red LED at P1.0

void main(void) {

    volatile uint32_t i; // unsigned int 32-bit type
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default highimpedance mode

    P1DIR |= rLED; // Direct pin as output
    P1OUT &= ~rLED; // Turn LED Off

    for(;;) {
        // Delay loop
        for(i=0; i<120000; i++) {}
        P1OUT ^= rLED; // Toggle red LED

    }
}

// 1.4 Flashing two LED’s
#include <msp430.h>

#define rLED BIT0 // Red LED at P1.0
#define gLED BIT7 // Green LED at P9.7

void main(void) {

    volatile unsigned int i;
    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default highimpedance mode

    P1DIR |= rLED; // Direct pin as output
    P9DIR |= gLED; // Direct pin as output

    P1OUT &= ~rLED; // Turn LED Off
    //P9OUT &= ~gLED; // Turn LED Off to blink in sync

    for(;;) {

        P1OUT ^= rLED; // Toggle red LED

        P9OUT ^= gLED; // Toggle green LED

        for(i=0; i<30000; i++) {} // Delay loop

    }
}

// 1.5 Flashing two LED’s at different rates
#include <msp430.h>

#define rLED BIT0 // Red LED at P1.0
#define gLED BIT7 // Green LED at P9.7

void main(void) {

    volatile unsigned int i;

    WDTCTL = WDTPW | WDTHOLD; // Stop the Watchdog timer
    PM5CTL0 &= ~LOCKLPM5; // Disable GPIO power-on default highimpedance mode

    P1DIR |= rLED; // Direct pin as output
    P9DIR |= gLED; // Direct pin as output

    P1OUT &= ~rLED; // Turn LED Off
    P9OUT &= ~gLED; // Turn LED Off

    for(;;) {

        P1OUT ^= rLED; // Toggle red LED

        P9OUT ^= gLED; // Toggle green LED

        //double red frequency
        for(i=0; i<30000; i++) {} // Delay loop
        P1OUT ^= rLED; // Toggle red LED
        for(i=0; i<30000; i++) {} // Delay loop
        P1OUT ^= rLED; // Toggle red LED
        for(i=0; i<30000; i++) {} // Delay loop
        P1OUT ^= rLED; // Toggle red LED
        P9OUT ^= gLED; // Toggle green LED

        for(i=0; i<30000; i++) {} // Delay loop

    }
}
