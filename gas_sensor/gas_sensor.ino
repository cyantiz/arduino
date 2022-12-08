
// Code cảm biến gas 
// Piezo chân số 9 
// 
int piezo = 9;

void setup() {
  Serial.begin(9600);  //Mở cổng Serial để giap tiếp | tham khảo Serial
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(piezo, OUTPUT);
}
 
void loop() {
  int value = analogRead(A0);   //đọc giá trị điện áp ở chân A0 - chân cảm biến
                                //(value luôn nằm trong khoảng 0-1023)
  Serial.println(value);        //xuất ra giá trị vừa đọc
  if(value > 500) {
    digitalWrite(LED_BUILTIN, HIGH);
    piezoSound(piezo);  
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    noTone(piezo);
  }
  
  //-----------------------------------------------------
  delay(1000);           //đợi 1 giây để bạn kịp tháy serial - (optional)
}

void piezoSound(int piezo) {
  int toneVal;
  float sinVal;
  for (int i = 0; i < 180; i++){
      sinVal = sin(i * 3.1412 / 180);
      toneVal = int(sinVal * 1000) + 2000;
      tone(piezo, toneVal);
  }
}
