
// define the pin to use for the servo
#define SERVO_PIN 5

// declare the servo
Servo servo;

void setup() {
	// attach the pin to the servo, so it knows what wire to
	// use to control the servo
	servo.attach(SERVO_PIN);
}

void loop() {
	for (int i = 0; i < 10; ++i) {
		// write a value to the servo
		// value is in degrees (between 0 and 180 degrees)
		servo.write(i * 10);
		delay(50);
	}

	for (int i = 9; i >= 0; ++i) {
		servo.write(i * 10);
		delay(50);
	}
}
