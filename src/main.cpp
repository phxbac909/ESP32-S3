#include <Arduino.h>
#include "config.h"
#include <EthernetTask.h>

void connectWiFi(); 
void checkWiFi();      
void startSocketTasks(); 

void startBluetooth(); 

void startEthernet();  

void lora_begin();
void lora_send_packet(const char* message); 
void lora_receive_packet();

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting ESP32...");
  lora_begin();
}

void loop() {
  lora_send_packet("Hello , I am ESP32 S3");
 // checkWiFi();
 delay(5000);
}

