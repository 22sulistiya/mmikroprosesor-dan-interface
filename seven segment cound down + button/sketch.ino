// Definisi pin segmen untuk seven segment puluhan
int segA1 = 2;
int segB1 = 3;
int segC1 = 4;
int segD1 = 5;
int segE1 = 6;
int segF1 = 7;
int segG1 = 8;

// Definisi pin segmen untuk seven segment satuan
int segA2 = 9;
int segB2 = 10;
int segC2 = 11;
int segD2 = 12;
int segE2 = 13;
int segF2 = A0;
int segG2 = A1;

// Definisi pin tombol
int buttonPin = A2;

// Status tombol
bool countdownStarted = false;

// Array untuk menampilkan angka 0-9 pada seven segment
int numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1}   // 9
};

// Fungsi untuk menampilkan angka pada seven segment
void displayNumber(int segPins[], int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], numbers[num][i]);  // Aktifkan segmen sesuai dengan angka
  }
}

void setup() {
  // Set semua pin segmen puluhan sebagai output
  for (int i = segA1; i <= segG1; i++) {
    pinMode(i, OUTPUT);
  }

  // Set semua pin segmen satuan sebagai output
  for (int i = segA2; i <= segG2; i++) {
    pinMode(i, OUTPUT);
  }

  // Set pin tombol sebagai input
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Cek apakah tombol ditekan
  if (digitalRead(buttonPin) == HIGH && !countdownStarted) {
    countdownStarted = true;  // Set countdown dimulai
    delay(200);               // Debounce tombol
  }

  // Jika countdown sudah dimulai
  if (countdownStarted) {
    // Countdown dari 20 ke 0
    for (int i = 20; i >= 0; i--) {
      int tens = i / 10;      // Angka puluhan
      int ones = i % 10;      // Angka satuan

      // Tampilkan angka puluhan
      int tensPins[] = {segA1, segB1, segC1, segD1, segE1, segF1, segG1};
      displayNumber(tensPins, tens);

      // Tampilkan angka satuan
      int onesPins[] = {segA2, segB2, segC2, segD2, segE2, segF2, segG2};
      displayNumber(onesPins, ones);

      delay(1000);           // Tampilkan angka selama 1 detik
    }

    countdownStarted = false; // Reset countdown setelah selesai
  }
}