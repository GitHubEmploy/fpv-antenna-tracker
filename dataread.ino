const int analogPin = A0;  // connect telem output to A0
float voltage = 0;
float power_dBm = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(analogPin);
  voltage = sensorValue * (5.0 / 1023.0); // analog reading -> voltage
  power_dBm = voltage * (60 / 2.5) - 95; // untuned conversion factor

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Power: ");
  Serial.print(power_dBm);
  Serial.println(" dBm");

  delay(1000); // delay to read easier
}
