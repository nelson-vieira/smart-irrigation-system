// C++ code
//
#include <Servo.h>
int moisture = 0;
int pos = 0;
Servo servo;

void setup()
{
	pinMode(A0, OUTPUT);
	pinMode(A1, INPUT);
	Serial.begin(9600);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	servo.attach(7);
}

void loop()
{
	// Apply power to the soil moisture sensor
	digitalWrite(A0, HIGH);
	delay(10); // Wait for 10 millisecond(s)
	moisture = analogRead(A1);
	// Turn off the sensor to reduce metal corrosion
	// over time
	digitalWrite(A0, LOW);
	Serial.println(moisture);
	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	digitalWrite(10, LOW);
	digitalWrite(11, LOW);
	digitalWrite(12, LOW);
	if (moisture < 200)
	{
		digitalWrite(12, HIGH);
	}
	else
	{
		if (moisture < 400)
		{
			digitalWrite(11, HIGH);
		}
		else
		{
			if (moisture < 600)
			{
				digitalWrite(10, HIGH);
			}
			else
			{
				if (moisture < 800)
				{
					digitalWrite(9, HIGH);
				}
				else
				{
					digitalWrite(8, HIGH);
				}
			}
		}
	}
	ativaServo(moisture);
	delay(100); // Wait for 100 millisecond(s)
}

void ativaServo(int moist)
{
	//   if(moist<100){
	//     servo.write(90);
	//   }
	//   else{
	//     servo.write(0);
	//   }
	if (moist < 100)
	{
    servo.write(180);
    delay(5);
		//for (pos = 0; pos <= 180; pos += 1)
		//{
			// tell servo to go to position in variable 'pos'
			//servo.write(pos);
			// wait 15 ms for servo to reach the position
			//delay(5); // Wait for 15 millisecond(s)
		//}
	}
	else
	{
		servo.write(0);
		// for (pos = 180; pos >= 0; pos -= 1)
		// {
		// 	// tell servo to go to position in variable 'pos'
		// 	servo.write(pos);
		// 	// wait 15 ms for servo to reach the position
		// 	delay(5); // Wait for 15 millisecond(s)
		// }
	}
}
