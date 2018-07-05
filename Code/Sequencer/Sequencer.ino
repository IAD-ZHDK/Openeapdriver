  const int eapPin = 0;
const int ledPin = 1;
const byte potPin_1 = A3;
const byte potPin_2 = A2;
int myInterval = 2000;
int myDuration = 1500;

unsigned long milis;
unsigned long lastMili = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(eapPin, OUTPUT);

  pinMode(potPin_1, INPUT);
  pinMode(potPin_2, INPUT);

};


void loop() {
  delay(20);

  milis = millis();
  float count = milis - lastMili;


  //sequence
  if (count <= myInterval) {
    // set sensor values
    digitalWrite(ledPin, LOW);
    digitalWrite(eapPin, LOW);
    // update values from sensors 
    myInterval = setDelayValues(potPin_1);
    myDuration = setDelayValues(potPin_2);

  } else if (count <= myInterval + myDuration) {

    digitalWrite(ledPin, HIGH);
    digitalWrite(eapPin, HIGH);

  } else {

    lastMili = milis;
  }

};

int setDelayValues(int pin) {
  int temp  = analogRead(pin);
  temp = map(temp, 0, 1023, 0, 5000); // up to 5 seconds  Serial.println(myInterval);
  return temp;
}

