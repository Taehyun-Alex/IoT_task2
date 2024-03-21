int previousSensorValue = HIGH;
const int ledDuration = 300;
int previousMillis = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop()
{
  //reading the state of the push button
  int sensorVal = digitalRead(2);
  
  if (sensorVal != previousSensorValue) {
    Serial.println(sensorVal);
    previousSensorValue = sensorVal;
    digitalWrite(13, HIGH);
    previousMillis = millis();
  }
  
  if (millis() - previousMillis >= ledDuration) {
    digitalWrite(13, LOW);
  }
}
