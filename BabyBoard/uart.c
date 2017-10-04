/* uart.c
 * Authors: Andrew Dudney and Matthew Haney
 * Copyright 2016 Andrew Dudney
 * Provides an implementation to the UART interface defined in uart.h
 */

#include <msp430.h>
#include "uart.h"
#include "msp430g2553.h”

// Parity disabled, LSB first, 8 bit data, 1 stop bit

// set_clock: Set the internal clock to the provided speed, in MHz.
void set_clock(int speed) {

}

/* init_uart: Initialize everything necessary for the UART functionality you are implementing.
*  Be sure not to affect pins other than the TX and RX pins (output values, directions, or select registers).
*  You must support a baud rate of 9600 (UART_BAUD_9600) and 115200 (UART_BAUD_115200).  The other baud rates are optional.
*/
void init_uart(char baud) {
  /*
   *
   * 1. Set UCSWRST
   * 2. Initialize all USCI registers with UCSWRST = 1 (including UCAxCTL1)
   * 3. Configure ports
   * 4. Clear USCWRST via software
   * 5. (Optional) Enable interrupts via UCAxRXIE and/or UCAxTXIE
   *
   * */

    UCA0CTL1 |= UCSWRST;    //set UCSWRST
    UCA0CTL1 |= UCSSEL_2;   //SMCLK clock

    /*8 bit char data
     * UC7BIT = 8-bit char data bit;
     * UCMODEx = UART mode;
     * UCSPB = one stop bit;
     * UCSYNC = UART mode
     * */
    UCA0CTL0 &= ~UC7BIT;

    //Baudrate set
    UCA0BR0 = baud;         //convert baud to hex??
    UCA0BR1 = 0x00;

    //configure ports
    //Done in main ? :/

    UCA0CTL1 &= ~ UCSWRST;  //clear UCSWRST
}

// uninit_uart: Uninitialize the uart driver.
void uninit_uart() {
  
}

// putch: Send an unsigned char via UART.  This function should transmit characters correctly regardless of how many times this function is called in rapid succession.
void putch(unsigned char c) {
  
}

// put_str: Send each element of a null-terminated array of unsigned chars via UART.  Do not send the final null-termination character.
void put_str(unsigned char* c) {
  
}

/*  uart_rx: Return the most recent character received via UART.
*   The block parameter determines the behavior of uart_rx if no character has been received.  The functionality is defined as follows:
*   If a character has been received, return the most recently received character.
*   If no character has been received and block is set to zero, return -1.
*   If no character has been received and block is set to one, wait for a character to be received and then return that character.
*   Thus, if the microcontroller receives 'a' one time, and this function is called twice with block = 0, the first call should return 'a' and the second should return -1.
*   If the microcontroller receives 'a' one time, and this function is called twice with block = 1, the first call should return 'a' and the
*   second should wait indefinitely until a character is received, and then return that character.
*/
int uart_rx(char block) {
  
}
