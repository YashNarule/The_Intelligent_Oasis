

#include <LiquidCrystal.h>
int cont=80;
int seconds = 0;
#include "DHT.h"
#define DHTPIN 8
#define SENSOR_IN A5
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
pinMode(A0,INPUT);

Serial.begin(9600);
Serial.println("DHTxx test!");
dht.begin();
delay(1500); 
//lcd
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
	analogWrite(6,cont);
lcd_1.setCursor(0, 1);
lcd_1.print("SMART WATER SYS");
}

void loop()
{
  lcd_1.setCursor(0, 0);

  if(Serial.available()){
  String line1=Serial.readStringUntil('\n');
  lcd_1.print(line1);
  Serial.print(line1);
  String line2=Serial.readStringUntil('\n');
  lcd_1.print(line2);
  Serial.print(line2);
  }
 
   delay(4000);
lcd_1.setCursor(0, 1);
lcd_1.print("SMART WATER SYS ");
  

}