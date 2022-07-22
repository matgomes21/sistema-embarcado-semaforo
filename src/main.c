#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// using wiringPi pinout

// leds
#define g1 31 // GPIO 01
#define y1 25 //GPIO 26
#define r1 29 // GPIO 21

// buttons
#define b1 10 // GPIO 08
#define b2 11 // GPIO 07

int counter;

void resetCounter() {
  if(counter>=5000){
    counter = 5000;
  }
}

int main(void)
{
    wiringPiSetup();

    // leds setup
    pinMode(g1, OUTPUT);
    pinMode(y1, OUTPUT);
    pinMode(r1, OUTPUT);

    // buttons setup
    pinMode(b1, INPUT);
    pullUpDnControl(b1, PUD_UP);
    pinMode(b2, INPUT);
    pullUpDnControl(b2, PUD_UP);

    fprintf(stderr, "Running on Raspberry Pi revision %d\n", piBoardRev());

    while (1) {
        digitalWrite(g1, HIGH);
        counter = 1000*5;
        delay(counter);
        digitalWrite(g1,LOW);
        digitalWrite(y1, HIGH);
        counter = 1000*5;
        delay(counter);
        digitalWrite(y1,LOW);
        digitalWrite(r1, HIGH);
        counter = 1000;
        delay(counter);
        digitalWrite(r1,LOW);
        
        // if (digitalRead(b1) == LOW) {
        //         digitalWrite(g1, LOW);
        // }
        // if (digitalRead(b1) == HIGH){
        //         printf("b1 HIGH\n");
        //         digitalWrite(g1, HIGH);
        // }
    }
}

