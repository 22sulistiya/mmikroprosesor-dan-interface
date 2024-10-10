int led = 9; 
int pinPot = 0;
float potVal = 0;
int angle = 0;

void setup() {
  pinMode(led, OUTPUT); // mengatur lampu led sebagai output
  Serial.begin(9600);
}

void loop () {
  potVal = analogRead(pinPot); // terima masukan nilai dari VR
  angle = (potVal / 1023.0) * 255; // ubah nilai (0-1023) jadi (0-255)
  analogWrite(led, angle); // ubah nilai VR untuk mengatur kecerahan
  Serial.println(angle);
  delay(100);
}
