
#include <SPI.h>
#include <LoRa.h>

// Định nghĩa các chân cho LoRa RA-01H
#define LORA_SS   5U
#define LORA_RST  4U
#define LORA_DIO0 15U

// Định nghĩa các chân SPI
#define SPI_SCK   18U
#define SPI_MOSI  23U
#define SPI_MISO  19U

// Tần số LoRa (921 MHz)
#define LORA_FREQUENCY 921E6

// Hàm khởi tạo LoRa
void lora_begin() {
    // Khởi tạo SPI với các chân đã định nghĩa
    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, LORA_SS);

    // Khởi tạo module LoRa
    LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);

    // Bắt đầu LoRa với tần số 921 MHz
    if (!LoRa.begin(LORA_FREQUENCY)) {
        Serial.println("LoRa initialization failed!");
        while (1); // Dừng chương trình nếu khởi tạo thất bại
    }

    Serial.println("LoRa initialized successfully!");
}

// Hàm nhận packet
void lora_receive_packet() {
    // Kiểm tra xem có packet nào được nhận không
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        // Đọc packet
        Serial.print("Received packet: ");
        while (LoRa.available()) {
            Serial.print((char)LoRa.read());
        }

        // In thông tin RSSI (Received Signal Strength Indicator)
        Serial.print(" with RSSI: ");
        Serial.println(LoRa.packetRssi());
    }
}

// Hàm gửi packet
void lora_send_packet(const char* message) {
    // Chuyển module LoRa sang chế độ truyền (TX)
    LoRa.beginPacket();

    // Gửi chuỗi message
    LoRa.print(message);

    // Kết thúc packet và gửi
    LoRa.endPacket();

    // In thông báo để debug
    Serial.print("Sent packet: ");
    Serial.println(message);
}
