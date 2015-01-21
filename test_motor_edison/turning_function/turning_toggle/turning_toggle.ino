//declare ints for Motor B
const int 
PWM_B   = 11,
DIR_B   = 13,
BRAKE_B = 8,
SNS_B   = A1,
SWITCH = 2;
boolean CurrentDirection = HIGH;
//set up for running motor B
void setup() {
  setPwmSwizzler(3, 5, 10, 11); //because swizzles
  // Configure the B output
  pinMode(BRAKE_B, OUTPUT);  // Brake pin on channel B
  pinMode(DIR_B, OUTPUT);    // Direction pin on channel B
  pinMode(SWITCH, INPUT);    //Switch Input
}
void loop() {
  digitalWrite(DIR_B,ChangeDirection()); //Run Direction Change to check switch
  digitalWrite(BRAKE_B, LOW);  // setting brake LOW disable motor brake
  analogWrite(PWM_B, 50);     // Set the speed of motor b, 255 is the maximum value
  delay(500);
  
}
boolean ChangeDirection() {
  if(digitalRead(SWITCH)==HIGH){
    if(CurrentDirection==LOW){
      return HIGH;}
    else{
      return LOW;}
  }
  else{
    return CurrentDirection;} 
}
