int ldr=13;
int m1=8;
int m2=9;
int m3=10;
int m4=11;
void setup()
{
  pinMode(ldr, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  long data = digitalRead(ldr);
//  Serial.println(ldr);
  if (data == LOW)
  {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    Serial.println("forword");
  }
  else
  {
   digitalWrite(m1, LOW);
   digitalWrite(m2, LOW);
   digitalWrite(m3, LOW);
   digitalWrite(m4, LOW); 
   Serial.println("back");
  }
}
