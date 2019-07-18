// ---------------
//   Pin Defines, heavily edited from Make: AVR Programming by Elliot Williams
// ---------------

#define SPEAKER                 PD6                            /* OC0A */
#define SPEAKER_PORT            PORTD
#define SPEAKER_PIN             PIND
#define SPEAKER_DDR             DDRD

#define LEDRC					PD0
#define LEDS1					PD1
#define LED_PORT				PORTD
#define LED_DDR					DDRD

#define BUTTON_PORT1            PORTD
#define BUTTON_PIN1             PIND
#define BUTTON_DDR1             DDRD

#define BUTTON_PORT2            PORTB
#define BUTTON_PIN2             PINB
#define BUTTON_DDR2             DDRB

#define BUTTON_PORT3            PORTC
#define BUTTON_PIN3             PINC
#define BUTTON_DDR3             DDRC

#define BUTTON1                 PD2 // D6
#define BUTTON2                 PD3 // B5
#define BUTTON3                 PD4 // A5
#define BUTTON4					PD5 // G5
#define BUTTON5					PD7 // E5
#define BUTTON6					PB0 // D5
#define BUTTON7					PB1 // B4
#define BUTTON8					PB2 // A4
#define BUTTON9					PB3 // G4
#define BUTTON10				PB4 // E4
#define BUTTON11				PB5 // D4
#define BUTTON12				PB6 // B3
#define BUTTON13				PB7 // A3
#define BUTTON14				PC0 // G3
#define BUTTON15				PC1 // E3
#define BUTTON16				PC2 // D3
#define BUTTONRC				PC3 // BEGIN RECORDING
#define BUTTONS1				PC4 // STOP RECORDING AND SAVE TO THIS BUTTON
/*
atmega168a has 11 free pins capable of outputting on the right side, one of which will be a speaker
	   and has 11 free pins capable of outputting on the left side
Free: PD-> 0, 1, 2, 3, 4, 5, 6 (6 is speaker), 7
	  PB-> 0, 1, 2, 3, 4, 5, 6, 7
	  PC-> 0, 1, 2, 3, 4, 5 
*/