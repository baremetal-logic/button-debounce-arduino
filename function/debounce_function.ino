bool debounceButton(int pin, unsigned long debounceTime){
    static int lastReading = LOW;
    static int buttonState = LOW;
    static unsigned long lastDebounceTime = 0;
    int reading = digitalRead(pin);
    if (reading != lastReading) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceTime) {
        buttonState = reading;
    }
    lastReading = reading;
    return buttonState;
}
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (debounceButton(7, 20)) {
    Serial.println("ok");
  }
}
