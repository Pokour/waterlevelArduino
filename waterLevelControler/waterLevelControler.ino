int level = 0;

void setup() {
  Serial.begin(9600);          // SERIAL TX RX AT 9600
  pinMode(13, OUTPUT);         // SET PIN 13 OUTPUT INDICATOR
  pinMode(2, INPUT_PULLUP);    // SET PIN 2 INPUT SENSOR L1
  pinMode(3, INPUT_PULLUP);    // SET PIN 2 INPUT SENSOR L1
  pinMode(4, INPUT_PULLUP);    // SET PIN 2 INPUT SENSOR L1
  pinMode(5, INPUT_PULLUP);    // SET PIN 2 INPUT SENSOR L1
  pinMode(6, OUTPUT);          // SET PIN 6 FOR RELAY OUTPUT
}

void loop() {
  level = 0;
  digitalWrite(13, LOW);       // SET PIN 13 LOW/INDICATOR OFF AT START
  digitalWrite(6, HIGH );

  if (digitalRead(2) == LOW) {
    Serial.println("PIN 2 LOW DETECTED WATER ON LEVEL 1");    // printing at loop started
    level +=1;
  }
  if (digitalRead(3) == LOW) {
    Serial.println("PIN 3 LOW DETECTED WATER ON LEVEL 2");    // printing at loop started
    level +=1;
  }
  if (digitalRead(4) == LOW) {
    Serial.println("PIN 4 LOW DETECTED WATER ON LEVEL 3");    // printing at loop started
    level +=1;
  }
  if (digitalRead(5) == LOW) {
    Serial.println("PIN 5 LOW DETECTED WATER ON LEVEL 4");    // printing at loop started
    level +=1;
    digitalWrite(6, LOW);
  }

  switch (level) {
    case 1:
      Serial.println("LEVEL 1 INDICATOR ON");
      //SWITCH LED ON FOR LEVEL 1
      break;
    case 2:
      Serial.println("LEVEL 2 INDICATOR ON");
      //SWITCH LED ON FOR LEVEL 2
      break;
    case 3:
      Serial.println("LEVEL 3 INDICATOR ON");
      //SWITCH LED ON FOR LEVEL 3
      break;
    case 4:
      Serial.println("LEVEL 4 INDICATOR ON");
      Serial.println("SEND SIGNAL TO RELAY");
      digitalWrite(6, LOW);
      //SWITCH LED ON FOR LEVEL 4
      break;
    default:
      Serial.println("SEND SIGNAL TO RELAY");
      digitalWrite(6, HIGH);
      // if nothing else matches, do the default
      // default is optional
    break;
  }

  delay(500);
    
  
  //  delay(500); // delay half second between numbers


}
