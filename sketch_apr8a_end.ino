int redLed1 = 3;
int redLed2 = 4;
int greenLed = 8;
int buzzer1 = 5; //PWM (~) pin
int buzzer2 = 6; //PWM (~) pin
int gasPin = A0;
int flamePin = 2;
// Your threshold value
int gasSensorThres = 100;

void setup() {
  pinMode(redLed1, OUTPUT);  
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(gasPin, INPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}
void loop() {
  int gasSensor = analogRead(gasPin);
  int flameSensor = digitalRead(flamePin);
 
  Serial.print("gasPin Value: ");
  Serial.println(gasSensor);
  Serial.print("flamePin Value: ");
  Serial.println(flameSensor);
  delay(1000);
  
  if (gasSensor > gasSensorThres  && flameSensor==LOW){
   digitalWrite(redLed1, HIGH);
    tone(buzzer1, 5000); //the buzzer sound frequency at 5000 Hz
    digitalWrite(redLed2, HIGH);
    tone(buzzer2, 5000); //the buzzer sound frequency at 5000 Hz
    digitalWrite(greenLed, LOW);
  }
   else if (gasSensor > gasSensorThres)
  {
    digitalWrite(redLed1, HIGH);
    tone(buzzer1, 5000); //the buzzer sound frequency at 5000 Hz
    digitalWrite(redLed2, LOW);
    noTone(buzzer2);
    digitalWrite(greenLed, LOW);
  }
  else if (flameSensor==LOW){ // HIGH MEANS NO FLAME
    digitalWrite(redLed1, LOW);
    noTone(buzzer1);
    digitalWrite(redLed2, HIGH);
    tone(buzzer2, 5000); //the buzzer sound frequency at 5000 Hz
    digitalWrite(greenLed, LOW);
    }
  
  else
  {
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    noTone(buzzer1);
    noTone(buzzer2);
    digitalWrite(greenLed, HIGH);    
  }
}