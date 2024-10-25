#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10     // Pin SDA dihubungkan ke pin D10 Arduino
#define RST_PIN 9     // Pin RST dihubungkan ke pin D9 Arduino

MFRC522 rfid(SS_PIN, RST_PIN); // Inisialisasi instance dari MFRC522

void setup() {
  Serial.begin(9600);  // Inisialisasi komunikasi serial
  SPI.begin();         // Mulai komunikasi SPI
  rfid.PCD_Init();     // Inisialisasi modul RFID
  Serial.println("Scan a card...");
}

void loop() {
  // Cek apakah ada kartu baru yang didekatkan ke reader RFID
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Cek apakah bisa membaca kartu
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Tampilkan UID kartu
  Serial.print("UID Kartu: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Hentikan komunikasi dengan kartu
  rfid.PICC_HaltA();
}