const byte numeral[10] = 
{
  // 0 = led dalam seven segment yang tidak diberikan tagangan
  // 1 = led dalam seven segment yang diberikan tagangan masukan
  B11111101, // angka 0
  B01100001, // angka 1
  B11011011, // angka 2
  B11110011, // angka 3
  B01100111, // angka 4
  B10110111, // angka 5
  B00111111, // angka 6
  B11100001, // angka 7
  B11111111, // angka 8
  B11100111, // angka 9
};

// pin dari segment dp,G,F,E,D,C,B,A
const int segmentPins[8] = { 5,9,8,7,6,4,3,2};


void setup()
{
  for(int i=0; i < 8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop()
{
  //Seven segment akan memulai dari 0 sampai 10
  //cara kerjanya sistem ditambah 1 dengan delay 1 detik dan ditambah 1 dengan delay 1 detik sampai batas nilai 10.
  for(int i=0; i <= 10; i++)
  {
    showDigit(i);
    delay(1000);
  }
    delay(2000);
  }

void showDigit( int number)
{
  boolean isBitSet;
  for(int segment = 1; segment < 8; segment++)
  {
    if( number < 0 || number > 9)
    {
      isBitSet = 0; // turn off all segments 
    }
    else
    {
    // isBitSet will be true if given bit is 1
    isBitSet = bitRead(numeral[number], segment);
    }
  isBitSet = !isBitSet; //
  digitalWrite( segmentPins[segment], isBitSet);
  }
}
