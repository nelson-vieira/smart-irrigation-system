// Sensor pins
#define sensorPower 7
#define sensorPin 8

void setup() {
	pinMode(sensorPower, OUTPUT);

	// Initially keep the sensor OFF
	digitalWrite(sensorPower, LOW);

	Serial.begin(9600);
}

void loop() {
	//get the reading from the function below and print it
	int val = readSensor();
	Serial.print("Digital Output: ");
	Serial.println(val);

	// Determine status of our soil moisture situation
	if (val) {
		Serial.println("Status: Soil is too dry - time to water!");
	} else {
		Serial.println("Status: Soil moisture is perfect");
	}

	delay(1000);	// Take a reading every second for testing
					// Normally you shoul take reading perhaps every 12 hours
	Serial.println();
}

//  This function returns the analog soil moisture measurement
int readSensor() {
	digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
	delay(10);              // Allow power to settle
	int val = digitalRead(sensorPin); // Read the analog value form sensor
	digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
	return val;             // Return analog moisture value
}