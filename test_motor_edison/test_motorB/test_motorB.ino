const int
PWM_B  = 11,
DIR_B  = 13,
BRAKE_B = 8,
SNS_B  = A1;

void setup() {
  // Configure the A output
  setPwmSwizzler(3, 5, 10, 11);
  pinMode(BRAKE_B, OUTPUT);
  pinMode(DIR_B, OUTPUT);

  // Open Serial communication
  Serial.begin(9600);
  Serial.println("Motor shield DC motor Test:\n");
}

void loop() {

// Set the outputs to run the motor forward
  digitalWrite(BRAKE_B, LOW);  // setting brake LOW disable motor brake
  digitalWrite(DIR_B, HIGH); 
  
  analogWrite(PWM_B, 255);

  delay(1000);                 // hold the motor at full speed for 5 seconds
  Serial.print("current consumption at full speed: ");
  Serial.println(analogRead(SNS_B));

// Brake the motor

  Serial.println("Start braking\n");
  // raising the brake pin the motor will stop faster than the stop by inertia
  digitalWrite(BRAKE_B, HIGH);  // raise the brake

  delay(1000);

// Set the outputs to run the motor backward

  Serial.println("Backward");

  digitalWrite(BRAKE_B, LOW);  // setting againg the brake LOW to disable motor brake
  digitalWrite(DIR_B, LOW);    // now change the direction to backward setting LOW the DIR_A pin

  analogWrite(PWM_B, 255);     // Set the speed of the motor

  delay(1000);
  Serial.print("current consumption backward: ");
  Serial.println(analogRead(SNS_B));

  // now stop the motor by inertia, the motor will stop slower than with the brake function
  analogWrite(PWM_B, 0);       // turn off power to the motor

  Serial.print("current brake: ");
  Serial.println(analogRead(A1));

  Serial.println("End of the motor shield test with DC motors. Thank you!");


  Serial.println("Start braking\n");
  // raising the brake pin the motor will stop faster than the stop by inertia
  digitalWrite(BRAKE_B, HIGH);  // raise the brake

  delay(500);

  while(1);
}
