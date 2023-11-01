// Define the analog pin, the LM35's Vout pin is connected to
#define sensorPin A0

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Get the voltage reading from the LM35
  int reading = analogRead(sensorPin);

  // Convert that reading into milivolts
  float voltage = reading * (5000.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = voltage / 10.0;
  // Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(voltage);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");
  
  // Print the temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("F");

  delay(1000); // wait a second between readings
}
