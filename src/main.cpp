#include <Arduino.h>
#include "config.h"
#include <EthernetTask.h>

void connectWiFi(); 
void checkWiFi();      
void startSocketTasks(); 
void startBluetooth(); 
void startEthernet();   

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting ESP32...");
  connectWiFi();
  startSocketTasks();
 // startBluetooth();
//  startEthernet();
}

void loop() {
 // checkWiFi();
 // delay(5000);
}

