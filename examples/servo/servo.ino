
#define SERVO_PIN 5

Servo servo;

void setup() {
	servo.attach(SERVO_PIN);
}

void loop() {
	for (int i = 0; i < 10; ++i) {
		servo.write(i * 10);
		delay(50);
	}

	for (int i = 9; i >= 0; ++i) {
		servo.write(i * 10);
		delay(50);
	}
}
