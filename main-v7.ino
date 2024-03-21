int previousSensorValue = LOW;
const int ledDuration = 300;
int previousMillis = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  //reading the state of the push button
  int sensorVal = digitalRead(2);
  //if the sensor value is changing
  if (sensorVal != previousSensorValue) {
    //and if the PIR sensor detected motion
    if (sensorVal == HIGH){
      Serial.println("Motion detected");
      digitalWrite(13, HIGH);
    }
    else {
      digitalWrite(13, LOW);
    }
    previousSensorValue = sensorVal;
    previousMillis = millis();
  }
  
  if (millis() - previousMillis >= ledDuration) {
    digitalWrite(13, LOW);
  } 
}
