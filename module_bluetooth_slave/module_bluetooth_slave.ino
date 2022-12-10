#include<SoftwareSerial.h>
  SoftwareSerial BTSerial(3,2);
 // int Button =4;
  int led=5;
    String text = "";
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
 // pinMode(Button,INPUT_PULLUP);
  pinMode(13,OUTPUT); 
}

void loop() {
 //int button= digitalRead(Button);
  if(BTSerial.available()>0)
 {
    
       //Serial.write(BTSerial.read());
       text = BTSerial.readString();
       Serial.print(text);
       text.trim();
 }
 if(text=="a")  
 {
  digitalWrite(LED_BUILTIN,HIGH);
 }
 else
 {
  digitalWrite(LED_BUILTIN,LOW);
 }
}
