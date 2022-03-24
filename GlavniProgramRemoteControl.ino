#include <IRremote.h> 
#include "LowPower.h"

IRsend irsend;

const int b1  = 2; //Dodeljivanje konstanti koje predstavlaju ulaze tastera
const int b2  = 4;
const int b3  = 5;
const int b4  = 6;


int timer;
int modeCounter = 0;

void wakeUp() {
  timer = 0; //Promenljiva timer postavlja se na 0.
}

void setup() {
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT); //Povezivanje konstanti sa ulazima 
}

void loop() {
  attachInterrupt(0, wakeUp, HIGH);
  while (timer < 10000) { //sve dok je timer manji od 10000 vrti petlju

    if (digitalRead(b1) == HIGH) { // kada je taster pritisnut udji u petlju
      timer = 0; //stavi timer na 0
      delay(50);
      irsend.sendNEC(0x1FE7887, 32);     //posalji ovaj HEX kod preko IR LED
    }

    if (digitalRead(b2) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x1FE20DF, 32);     
    }

    if (digitalRead(b3) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x1FEA05F, 32);     
    }

    if (digitalRead(b4) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0x1FE48B7, 32);     
    }

    delay(1);
    timer = timer + 1; //inkrementiraj timer

  }
  
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}
