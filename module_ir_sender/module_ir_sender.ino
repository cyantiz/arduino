#include <IRremote.h> 
 
 IRsend irsend(3); 
 
 void setup() 
 { 
 } 
 
 void loop() { 
 
 irsend.sendRC5(0x100, 8); //send 0x0 code (8 bits) 
 delay(1000); 
 
 irsend.sendRC5(0x101, 8); 
 delay(1000);
 } 
