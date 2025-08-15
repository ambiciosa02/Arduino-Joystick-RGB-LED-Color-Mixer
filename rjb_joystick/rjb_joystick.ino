// Joystick pins
#define VRx A0
#define VRy A1
#define SW  2

// RGB pins
#define RED_PIN    9
#define GREEN_PIN 10
#define BLUE_PIN  11

int red = 128, green = 128, blue = 128;
int mode = 0; // 0 = red, 1 = green, 2 = blue

void setup() {
  pinMode(SW, INPUT_PULLUP); // Joystick button
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}

void loop() {
  int x = analogRead(VRx);
  int y = analogRead(VRy);

  // Read switch press
  if (digitalRead(SW) == LOW) {
    mode = (mode + 1) % 3; // cycle mode
    delay(300); // debounce
  }

  // Adjust selected color
  int delta = 0;
  if (y > 600) delta = 5;
  if (y < 400) delta = -5;

  switch (mode) {
    case 0:
      red = constrain(red + delta, 0, 255);
      break;
    case 1:
      green = constrain(green + delta, 0, 255);
      break;
    case 2:
      blue = constrain(blue + delta, 0, 255);
      break;
  }

  // Output colors
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);

  // Debug info
  Serial.print("R: "); Serial.print(red);
  Serial.print(" G: "); Serial.print(green);
  Serial.print(" B: "); Serial.println(blue);

  delay(100);
}
