const byte buttonPin = 7;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 20;
bool lastReading = LOW;
bool buttonState = LOW;

void setup(){
  pinMode(buttonPin, INPUT);  // niente pullup interna
  Serial.begin(9600);
}

void loop(){
  bool reading = digitalRead(buttonPin);
  if (reading != lastReading){
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == HIGH){   // ora HIGH = premuto
        Serial.println("ok");
      }
    }
  }
  lastReading = reading;
}
