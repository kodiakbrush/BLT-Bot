const int 
PWM_B   = 11,
DIR_B   = 13,
BRAKE_B = 8,
SNS_B   = A1,
SWITCH  = 2;

void setup() {
  // Configure the A output
  
  pinMode(BRAKE_B, OUTPUT);  // Brake pin on channel B
  pinMode(DIR_B, OUTPUT);    // Direction pin on channel B
  pinMode(SWITCH, INPUT); //Input from Limit Switch
  setPwmSwizzler(3, 5, 10, 11); //because swizzles
  // Open Serial communication
  Serial.begin(9600);
  Serial.println("Motor shield DC motor Test:\n");
}

void loop() {
  int readSWITCH = digitalRead(SWITCH);
  if (readSWITCH == HIGH) // if pin 2 reads 5 volts 
  {
    digitalWrite(BRAKE_B,LOW);
    digitalWrite(DIR_B,HIGH);
    analogWrite(PWM_B,50);
    delay(3000);
    analogWrite(PWM_B,0);
    Serial.println("switch switched");
  };
Serial.println(readSWITCH);}
