
int startValue = 9;

int buzzerPin = 8;

// Segment pins: a, b, c, d, e, f, g
int segmentPins[] = {4, 5, 9, 7, 6, 3, 2};
int numSegments = 7;

byte digits[10][7] = {
  {1,1,1,1,1,1,0}, 
  {0,1,1,0,0,0,0}, 
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1} 
};


void showDigit(int n) {
  if (n < 0 || n >= 9) return;

  for (int i = 0; i < numSegments; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup() {
  Serial.begin(9600);


  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  Serial.println("=== Smart Beeping Countdown Starting ===");

  int count = 9;

  while (count >= 1) {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);

    tone(buzzerPin, 1000, 200);

    delay(1000);

    count = count - 1;
  }

  showDigit(0);
  tone(buzzerPin, 1500, 200);

  Serial.println("=== Countdown Complete === ");

}

void loop() {
  

}
