#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(44,45,46,47,48,49);

void setup() {
 Serial.begin(9600);
 Serial1.begin(9600);
 lcd.begin(16,2);
}

void loop() {
  char data =Serial1.read();
  Serial.print(data);
  if(data=='1'){
     lcd.write("warning!");
     analogWrite(4,0);
  }
  else if(data=='2'){
    lcd.write("danger!");
    analogWrite(4,100);
  }
  delay(500);
  analogWrite(4,0);
  lcd.clear();
}
