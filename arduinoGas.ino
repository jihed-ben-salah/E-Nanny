
int redLed = 13;
int greenLed = 11;
int buzzer = 10;
int GasSensor = A5;
// Your threshold value
int sensorThres = 400;
char data; 
int x;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(GasSensor, INPUT);
  Serial.begin(9600);
}

void loop() {

        data = Serial.read();

        if (data == '0') {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      noTone(buzzer);
      Serial.write('0');
      x=5;
      }
      int analogSensor =analogRead(GasSensor);
    Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (x != 5){
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
    Serial.write('1');
  }
  else 
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
    Serial.write('0');
  }}
  
  
  // Checks if it has reached the threshold value
 

  
  

delay(100);
}
