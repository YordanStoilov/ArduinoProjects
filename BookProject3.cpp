const int sensorPin = A0;
const double baselineTemp = 22;

void setLightValues(int val1, int val2, int val3) {
  digitalWrite(2, val1);
  digitalWrite(3, val2);
  digitalWrite(4, val3);
}

void setup() {
  Serial.begin(9600);

  for (int pinNum = 2; pinNum < 5; ++pinNum) {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  float voltage = (sensorVal / 1024.0) * 5.0;
  float degreesCelsius = -1 * ((voltage - 0.5) * 100);
  
  Serial.print("\nDegrees: ");
  Serial.print(degreesCelsius);

  if (degreesCelsius < baselineTemp) {
    setLightValues(LOW, LOW, LOW);
  }
  else if (degreesCelsius >= baselineTemp && degreesCelsius <= baselineTemp + 2) {
    setLightValues(HIGH, LOW, LOW);
  }
  else if (degreesCelsius >= baselineTemp + 2 && degreesCelsius <= baselineTemp + 4) {
    setLightValues(HIGH, HIGH, LOW);
  }
  else {
    setLightValues(HIGH, HIGH, HIGH);
  }

  delay(1);
}
