#include <Servo.h>
Servo myservo;
int potPin = 0;
int val;
int toneVal;
float sinVal;
int servo = 9;
int piezo = 8;


void setup() {
  myservo.attach(servo);
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop() {
  val = analogRead(potPin);

  val = map(val, 0, 1023, 0, 180);

  myservo.write(val);
  Serial.println(val);

  if (val > 90) {
    piezoSound(piezo);  
  } else {
    noTone(piezo);  
  }

  delay(15);
  
}

void piezoSound(int piezoPin) {
  for (int i = 0; i < 180; i++){
      sinVal = sin(i * 3.1412 / 180);
      toneVal = int(sinVal * 1000) + 2000;
      tone(piezoPin, toneVal);
  }
}
