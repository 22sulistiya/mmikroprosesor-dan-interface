#include <ESP8266WiFi.h>
#include <WiFiManager.h>

void setup() {
    Serial.begin(115200);
    WiFiManager wifiManager;

    // Mengatur portal konfigurasi secara manual tanpa auto connect
    Serial.println("Memulai portal konfigurasi...");
    wifiManager.startConfigPortal("ESP indi  dan sulis ");

    // Setelah pengguna mengatur WiFi, perangkat akan mencoba konek
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Terhubung ke WiFi!");
    } else {
        Serial.println("Gagal terhubung ke WiFi.");
    }
}

void loop() {
    // Kode aplikasi utama Anda di sini
}