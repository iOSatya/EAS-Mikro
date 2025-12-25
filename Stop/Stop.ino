void setup() {
  // Define all the motor pins we found
  pinMode(26, OUTPUT); 
  pinMode(27, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);

  // Turn them ALL off
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
}

void loop() {
  // Do nothing
}