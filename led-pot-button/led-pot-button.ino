#define PIN_GREEN 6
#define PIN_ORANGE 5
#define PIN_RED 3
#define PIN_BUTTON 2
#define PIN_POT A0
int valeurDuPotentiometre;
volatile bool isClicked = false;
void onButtonClicked() {
  isClicked = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("initialization en cours");

  Serial.print("Saisir votre nom:");
  while (Serial.available() == 0) { delay(500); }
  String prenom=Serial.readString();
  Serial.print("Bonjour ");
  Serial.println(prenom); 


  /*char buffer[32];
  char itter = 0;
  do {
    buffer[itter++] = Serial.read();
  } while (itter < 31 && Serial.available());
  Serial.flush();
  buffer[itter] = '\0';*/
  
  
   pinMode(PIN_GREEN, OUTPUT);
  Serial.print('.');
  pinMode(PIN_ORANGE, OUTPUT);
  Serial.print('.');
  pinMode(PIN_RED, OUTPUT);
  Serial.print('.');
  pinMode(PIN_BUTTON, INPUT);
  Serial.print('.');
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), onButtonClicked, RISING);
  Serial.println('.');
  valeurDuPotentiometre = map(analogRead(PIN_POT), 0, 1023, 0, 255);
  Serial.print(valeurDuPotentiometre, DEC);
  Serial.print(' ');
  Serial.print(valeurDuPotentiometre, HEX);
  Serial.print(' ');
  Serial.print(valeurDuPotentiometre, OCT);
  Serial.print(' ');
  Serial.print(valeurDuPotentiometre, BIN);
  Serial.println("\nAllumage feu vert");
  Serial.print('c');
  Serial.write(67);
  analogWrite(PIN_GREEN, valeurDuPotentiometre);
}

void loop() {
  if (isClicked == true) {
    sequencePieton(800);
    isClicked = false;
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