#include <ESP8266WiFi.h>
#include <espnow.h>

// Buffer untuk menyimpan pesan yang diterima
char receivedMessage[100];

// Fungsi callback saat data diterima
void onDataRecv(uint8_t *mac_addr, uint8_t *incomingData, uint8_t len) {
  Serial.print("Data diterima dari alamat MAC: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(mac_addr[i], HEX);
    if (i < 5) Serial.print(":");
  }
  Serial.println();

  // Salin data yang diterima ke buffer dan tampilkan
  memcpy(receivedMessage, incomingData, len);
  receivedMessage[len] = '\0';  // Tambahkan null terminator pada akhir pesan
  Serial.print("Pesan: ");
  Serial.println(receivedMessage);
  Serial.println();
}

void setup() {
  Serial.begin(9600);  // Ubah baud rate ke 9600
  WiFi.mode(WIFI_STA);

  // Inisialisasi ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Gagal menginisialisasi ESP-NOW");
    return;
  }

  // Registrasi callback penerimaan
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(onDataRecv);
}

void loop() {
  // Tidak ada operasi di loop
}