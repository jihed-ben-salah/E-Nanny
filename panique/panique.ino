

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPinRouge =  13;
const int ledPinVert = 12;// the number of the LED pin
char data;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  
 
  pinMode(ledPinVert, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    Serial.write('1');
  }
if(Serial.available())
{
 data= Serial.read();
    if( data == 1 )
    {
      digitalWrite(ledPinVert,HIGH);
      delay(1000);
       digitalWrite(ledPinVert,LOW);
    }
  } 
   
  
  
}
