#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definisi pin dan tipe sensor
#define DHTPIN 2        // Pin data DHT22 terhubung ke pin D2 Arduino
#define DHTTYPE DHT22   // Tipe sensor DHT22
#define LEDPIN 8        // Pin LED terhubung ke pin 8 Arduino

// Inisialisasi sensor DHT dan LCD I2C
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C LCD biasanya 0x27 atau 0x3F

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);
  
  // Inisialisasi sensor DHT
  dht.begin();

  // Inisialisasi LCD
  lcd.init();         
  lcd.backlight();    // Nyalakan backlight LCD
  
  // Inisialisasi LED
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW); // Matikan LED awalnya

  // Tampilkan pesan awal di LCD
  lcd.print("Mengukur...");
}

void loop() {
  // Baca kelembaban dan suhu dari sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Cek apakah ada error dalam pembacaan
  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.print("Error membaca");
    lcd.setCursor(0, 1);
    lcd.print("sensor DHT!");
    return;
  }

  // Tampilkan hasil pada Serial Monitor
  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Tampilkan hasil pada LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Kelembaban: ");
  lcd.print(humidity);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("Suhu: ");
  lcd.print(temperature);
  lcd.print(" *C");

  // Logika pengendalian LED berdasarkan suhu
  if (temperature >= 25.0) {
    digitalWrite(LEDPIN, HIGH); // Nyalakan LED jika suhu >= 25°C
  } else {
    digitalWrite(LEDPIN, LOW);  // Matikan LED jika suhu < 25°C
  }

  // Tunggu 2 detik sebelum pembacaan ulang
  delay(2000);
}