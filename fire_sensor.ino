#include <SoftwareSerial.h>
SoftwareSerial BTSerial(12,13);

int analogPin = A3;
int digitalPin = 3;
int buzzerPin = 7;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;



void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
  int digitalVal = digitalRead(digitalPin);
  int analogVal = analogRead(analogPin);
  Serial.println(digitalVal+String("/")+analogVal);

  if(digitalVal == HIGH) {
    BTSerial.write("on");
    if(analogVal < 200){
      digitalWrite(redPin,255);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      tone(buzzerPin, 784);
      

      delay(200);

      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      
      noTone(buzzerPin);
    }
  
    else if (analogVal < 60 0){
      digitalWrite(redPin,255);
      digitalWrite(greenPin, 127);
      digitalWrite(bluePin, 0);
      tone(buzzerPin,523);

      delay(500);

      digitalWrite(redPin,0);
      digitalWrite(greenPin,0);
      digitalWrite(bluePin,0);

      noTone(buzzerPin);
    }
    } else {
      BTSerial.write("off");
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 255);
      digitalWrite(bluePin, 0);

      noTone(buzzerPin);
    }
    delay(200);

    if(BTSerial.available())
      Serial.println(BTSerial.parseInt());

}
