#define LED_PIN 10

unsigned long startTime=millis(); 
unsigned long blinkDelay = 500;
int LEDState = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long loopTime=millis();
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 4000)) {
      blinkDelay = data;
    }
  }

  if(loopTime-startTime>blinkDelay){

  if (LEDState == LOW) {
    LEDState = HIGH;
  }
  else {
    LEDState = LOW;
  }
  digitalWrite(LED_PIN, LEDState);
  startTime+=blinkDelay;
}
}
