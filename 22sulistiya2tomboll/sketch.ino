// Pin definisi
const int led1 = 4;
const int led2 = 3;
const int led3 = 2;
const int button1 = 8;  // Tombol untuk running dari kiri ke kanan
const int button2 = 9;  // Tombol untuk running dari kanan ke kiri

int buttonState1 = 0;  // Status tombol 1
int buttonState2 = 0;  // Status tombol 2

void setup() {
  // Atur pin LED sebagai output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Atur pin tombol sebagai input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  // Awal status LED mati
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  // Baca status tombol
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  // Jika tombol pertama ditekan, jalankan LED dari kiri ke kanan
  if (buttonState1 == HIGH) {
    digitalWrite(led1, HIGH);
    delay(300);
    digitalWrite(led1, LOW);

    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led2, LOW);

    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led3, LOW);
  }

  // Jika tombol kedua ditekan, jalankan LED dari kanan ke kiri
  if (buttonState2 == HIGH) {
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led3, LOW);

    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led2, LOW);

    digitalWrite(led1, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
  }
}