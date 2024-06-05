#include "BeanMPX.h"
#define RX_BUFFER_SIZE 20
BeanMPX bean;

uint8_t engTemp[]  =  {0x62, 0x2C, 0x00}; // Engine Temp 90-255 deadzone 165-212
uint8_t lights[] = {0x62, 0xD4, 0x00}; // BATT, OIL --11---- (32,16) 
uint32_t timer = 0;
uint32_t current_millis = 0;
uint8_t bean_rx_buffer[RX_BUFFER_SIZE];
uint8_t bean_rx_index = 0;
uint8_t g = 1;
float t = 0;

void setup() {
  pinMode(9, INPUT_PULLUP);     //Oil Pressure Light
  pinMode(10, INPUT_PULLUP);     //Charge Light
  Serial.begin(115200);
  while (!Serial) {;}  
  bean.begin(8, 9); //RX pin, TX pin
}

void loop() { 
  current_millis = millis();
  if (bean.available()) {
   bean.getMsg(bean_rx_buffer, RX_BUFFER_SIZE);
    Serial.print((char)bean_rx_buffer[1]); 
    Serial.print(" ");
   for (int i = 2; i < bean_rx_buffer[0]+2; i++) {
      if (bean_rx_buffer[i] < 0x10) {
        Serial.print(0, HEX); 
      }
      Serial.print(bean_rx_buffer[i], HEX); 
      Serial.print(" ");    
    }    
    Serial.print("\n");    
    memset(bean_rx_buffer, 0, RX_BUFFER_SIZE); 
   }  
    if (current_millis - timer > 1000) {
    if (!bean.isBusy()) {  

             
//Does the temp gauge Algo is 75000/(ADC+300)).... ADC 0-1023 is 0-5v
//Engine Temp Gauge moves 90-255 but normal range deadzone 165-212
      t = analogRead(A7);  //read temp sensor voltage on analogue pin 2
      t = 75000/(t+300);
      engTemp[2] = t;
      if (engTemp[2]==213){engTemp[2]=214;} // fixes weird needle drop at 213h
      bean.sendMsg(engTemp, sizeof(engTemp));
      Serial.print(analogRead(A2));
      Serial.print(" ADC is hex value "); 
      Serial.print(engTemp[2]);
      Serial.print("\n");

      delay(50);
           
//Does the warning lights
      g = 0;  
      if (digitalRead(9) ==LOW){g=g+16;}   //Oil Pressure Light
      if (digitalRead(10) ==LOW){g=g+32;}   //Charge Light
      lights[2] = g;    
      bean.sendMsg(lights, sizeof(lights));
      Serial.print(digitalRead(9));
      Serial.print(" OILd11 - BATTd12 "); 
      Serial.print(digitalRead(10));
      Serial.print("\n");   

      timer = current_millis;
    }  
      
  } 
}
