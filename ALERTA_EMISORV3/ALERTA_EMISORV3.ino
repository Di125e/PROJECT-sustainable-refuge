  #include "heltec.h"
#include "images.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>


#define lcd_width 128
#define lcd_height 64
#define BAND 915E6
#define PULSADOR 38

//Adafruit_SSD1306 display(lcd_width, lcd_height, &Wire, -1);

void setup() {
    pinMode(PULSADOR, INPUT);
  Serial.begin(115200);
 // !display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Heltec.begin(true, true , true, true, BAND);
  LoRa.beginPacket();
  /*display.clearDisplay();
  display.drawBitmap(0, 0, roboticalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, camecalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, iprodhalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
  digitalWrite(25, HIGH);*/
  Heltec.display -> clear();
  Heltec.display -> display();
}
void loop() {
   //display.flipScreenVertically();
if (digitalRead(PULSADOR)==1){
  Heltec.display -> clear();
  Heltec.display -> display();
    Serial.println ("Alerta enviada");
       LoRa.beginPacket();
       LoRa.setTxPower(14, RF_PACONFIG_PASELECT_PABOOST);
       LoRa.print("Estacion 1");
       LoRa.endPacket();
  Heltec.display -> setFont (ArialMT_Plain_10);
  Heltec.display -> drawString(0, 0, "Alerta  enviada...");
  Heltec.display -> display();
   delay(10000);
  Heltec.display -> clear();
  Heltec.display -> display();
   delay (10000);
}else{
  Heltec.display -> setFont (ArialMT_Plain_10);
  Heltec.display -> drawString(15, 20, "APRETE EL BOTON");
  Heltec.display -> drawString(5, 30, "EN CASO DE INCIDENTE");
  Heltec.display -> display();
   Serial.println ("APRETE EL BOTON EN CASO DE INCIDENTE");
}
 }
  
  /*display.clearDisplay();
  display.drawBitmap(0, 0, roboticalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, camecalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, iprodhalog, 128, 64, SSD1306_WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  digitalWrite(25, HIGH);
  delay(1000);*/
  

  
  
