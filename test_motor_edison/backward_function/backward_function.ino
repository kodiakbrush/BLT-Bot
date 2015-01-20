// Code to run robot backward for specified time interval
// First sets up function for running motor backward
// main loop at bottom


//declare ints for Motor A
const int 
PWM_A   = 3,
DIR_A   = 12,
BRAKE_A = 9,
SNS_A   = A0;

//set up for running motor A
void setup() {
  setPwmSwizzler(3,5,10,11);
  // Configure the A output
  pinMode(BRAKE_A, OUTPUT);  // Brake pin on channel A
  pinMode(DIR_A, OUTPUT);    // Direction pin on channel A

  // Open Serial communication
  Serial.begin(9600);
}

// -----------------FUNCTION loop for running motor A backward-------------------- //

void Backward(int time_back) // Set the outputs to run the motor backward
{
  digitalWrite(BRAKE_A, LOW);  // setting againg the brake LOW to disable motor brake
  digitalWrite(DIR_A, LOW);    // now change the direction to backward setting LOW the DIR_A pin
  digitalWrite(PWM_A, 255);  // runs the motor at full speed

  delay (time_back);

  analogWrite(PWM_A, 0); // turn off power to motor A
  digitalWrite(BRAKE_A, HIGH); // raise the brake 
}


// ------------------- MAIN LOOP ---------------------------- //
void loop()
{
  Backward(0);
}
