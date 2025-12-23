#include <Adafruit_SSD1306.h>
#include <splash.h>
#define BUZZER_PIN 10
#define BUTTON_PIN A0

void setup() {
  //pin setup
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  //serial init
  Serial.begin(9600);
  //beep to signify power on or code restart
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);
  
}

void loop() {
  readButton();
  delay(1000);
}

void soundAlarm(){
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(350);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);
  delay(150);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(150);
  digitalWrite(BUZZER_PIN, LOW);
  delay(150);
}
void readButton(){
  int readValue = analogRead(BUTTON_PIN);
  Serial.print(readValue);
  if (readValue >= 98 && readValue <= 170){
    Serial.println("Closest to OLED");
  }
  if (readValue >= 514 && readValue <= 570){
    Serial.println("Middle Button!");
    soundAlarm();
  }
  if (readValue >= 490 && readValue <= 505){
    Serial.println("Middle Button");
  }
}
