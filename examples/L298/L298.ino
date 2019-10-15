
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

void setup() {
	/* set all the pins to output mode */
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);

	/* start off with low written to make sure the motors are off */
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);

	/* set a motor to "on" */
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
	analogWrite(ENA, 255);

	/* wait a lil' bit */
	delay(1000);

	/* stop the motor */
	digitalWrite(IN1, LOW);

	/* set the other motor to spin at half speed in reverse */
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
	analogWrite(ENB, 128);

	/* wait a lil' bit */
	delay(1000);

	/* stop the other motor using a different method */
	analogWrite(ENB, 0);
}

void loop() {
	/* do nothing */
}
