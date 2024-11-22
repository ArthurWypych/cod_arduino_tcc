int average = 0;
int emg_val = 0;
int amp_val = 0;
int threshold = 0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT); // air pumps
  pinMode(10, OUTPUT); // valve

}

void loop() {
  // put your main code here, to run repeatedly:
  emg_val = analogRead(A0);
  amp_val = emg_val * 3;
  threshold = 90 * 3;

  average = 0;
  for (int i=0; i < 100; i++) {
  average = average + amp_val;
  }

  Serial.println(average);
  average = average/100;

  if (average >= threshold) {
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    delay(1500);
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(10, HIGH);
  }
    
}
