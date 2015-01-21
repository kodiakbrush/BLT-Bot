const int
PWM_B  = 11,
DIR_B  = 13,
BRAKE_B = 8,
SNS_B  = A1,
SWITCH = 2;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  setPwmSwizzler(3, 5, 10, 11);
  pinMode(BRAKE_B, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(SWITCH, INPUT);
  Serial.begin(9600);
  Serial.println("End setup code:\n");
}

void loop() {
  int readSWITCH = digitalRead(SWITCH); 
  // put your main code here, to run repeatedly: 
  Serial.println("Start loop\n");
  
  digitalWrite(BRAKE_B, LOW); //disable brake
  digitalWrite(DIR_B, HIGH); // set initial turning direction
  analogWrite(PWM_B, 255); //run motor B at full speed
  
  if (readSWITCH == HIGH){// if limit switch pressed
    Serial.println("Limit Switch pressed \n");
    analogWrite(PWM_B, 0); //stop motor
    digitalWrite(DIR_B, LOW); // switch turning direction
    delay(1000);
    
    analogWrite(PWM_B, 255); // run that sucker at full speed
    delay(3000);
  }
  counter++;
  Serial.println("This is loop number");
  Serial.println(counter);
  delay(3000);
}
