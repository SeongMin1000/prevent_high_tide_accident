#include<SoftwareSerial.h>

SoftwareSerial myserial(6,7);
SoftwareSerial HM10(0,1);

#include <pitches.h>
int LED_pins[]={2,3};
int motionPin = 5;
int waterPin = A0;
void setup() {
  Serial.begin(9600);
  myserial.begin(9600);
  HM10.begin(9600);
  for(int i=0;i<2;i++){
  pinMode(LED_pins[i], OUTPUT);
  }
  pinMode( waterPin, INPUT);
  pinMode(motionPin,INPUT);
}

void loop() {
  int water = analogRead(waterPin);
  int motion= digitalRead(motionPin);
  if(water < 400){
    noTone(A1);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    analogWrite(4,0);
  }
  if(water > 400 && motion == 0){
    for(int i=0; i<2;i++){
      digitalWrite(LED_pins[i],HIGH);
      delay(30);
      digitalWrite(LED_pins[i],LOW);
    }
    noTone(A1);
  }
   if(water >500 && motion==0){
    for(int i=0; i<2;i++){
      digitalWrite(LED_pins[i],HIGH);
      delay(30);
      digitalWrite(LED_pins[i],LOW);
    }
    tone(A1,NOTE_G6);
    analogWrite(4,0);
    myserial.write('1');
  }
  if(water >500 && motion==1){
    for(int i=0; i<2;i++){
      digitalWrite(LED_pins[i],HIGH);
      delay(30);
      digitalWrite(LED_pins[i],LOW);
    }
    tone(A1,NOTE_G6);
    analogWrite( 4,100);
    myserial.write('2');
  }
  HM10.write("Hello");
  delay(500);
}
