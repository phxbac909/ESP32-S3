#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>
#include "EthernetTask.h"

// Định nghĩa chân kết nối với W5500
#define ETHERNET_CS_PIN     20 
#define ETHERNET_SPI_CLK    3 
#define ETHERNET_SPI_MOSI   9 
#define ETHERNET_SPI_MISO   46


// Cấu hình MAC Address giả định (cần chỉnh sửa nếu cần)
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetClient client;

// Task chạy trong luồng riêng
void EthernetTask(void *pvParameters) {
    Serial.println("Khởi tạo Ethernet...");
  
    
    // Thiết lập SPI
    SPI.begin(ETHERNET_SPI_CLK, ETHERNET_SPI_MISO, ETHERNET_SPI_MOSI, ETHERNET_CS_PIN);
    Ethernet.init(ETHERNET_CS_PIN);


    // Thử DHCP
    if (Ethernet.begin(mac) == 0) {
        Serial.println("Lấy IP từ DHCP thất bại, thử đặt IP tĩnh...");
        Ethernet.begin(mac, IPAddress(192, 168, 1, 100));
    }

    Serial.print("Địa chỉ IP: ");
    Serial.println(Ethernet.localIP());

    while (true) {
        if (Ethernet.hardwareStatus() == EthernetNoHardware) {
            Serial.println("Không tìm thấy module W5500!");
        } else if (Ethernet.linkStatus() == LinkOFF) {
            Serial.println("Cáp mạng chưa cắm hoặc mất kết nối!");
        } else {
            Serial.println("Ethernet hoạt động bình thường.");
        }
        vTaskDelay(pdMS_TO_TICKS(5000));  // Chờ 5 giây rồi kiểm tra lại
    }
}

// Hàm gọi từ main.cpp để khởi động task
void startEthernet2() {
    xTaskCreatePinnedToCore(
        EthernetTask, "EthernetTask", 4096, NULL, 1, NULL, 1
    );
}
