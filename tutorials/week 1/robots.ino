
/* This code is here to simplify a few things for you.
 *
 * You can (and should) use the functions declared below
 * to control your robot. Stick your code in the `setup`
 * and `loop` functions to control the robot.
 *
 * If you want to define variables and things, put them
 * in the section with the setup and loop functions just
 * for clarity.
 */


/* set the speed of the left motor */
/* speed between -255 and 255 inclusive */
void setLeftSpeed(int speed);

/* set the speed of the right motor */
/* speed between -255 and 255 inclusive */
void setRightSpeed(int speed);

/* set the speed of both motors */
/* speeds between -255 and 255 inclusive */
void setSpeeds(int left, int right);


/* set the angle of the tail (in degrees) */
void setTailAngle(int angle);


/* read the distance in front using the ultrasonic sensor */
int readDistance();


/* call this pls */
void initialiseStuff();


/////////////////////////////////////////////////////////////////////


void setup() {
	initialiseStuff();

	/* stick your code here */
}


void loop() {
	/* stick your code here too */
}


/////////////////////////////////////////////////////////////////////
// ignore everything below here, unless you're very interested     //
/////////////////////////////////////////////////////////////////////

#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define TAIL 3
#define ECHO 7
#define TRIGGER 12

Servo tail;

void setMotorSpeed(int INA, int INB, int ENX, int speed) {
	if (speed > 0) {
		digitalWrite(INA, HIGH);
		digitalWrite(INB, LOW);
	}
	else {
		digitalWrite(INA, LOW);
		digitalWrite(INB, HIGH);
		speed = -speed;
	}

	if (speed > 255) speed = 255;

	analogWrite(ENX, speed);
}

void setLeftSpeed(int speed) {
	setMotorSpeed(IN1, IN2, ENA, speed);
}

void setRightSpeed(int speed) {
	setMotorSpeed(IN3, IN4, ENB, speed);
}

void setSpeeds(int left, int right) {
	setLeftSpeed(left);
	setRightSpeed(right);
}

void setTailAngle(int angle) {
	if (angle < 0) angle = 0;
	if (angle > 180) angle = 180;
	tail.write(angle);
}

int readDistance() {

}

void initialiseStuff() {
	Serial.begin(9600);

	pinMode(ECHO, INPUT);
	pinMode(TRIGGER, OUTPUT);
	
	tail.attach(TAIL);

	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);

	pinMode(LED_BUILTIN, OUTPUT);

	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);

	tail.write(0);
}
