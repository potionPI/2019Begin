// Code to create PWM music taken and modified from Make: AVR Programming by Elliot Williams

// Includes:
#include <avr/io.h>
#include <util/delay.h>
#include "scale16.h"
#include "pinDefines.h"

// defines
#define keyAmount 16
#define song1length 50
#define initialSongMultiplier 1.25

// global variables
int timePressed = 0;
int recordingNow = 0;
int playingSong1Now = 0;
uint16_t song1[song1length];
int song1duration[song1length];
int song1position = 0;

// playNote function. 
void playNote(uint16_t period, uint16_t duration) {
	uint16_t elapsed;
	uint16_t i;
	for (elapsed = 0; elapsed < duration; elapsed += period) {
		/* For loop with variable delay selects the pitch */
		for (i = 0; i < period; i++) {
			_delay_us(1);
		}
		SPEAKER_PORT ^= (1 << SPEAKER);
	}
}

void rest(uint16_t duration) {
	do {
		_delay_us(1);
	} while (--duration);
}

int main(void) {
	
	song1[0] = B5; song1duration[0] = 38 * initialSongMultiplier;
	song1[1] = A5; song1duration[1] = 13 * initialSongMultiplier;
	song1[2] = B5; song1duration[2] = 50 * initialSongMultiplier;
	song1[3] = E6; song1duration[3] = 38 * initialSongMultiplier;
	song1[4] = D6; song1duration[4] = 13 * initialSongMultiplier;
	song1[5] = E6; song1duration[5] = 50 * initialSongMultiplier;
	song1[6] = B5; song1duration[6] = 38 * initialSongMultiplier;
	song1[7] = D6; song1duration[7] = 13 * initialSongMultiplier;
	song1[8] = B5; song1duration[8] = 25 * initialSongMultiplier;
	song1[9] = A5; song1duration[9] = 25 * initialSongMultiplier;
	song1[10] = G5; song1duration[10] = 75 * initialSongMultiplier;
	song1[11] = 0; song1duration[11] = 25 * initialSongMultiplier;
	song1[12] = E6; song1duration[12] = 25 * initialSongMultiplier;
	song1[13] = 0; song1duration[13] = 3 * initialSongMultiplier;
	song1[14] = E6; song1duration[14] = 25 * initialSongMultiplier;
	song1[15] = D6; song1duration[15] = 25 * initialSongMultiplier;
	song1[16] = B5; song1duration[16] = 25 * initialSongMultiplier;
	song1[17] = E6; song1duration[17] = 25 * initialSongMultiplier;
	song1[18] = 0; song1duration[18] = 3 * initialSongMultiplier;
	song1[19] = E6; song1duration[19] = 25 * initialSongMultiplier;
	song1[20] = D6; song1duration[20] = 50 * initialSongMultiplier;
	song1[21] = 0; song1duration[21] = 25 * initialSongMultiplier;
	song1[22] = G6; song1duration[22] = 25 * initialSongMultiplier;
	song1[23] = E6; song1duration[23] = 25 * initialSongMultiplier;
	song1[24] = G6; song1duration[24] = 25 * initialSongMultiplier;
	song1[25] = E6; song1duration[25] = 38 * initialSongMultiplier;
	song1[26] = D6; song1duration[26] = 13 * initialSongMultiplier;
	song1[27] = B5; song1duration[27] = 50 * initialSongMultiplier;
	song1[28] = E6; song1duration[28] = 25 * initialSongMultiplier;
	song1[29] = 0; song1duration[29] = 3 * initialSongMultiplier;
	song1[30] = E6; song1duration[30] = 25 * initialSongMultiplier;
	song1[31] = D6; song1duration[31] = 25 * initialSongMultiplier;
	song1[32] = E6; song1duration[32] = 25 * initialSongMultiplier;
	song1[33] = B5; song1duration[33] = 50 * initialSongMultiplier;
	song1[34] = D6; song1duration[34] = 25 * initialSongMultiplier;
	song1[35] = E6; song1duration[35] = 25 * initialSongMultiplier;
	song1[36] = B5; song1duration[36] = 38 * initialSongMultiplier;
	song1[37] = A5; song1duration[37] = 13 * initialSongMultiplier;
	song1[38] = G5; song1duration[38] = 50 * initialSongMultiplier;
	song1[39] = 0; song1duration[39] = 3 * initialSongMultiplier;
	song1[40] = G5; song1duration[40] = 75 * initialSongMultiplier;
	
	song1position = 41;

	// -------- Inits --------- //
	BUTTON_DDR1 = 0;
	BUTTON_PORT1 = 0b11111111; // pullup on buttons
	BUTTON_DDR2 = 0;
	BUTTON_PORT2 = 0b11111111; // pullup on buttons
	BUTTON_DDR3 = 0;
	BUTTON_PORT3 = 0b11111111; // pullup on buttons
	SPEAKER_DDR |= (1 << SPEAKER);                 /* speaker for output */
	SPEAKER_PORT &= ~(1 << SPEAKER);
	LED_DDR |= (1 << LEDRC);
	LED_DDR |= (1 << LEDS1);
	LED_PORT &= ~(1 << LEDRC);
	LED_PORT &= ~(1 << LEDS1);

  // ------ Event loop ------ //
	while (1) {
		while (bit_is_clear(BUTTON_PIN1, BUTTON1)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(D6, 1000);
		}
		while (bit_is_clear(BUTTON_PIN1, BUTTON2)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(B5, 1000);
		}
		while (bit_is_clear(BUTTON_PIN1, BUTTON3)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(A5, 1000);
		}
		while (bit_is_clear(BUTTON_PIN1, BUTTON4)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(G5, 1000);
		}
		while (bit_is_clear(BUTTON_PIN1, BUTTON5)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(E5, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON6)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(D5, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON7)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(B4, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON8)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(A4, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON9)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(G4, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON10)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(E4, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON11)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(D4, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON12)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(B3, 1000);
		}
		while (bit_is_clear(BUTTON_PIN2, BUTTON13)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(A3, 1000);
		}
		while (bit_is_clear(BUTTON_PIN3, BUTTON14)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(G3, 1000);
		}
		while (bit_is_clear(BUTTON_PIN3, BUTTON15)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(E3, 1000);
		}
		while (bit_is_clear(BUTTON_PIN3, BUTTON16)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			playNote(D3, 1000);
		}
		
		if (bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
			if (!recordingNow) {
				recordingNow = 1;
				song1position = 0;
				for (int i = 0; i < song1length; i++) {
					song1duration[i] = 0;
				}
			} else {
				recordingNow = 0;
			}
			while(bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
			}
		}
		
		if (!recordingNow) {
			LED_PORT = LED_PORT & ~(1 << LEDRC);
		} else {
			LED_PORT = LED_PORT | (1 << LEDRC);
		}
		
		while (recordingNow) {
			if (bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
				recordingNow = 0;
				while(bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
				}
				break;
			}
			
			if (bit_is_clear(BUTTON_PIN1, BUTTON1)) {
				song1[song1position] = D6;
				song1position++;
				while (bit_is_clear(BUTTON_PIN1, BUTTON1)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(D6, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN1, BUTTON2)) {
				song1[song1position] = B5;
				song1position++;
				while (bit_is_clear(BUTTON_PIN1, BUTTON2)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(B5, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN1, BUTTON3)) {
				song1[song1position] = A5;
				song1position++;
				while (bit_is_clear(BUTTON_PIN1, BUTTON3)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(A5, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN1, BUTTON4)) {
				song1[song1position] = G5;
				song1position++;
				while (bit_is_clear(BUTTON_PIN1, BUTTON4)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(G5, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}	
			}
			if (bit_is_clear(BUTTON_PIN1, BUTTON5)) {
				song1[song1position] = E5;
				song1position++;
				while (bit_is_clear(BUTTON_PIN1, BUTTON5)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(E5, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON6)) {
				song1[song1position] = D5;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON6)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(D5, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}	
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON7)) {
				song1[song1position] = B4;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON7)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(B4, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON8)) {
				song1[song1position] = A4;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON8)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(A4, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON9)) {
				song1[song1position] = G4;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON9)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(G4, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON10)) {
				song1[song1position] = E4;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON10)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(E4, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON11)) {
				song1[song1position] = D4;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON11)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(D4, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON12)) {
				song1[song1position] = B3;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON12)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(B3, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN2, BUTTON13)) {
				song1[song1position] = A3;
				song1position++;
				while (bit_is_clear(BUTTON_PIN2, BUTTON13)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(A3, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN3, BUTTON14)) {
				song1[song1position] = G3;
				song1position++;
				while (bit_is_clear(BUTTON_PIN3, BUTTON14)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(G3, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN3, BUTTON15)) {
				song1[song1position] = E3;
				song1position++;
				while (bit_is_clear(BUTTON_PIN3, BUTTON15)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(E3, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (bit_is_clear(BUTTON_PIN3, BUTTON16)) {
				song1[song1position] = D3;
				song1position++;
				while (bit_is_clear(BUTTON_PIN3, BUTTON16)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
					playNote(D3, 1000);
					song1duration[song1position-1] += 1;
				}
				if (song1position >= song1length) {
					recordingNow = 0;
					break;
				}
			}
			if (!bit_is_clear(BUTTON_PIN1, BUTTON1) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON2) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON3) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON4) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON5) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON6) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON7) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON8) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON9) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON10) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON11) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON12) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON13) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON14) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON15) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON16) &&
				!bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
				song1[song1position] = 0;
				song1position++;
				while(!bit_is_clear(BUTTON_PIN1, BUTTON1) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON2) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON3) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON4) &&
				!bit_is_clear(BUTTON_PIN1, BUTTON5) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON6) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON7) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON8) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON9) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON10) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON11) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON12) &&
				!bit_is_clear(BUTTON_PIN2, BUTTON13) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON14) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON15) &&
				!bit_is_clear(BUTTON_PIN3, BUTTON16) &&
				!bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
					song1duration[song1position-1] += 1;
					rest(100);
					if (song1position >= song1length) {
						recordingNow = 0;
						break;
					}
				}
			}			
		}
		
		if (bit_is_clear(BUTTON_PIN3, BUTTONS1)) {
			if (!playingSong1Now) {
				playingSong1Now = 1;
				} else {
				playingSong1Now = 0;
			}
			while(bit_is_clear(BUTTON_PIN3, BUTTONS1)) {
			}
		}
		
		if (!playingSong1Now) {
			LED_PORT = LED_PORT & ~(1 << LEDS1);
			} else {
			LED_PORT = LED_PORT | (1 << LEDS1);
		}
		
		while (playingSong1Now) {
			for (int i = 0; i < song1position; i++) {
				for (int g = 0; g < song1duration[i]; g++) {
					if (song1[i] != 0) {
						playNote(song1[i], 1000);
					} else {
						rest(100);
					}
				}
			}
			playingSong1Now = 0;
		}
		
		//if (bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
			//LED_PORT ^= (1 << LEDRC);
			//if (recordingNow) {
				//recordingNow = 0;
			//} else {
				//recordingNow = 1;
				//song1position = 0;
				//if(playingSong1Now) {
					//playingSong1Now = 0;
					//LED_PORT ^= (1 << LEDS1);
				//}
			//}
			//
			//while(bit_is_clear(BUTTON_PIN3, BUTTONRC)) {
			//}
		//}
		//
		//if (!recordingNow && bit_is_clear(BUTTON_PIN3, BUTTONS1)) {
			//LED_PORT ^= (1 << LEDS1);
			//if (playingSong1Now) {
				//playingSong1Now = 0;
			//} else {
				//playingSong1Now = 1;
			//}
			//while(bit_is_clear(BUTTON_PIN3, BUTTONS1)) {
			//}
			//if (playingSong1Now) {
				//for (int i = 0; i < song1position; i++) {
					//for (int j = 0; j < song1duration[i]; j++) {
						//playNote(song1[i], 1000);
					//}
					//
				//}
			//}
		//}
		//
		//if (bit_is_clear(BUTTON_PIN1, BUTTON1)) { // ahh whatever I'm using a 4.7uF cap instead of programming debouncing
			//if (recordingNow) {
				//song1[song1position] = D6;
				//song1position++;
			//}
			//
			//while(bit_is_clear(BUTTON_PIN1, BUTTON1)) {
				//playNote(D6, 1000);
				//if (recordingNow) {
					//song1duration[song1position-1] ++;
				//}
			//}
			//if (recordingNow && (song1position >= song1length)) {
				//recordingNow = 0;
				//LED_PORT ^= (1 << LEDRC);
			//}
		//}
		//if (bit_is_clear(BUTTON_PIN1, BUTTON2)) { // ahh whatever I'm using a 470nF cap instead of programming debouncing
			//if (recordingNow) {
				//song1[song1position] = B5;
				//song1position++;
			//}
			//
			//while(bit_is_clear(BUTTON_PIN1, BUTTON2)) {
				//playNote(B5, 1000);
				//if (recordingNow) {
					//song1duration[song1position-1] ++;
				//}
			//}
			//if (recordingNow && (song1position >= song1length)) {
				//recordingNow = 0;
				//LED_PORT ^= (1 << LEDRC);
			//}
		//}
	
	} // end while(1)
	return 0;
}
