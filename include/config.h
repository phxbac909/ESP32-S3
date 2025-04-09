#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

// WiFi
extern const char* SSID;
extern const char* PASSWORD;

// Socket
extern const int SERVER_PORT;
extern const char* TARGET_IP;
extern const int TARGET_PORT;

// Bluetooth
extern const char* BT_NAME;

extern  uint8_t MAC_ADDRESS[6];  // Địa chỉ MAC cho Ethernet
extern const int ETHERNET_CS_PIN;     // Chân CS cho HR961160C
extern const int ETHERNET_SPI_CLK;    // Chân SPI CLK
extern const int ETHERNET_SPI_MOSI;   // Chân SPI MOSI
extern const int ETHERNET_SPI_MISO;   // Chân SPI MISO
extern const int ETHERNET_RESET;   // Chân RESET cho HR961160C
extern const int ETHERNET_LAN_INT ;   // Chân LAN INT
#endif