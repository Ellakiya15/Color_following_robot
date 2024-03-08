// Define color sensor pins
#define S0 4
#define S1 5
#define S2 7
#define S3 6
#define sensorOut 8
int motor1pin1 = 13; 
int motor1pin2 = 2;
int motor2pin1 = 10;
int motor2pin2 = 12;
 // put your setup code here, to run once:
// Calibration Values
// *Get these from Calibration Sketch
//int redMin = 52; // Red minimum value
//int redMax = 185; // Red maximum value
//int greenMin = 80; // Green minimum value
//int greenMax = 170; // Green maximum value
//int blueMin = 86; // Blue minimum value
//int blueMax = 180; // Blue maximum value

//int redMin = 32; // Red minimum value
//int redMax = 191; // Red maximum value
//int greenMin = 73; // Green minimum value
//int greenMax = 237; // Green maximum value
//int blueMin = 59; // Blue minimum value
//int blueMax = 201;

int redMin =22;
int redMax = 211;
int greenMin = 18;
int greenMax = 267;
int blueMin = 26;
int blueMax = 193;

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Variables for final Color values
int redValue;
int greenValue;
int blueValue;
int enA =9;
int enB=11;
void setup() {
	// Set S0 - S3 as outputs
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);

	// Set Sensor output as input
	pinMode(sensorOut, INPUT);

	// Set Frequency scaling to 100%
	digitalWrite(S0,HIGH);
	digitalWrite(S1,HIGH);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,  OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  //(Optional)
  pinMode(enA,  OUTPUT); 
  pinMode(enB, OUTPUT);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
	// Setup Serial Monitor
	Serial.begin(9600);
}

void loop() {
	// Read Red value
	redPW = getRedPW();
	// Map to value from 0-255
	redValue = map(redPW, redMin,redMax,255,0);
	// Delay to stabilize sensor
	delay(200);

	// Read Green value
	greenPW = getGreenPW();
	// Map to value from 0-255
	greenValue = map(greenPW, greenMin,greenMax,255,0);
	// Delay to stabilize sensor
	delay(200);

	// Read Blue value
	bluePW = getBluePW();
	// Map to value from 0-255
	blueValue = map(bluePW, blueMin,blueMax,255,0);
	// Delay to stabilize sensor
	delay(200);

	// Print output to Serial Monitor
	Serial.print("Red = ");
	Serial.print(redValue);
	Serial.print(" - Green = ");
	Serial.print(greenValue);
	Serial.print(" - Blue = ");
	Serial.println(blueValue);
  
  
  if( blueValue > greenValue && blueValue > redValue)
  {
    Serial.println("Blue Colour is detected!");
    while(303<blueValue<334){    
      Serial.println("FORWARD...");
      forward();
      break;
    }
  }
  else if( greenValue > blueValue && greenValue > redValue )
  {
    Serial.println("Green Colour is detected!");
    stop();
  }
  else if(redValue > greenValue && redValue < blueValue)
  {
    Serial.println("Red Colour is detected!");
    stop();
  }
  
  else{
    Serial.println("Stopped");
    stop();
  }
}
  /*else if( blueValue > greenValue && blueValue > redValue ){
    Serial.println("Blue Colour is detected!");
  }
  else if( greenValue > blueValue && greenValue > redValue ){
    Serial.println("Green Colour is detected!");
  }
*/

// Function to read Red Pulse Widths
int getRedPW() {
	// Set sensor to read Red only
	digitalWrite(S2,LOW);
	digitalWrite(S3,LOW);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}
// Function to read Green Pulse Widths
int getGreenPW() 
{
	// Set sensor to read Green only
	digitalWrite(S2,HIGH);
	digitalWrite(S3,HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}
// Function to read Blue Pulse Widths
int getBluePW() {
	// Set sensor to read Blue only
	digitalWrite(S2,LOW);
	digitalWrite(S3,HIGH);
	// Define integer to represent Pulse Width
	int PW;
	// Read the output Pulse Width
	PW = pulseIn(sensorOut, LOW);
	// Return the value
	return PW;
}

void forward(){
  
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(enA,255);
  
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(enB,255);
}

void turn(){
  analogWrite(enA,255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  analogWrite(enB,255);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void stop(){
  analogWrite(enA,0);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2,HIGH);
  analogWrite(enB,150);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void backward(){
  
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(enA,255);
  
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  analogWrite(enB,255);
}
