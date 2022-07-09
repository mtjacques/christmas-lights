                  // This code was written by Click that moment.

// To adapt the code to your case, just change this top section, with the #define lines.


// Includes the watchdog timer library

#include <avr/wdt.h>


// This sets how many channels will vixen be sending. Can be set to any number from 1 to 48 for Arduino Mega, and 1 to 18 for Arduino Uno.

#define CHANNEL_COUNT 5


// speed for the com port for talking with vixen. From 9600 to 115200. Use the same speed as set in Vixen.

#define VIXEN_COM_SPEED 9600


// Timeout waiting for serial input before going to random mode (in milliseconds).

#define TIME_OUT 1000


// If the relays turn On and Off opposite to Vixen sequence, change "#define MODE NOT_INVERTED" for "#define MODE INVERTED"

#define NOT_INVERTED 0

#define INVERTED 1

#define MODE NOT_INVERTED


// which pins control which channels

// You can change these assignment to use different pins, but be very careful to not repeat the same pin number for 2 channels. 

// DO NOT use pings 0 and 1, as those are for the serial port to talk to the computer.

#define CH01 2

#define CH02 3

#define CH03 4

#define CH04 5

#define CH05 6



int channels[] = {CH01,CH02,CH03,CH04,CH05};


int incomingByte[CHANNEL_COUNT];


int i = 0; // Loop counter

volatile unsigned long timer_a = 0; // new line


//setup the pins/ inputs & outputs

void setup(){


// enable the watchdog timer with a time of 1 second. If the board freezes, it will reset itself after 1 second.

wdt_enable(WDTO_1S);


// specifically for the UNO

sei(); 


// initalize PWM Channels / Pins

for (i=0; i < CHANNEL_COUNT; i++){

pinMode(channels[i], OUTPUT);

}


// set all the realys to off to start with

if (MODE == NOT_INVERTED) {

for (i=0; i < CHANNEL_COUNT; i++){

digitalWrite(channels[i], LOW);


}

}


else {

for (i=0; i < CHANNEL_COUNT; i++){

digitalWrite(channels[i], HIGH);

}

}


testSequence();


// set up Serial according to the speed defined above.

Serial.begin(VIXEN_COM_SPEED);

}


void loop()

{

if (Serial.available() >= (CHANNEL_COUNT+2)) {

wdt_reset(); // resets the watchdog

timer_a = millis (); // new line

int uno = Serial.read();

if (uno == 126){


int dos = Serial.read();

if (dos == 33){


for (i=0; i < CHANNEL_COUNT; i++) {

// read each byte

incomingByte[i] = Serial.read();

}

if (MODE == NOT_INVERTED) {

for (i=0; i < CHANNEL_COUNT; i++){

int value = incomingByte[i];

if (value <= 127) {

digitalWrite(channels[i], LOW);

}

else {

digitalWrite(channels[i], HIGH);

}

}

}

else {

for (i=0; i < CHANNEL_COUNT; i++){

int value = incomingByte[i];

if (value < 127) {

digitalWrite(channels[i], HIGH);

}

else {

digitalWrite(channels[i], LOW);

}

}

}


}

}

}

// Random mode code. Random mode starts if no serial input has been received in TIME_OUT millisenconds

else {

wdt_reset(); // resets the watchdog

unsigned long diff = millis() - timer_a;

if (diff >= TIME_OUT) {

timer_a = millis ();

int random_a = 0;

for (i=0; i < CHANNEL_COUNT; i++){

random_a = random(0, 2);

if (random_a == 0) {

digitalWrite(channels[i], LOW);

}

else {

digitalWrite(channels[i], HIGH);

}

}

}

}

}


void testSequence(){


if (MODE == NOT_INVERTED) {

for (i=0; i < CHANNEL_COUNT; i++){

wdt_reset(); // resets the watchdog

digitalWrite(channels[i], HIGH);

delay (500);

digitalWrite(channels[i], LOW);

}

}


else {

for (i=0; i < CHANNEL_COUNT; i++){

wdt_reset(); // resets the watchdog

digitalWrite(channels[i], LOW);

delay (500);

digitalWrite(channels[i], HIGH);

}

}

}
