#define PIN_GREEN 6
#define PIN_ORANGE 5
#define PIN_RED 3
#define PIN_BUTTON 2
#define PIN_POT A0
int valeurDuPotentiometre;
volatile bool isClicked=false;
void onButtonClicked(){
  isClicked=true;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_ORANGE, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), onButtonClicked, RISING);
  valeurDuPotentiometre = map(analogRead(PIN_POT), 0, 1023, 0, 255);
  analogWrite(PIN_GREEN, valeurDuPotentiometre);
}

void loop() {
  if (isClicked == true) {
    sequencePieton(800);
    isClicked=false;
  } else {
    delay(1000);
  }
}

void sequencePieton(uint16_t tempsRepos) {
  delay(500);
  analogWrite(PIN_ORANGE, valeurDuPotentiometre);
  digitalWrite(PIN_GREEN, LOW);
  delay(tempsRepos);
  analogWrite(PIN_RED, valeurDuPotentiometre);
  digitalWrite(PIN_ORANGE, LOW);
  delay(tempsRepos);
  analogWrite(PIN_GREEN, valeurDuPotentiometre);
  digitalWrite(PIN_RED, LOW);
  delay(tempsRepos);
}