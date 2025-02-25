const int greenLED = 6;
const int redLED = 7;
const int statusLED = 8;
const int muteButton = 4;
const int potPin = A0;

int potValue = 0;
bool muted = false;

void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(statusLED, OUTPUT);
  
  pinMode(muteButton, INPUT_PULLUP);
  
  digitalWrite(statusLED, HIGH);
}

void loop() {
  potValue = analogRead(potPin);
  bool muteButtonPressed = digitalRead(muteButton) == LOW;

  Serial.print("Potenciometar: "); Serial.print(potValue);
  Serial.print("\tMuted: "); Serial.println(muted);

  if (potValue < 10 || muted) {
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);
  }

  if (potValue > 1000) {
    digitalWrite(greenLED, HIGH); 
  } else {
    digitalWrite(greenLED, LOW);  
  }

  if (muteButtonPressed) {
    muted = !muted;
    delay(200);  
  }

  delay(100);
}
