#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define TILT_PIN 10

int segments[] = {A, B, C, D, E, F, G};
int digits[6][7] = {
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
};
int dice_result;

void print_digit(int d) {
  for(int i = 0; i < 7; i++) {
    digitalWrite(segments[i], digits[d - 1][i]);
  }
}

void clear_display() {
  for(int i = 0; i < 7; i++) {
    digitalWrite(segments[i], LOW);
  }
}

void animate_dice() {
  for(int i = 0; i < 3; i++) {
    for(int j = 1; j < 7; j++) {
      clear_display();
      print_digit(j);
      delay(50);
    }
    
    clear_display();
  }
}

void animate_idle() {
  for(int i = 0; i < 7; i++) {
    digitalWrite(segments[i], HIGH);
    delay(50);
    digitalWrite(segments[i], LOW);
  }
}

void blink_digit(int d) {
  for(int i = 0; i < 4; i++) {
    print_digit(d);
    delay(100);
    clear_display();
    delay(100);
  }

  clear_display();
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(TILT_PIN, INPUT_PULLUP);

  Serial.begin(9600);

  animate_idle();
  blink_digit(6);
}



void loop() {
  if(digitalRead(TILT_PIN) == HIGH) {
    clear_display();
    animate_dice();

    dice_result = random(1, 7);
    Serial.println(dice_result);

    blink_digit(dice_result);
    print_digit(dice_result);
  }

  delay(100);
}
