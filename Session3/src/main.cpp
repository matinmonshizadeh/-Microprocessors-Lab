#include <Arduino.h>
#include "notes.h"
#define LEDGREEN 9
#define PUSHBUTTON 7/.pio


void generateSquareWave(int pin, int frequency, unsigned long duration)
{
    unsigned long delayTime = 1000000L / (2 * frequency);
    unsigned long numberOfRepeats = (duration  * 1000L) / (2 * delayTime); 

    if (delayTime < 10000)
    {
        for (int i = 0; i < numberOfRepeats; i++)
        {
            digitalWrite(pin, HIGH);
            delayMicroseconds(delayTime);
            digitalWrite(pin, LOW);
            delayMicroseconds(delayTime);
        }
    }
    else
    {
        delayTime /= 1000;  
        for (int i = 0; i < numberOfRepeats; i++)
        {
            digitalWrite(pin, HIGH);
            delay(delayTime);
            digitalWrite(pin, LOW);
            delay(delayTime);
        }
    }
}

int melody [] {
    NOTE_A4, NOTE_B1, NOTE_G3
};

uint8_t durations[]{
    2, 4, 8
};

void setup()
{
    pinMode(9, OUTPUT);
    
    
}


void loop() {
    int numberOfNotes = sizeof(melody) / sizeof(int);
    for (int i = 0; i < numberOfNotes; i++)
    {
        int dur = 1000 / durations[i];
        generateSquareWave(9, melody[i], dur);
        delay(0.3 * dur);

    }
}