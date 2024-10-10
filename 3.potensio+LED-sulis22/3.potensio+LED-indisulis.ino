int led = 9; // memilih pin digital untuk lampu led
int pinPot = 0; // memilih pin analog untuk VR
int potVal = 0; // tempat untuk menerima nilai tegangan dari VR

void setup() {
  pinMode(led, OUTPUT); // mengatur lampu led sebagai output
}

void loop () {
  potVal = analogRead(pinPot); // terima masukan nilai dari VR
  potVal = map(potVal, 0, 1023, 0, 255); // ubah nilai (0-1023) jadi (0-255)
  analogWrite(led, potVal); // ubah nilai VR untuk mengatur kecerahan
}