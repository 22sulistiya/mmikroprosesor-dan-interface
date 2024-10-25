#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 13;  // Pin LED built-in Arduino
const int extraLedPin = 12;  // Pin untuk LED tambahan
const float thresholdTemperature = 25.0;  // Ambang suhu yang ingin Anda tentukan

void setup() {
  Serial.begin(9600);
  Serial.println("Sistem Monitoring Suhu");
  lcd.begin(16, 2);
  dht.begin();
  
  pinMode(ledPin, OUTPUT);
  pinMode(extraLedPin, OUTPUT);  // Tentukan pin sebagai OUTPUT untuk LED tambahan
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  Serial.println("Suhu = ");
  Serial.print(t);
  Serial.println(" C");
  Serial.println("Kelembaban = ");
  Serial.print(h);
  Serial.println(" %");

  lcd.setCursor(0, 0);
  lcd.println("Suhu=");
  lcd.print(t);
  lcd.println(" C");
  lcd.setCursor(0, 1);
  lcd.println("Lembab=");
  lcd.print(h);
  lcd.println(" %");

  // Menyalakan LED built-in Arduino jika suhu mencapai ambang tertentu
  if (t >= thresholdTemperature) {
    digitalWrite(ledPin, HIGH);  // Menyalakan LED built-in Arduino
    digitalWrite(extraLedPin, HIGH);  // Menyalakan LED tambahan
  } else {
    digitalWrite(ledPin, LOW);  // Matikan LED built-in Arduino jika suhu tidak mencapai ambang tertentu
    digitalWrite(extraLedPin, LOW);  // Matikan LED tambahan
  }

  delay(1000);  // Tunggu sejenak sebelum membaca suhu kembali
}