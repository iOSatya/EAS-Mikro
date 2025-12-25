// --- iMCLab FINAL HARDWARE CONFIG ---

// MOTOR PINS
const int MOTOR_PIN_A = 26;
const int MOTOR_PIN_B = 27;

// ENABLE PINS (We turn on BOTH 12 and 14 to be safe)
const int ENABLE_PIN_1 = 12; 
const int ENABLE_PIN_2 = 14;

// SENSOR CANDIDATES
const int SENSOR_PINS[] = {34, 35, 36, 39};

void setup() {
  Serial.begin(115200);
  
  // Setup Motor Pins
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);
  pinMode(ENABLE_PIN_1, OUTPUT);
  pinMode(ENABLE_PIN_2, OUTPUT);
  
  // Setup Sensor Pins
  for(int i=0; i<4; i++){
    pinMode(SENSOR_PINS[i], INPUT);
  }

  Serial.println("--- MOTOR RESTARTING ---");
}

void loop() {
  // 1. TURN ON MOTOR (Corrected for Pin 12)
  digitalWrite(MOTOR_PIN_A, HIGH);
  digitalWrite(MOTOR_PIN_B, LOW);
  
  // "Press the gas" on both possible pins
  digitalWrite(ENABLE_PIN_1, HIGH); 
  digitalWrite(ENABLE_PIN_2, HIGH); 

  // 2. READ SENSORS
  // We want to see if the "0" flips to "1" when the hole passes by
  int s1 = digitalRead(34);
  int s2 = digitalRead(35);
  int s3 = digitalRead(36);
  int s4 = digitalRead(39);

  Serial.print("Readings [34,35,36,39]: ");
  Serial.print(s1); Serial.print(" | ");
  Serial.print(s2); Serial.print(" | ");
  Serial.print(s3); Serial.print(" | ");
  Serial.println(s4);
  
  // Small delay so we don't flood the screen, 
  // but fast enough to catch the hole
  delay(50); 
}