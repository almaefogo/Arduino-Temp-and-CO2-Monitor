


#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8  // pin do Sensor de Temperatura
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);    

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //pins usados para usados para o display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
 pinMode(7,INPUT); //pin do Sensor de Gás
 pinMode(10,OUTPUT);/pin Alarme de Gás
 pinMode(13,OUTPUT);pin Alarme de Temperatura
 digitalWrite(13,LOW);
 digitalWrite(10,LOW);
  lcd.begin(20, 4);
   
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.print(dht.readTemperature());
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidade:    ");
  lcd.print(dht.readHumidity());
  lcd.print("%");
    if (digitalRead(7) == HIGH){
    lcd.setCursor(0,2);
    digitalWrite(10,LOW);
    lcd.print("                   ");
  }
if (digitalRead(7) == LOW){
    lcd.setCursor(0,2);
  lcd.print("**Alarme Gas**");
  digitalWrite(10,HIGH);
  }

  if (dht.readTemperature()>29){
    lcd.setCursor(0,3);
  lcd.print("*Alarme Tempertura*");
  tone( 10, 2000, 500);
  digitalWrite(13,HIGH);
  delay(500);
  
  }
  if (dht.readTemperature()<28.9){
    lcd.setCursor(0,3);
    digitalWrite(13,LOW);
    lcd.print("                   ");
  }
  delay(750);
}
