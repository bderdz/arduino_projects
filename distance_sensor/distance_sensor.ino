#define TRIG_PIN 2
#define ECHO_PIN 3
#define GREEN_PIN 6
#define YELLOW_PIN 7
#define RED_PIN 8
#define BUZZ_PIN 12

float duration, distance;

void setup() {
  // SENSOR
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // OUTPUT
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BUZZ_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0343 / 2;

  Serial.println(distance);

  if(distance > 50.0) {
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BUZZ_PIN, LOW);
  } else if(distance > 20) {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(BUZZ_PIN, LOW);
  } else {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(BUZZ_PIN, HIGH);
  }

  delay(100);
}
