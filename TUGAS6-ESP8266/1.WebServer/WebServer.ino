#include <ESP8266WiFi.h>

const char *ssid = "pengen ga";
const char *password = "sulissssss";

WiFiServer server(80);

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    // Tunggu sampai ESP8266 terhubung ke WiFi
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Menghubungkan...");
    }

    // Tampilkan alamat IP setelah terhubung
    Serial.println("Terhubung ke WiFi!");
    Serial.print("Alamat IP ESP8266: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("Client connected");
        client.println("<html><body><h1>Selamat Datang di Web Sulis dan Indi!</h1></body></html>");
        delay(1);
        client.stop();
        Serial.println("Client disconnected");
    }
}