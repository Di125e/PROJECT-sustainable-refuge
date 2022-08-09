#include "heltec.h"
#include "images.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define lcd_width 128
#define lcd_height 64
#define BAND 915E6
#define BUZZER 33
#define PULSADOR 38
#define LED 25


Adafruit_SSD1306 display(lcd_width, lcd_height, &Wire, -1);

String mensaje;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PULSADOR, INPUT);
  Serial.begin(115200);
  Heltec.begin(true, true , true, true, BAND);
   !display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.setRotation(2);
    display.display();
 
  LoRa.beginPacket();
  LoRa.receive();
        }
unsigned long temp=0;
unsigned long temp2=0;
unsigned long temp3=0;

bool Log=false;
bool Log2=false;
bool Log3=true;

bool Recepcion=false;

void loop() {
     int packetSize = LoRa.parsePacket();
      
      Serial.print("PULSADOR: ");
      Serial.println(digitalRead(PULSADOR));
    if (packetSize) {
      mensaje=LoRa.readString();
      Heltec.begin(true, true , true, true, BAND);
    
    Serial.println(" Alerta recibida");
          //while (LoRa.available()) {
    //mensaje=LoRa.readString();
    Serial.println (mensaje);
    
       digitalWrite(LED, HIGH); 
       digitalWrite(BUZZER, HIGH); 
        
bool imp=false;
long temp=millis(),temp2=millis();

  while (digitalRead(PULSADOR)==0){
  if ((imp==false)&&(temp2<millis())){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(5, 23);
    display.println("Alerta");
    display.display();
    imp=true;
    temp=millis()+1000;
    }else{
   if ((imp==true)&&(temp<millis())){
          display.clearDisplay();
          display.setTextSize(2);
          display.setTextColor(SSD1306_WHITE);
          display.setCursor(5, 23);
          display.println(mensaje);
          display.display();
          temp2=millis()+1000;
          imp=false;
      }
    }
    delay(50);
          }
          digitalWrite(BUZZER, LOW);
          digitalWrite(LED, LOW);
       
}   else {
          cont_disp();
          }
}
