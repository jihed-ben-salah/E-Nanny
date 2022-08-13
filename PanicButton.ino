const int BUTTON = 10;
const int LED = 13;
int BUTTONstate = 0;
char data;
char data1;
void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{//if(Serial.available())
//{
  data1=Serial.read(); 
  BUTTONstate = digitalRead(BUTTON);
     if ( data1 == '2')
  {
     digitalWrite(LED, HIGH);
     delay(10000);
  }

  if (BUTTONstate == HIGH)
  {
   
    Serial.write('1'); 
   
  } 
  else
  {
    digitalWrite(LED, LOW);
  }
}
//}
