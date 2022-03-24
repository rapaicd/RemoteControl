#include <IRremote.h> // Uključujemo IRremote biblioteku

int RECV_PIN = 11; // deklarišemo ulazni pin

IRrecv irrecv(RECV_PIN); //ulazni pin dodeljujemo IRrecv

decode_results results; 

void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn(); //Palimo funckiju za IR prijemnik
}
  
void loop() {
if (irrecv.decode(&results)) { //Ako prijemnik primi neki kod udji u petlju
    Serial.println(results.value, HEX); //Ispiši na serial monitoru dekodovan kod
    irrecv.resume();
  }
}
