int left=6;
int right=7;
int Left=0;
int Right=0;

void LEFT();
void RIGHT();
void STOP();

void setup() 
{
  pinMode(2,OUTPUT); //a1
  pinMode(3,OUTPUT); //a2
  pinMode(4,OUTPUT); //b2
  pinMode(5,OUTPUT); //b1
  pinMode(0, OUTPUT); //en
  pinMode(1, OUTPUT); //en
  pinMode(left,INPUT); //6 - IR
  pinMode(right,INPUT); //7 -IR

  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
}

void loop() 
{ 
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);

  analogWrite(3,0);
  analogWrite(2,153);
  analogWrite(5,0);
  analogWrite(4,153);

  while(1)
  {
    Left=digitalRead(left);
    Right=digitalRead(right);
    if(Left==1 && Right==0) //if left sensor detects black
      LEFT();
    else if(Right==1 && Left==0) //if right sensor detects black
      RIGHT();
  }
}

void LEFT()
{
  analogWrite(5,-5);
  analogWrite(4,0);

   while(Left==0)
   {
    Left=digitalRead(left);
    Right=digitalRead(right);
    if(Right==0)
    {
      int lprev=Left;
      int rprev=Right;
      STOP();
      while(((lprev==Left)&&(rprev==Right))==1)
      {
         Left=digitalRead(left);
         Right=digitalRead(right);
      }
    }
    analogWrite(3,0);
    analogWrite(2,153); 
   }
   analogWrite(5,0);
   analogWrite(4,153);
}

void RIGHT()
{
   analogWrite(3,-5);
   analogWrite(2,0);

   while(Right==0)
   {
    Left=digitalRead(left);
    Right=digitalRead(right);
    if(Left==0)
    {
      int lprev=Left;
      int rprev=Right;
     STOP();
      while(((lprev==Left)&&(rprev==Right))==1)
      {
         Left=digitalRead(left);
         Right=digitalRead(right);
      }
    }
    analogWrite(5,0);
    analogWrite(4,153);
    }
   analogWrite(3,0);
   analogWrite(2,153);
}

void STOP()
{
  analogWrite(2,0);
  analogWrite(3,0);
  analogWrite(4,0);
  analogWrite(5,0);
}
/*
 *   //direction: right
  if(right==HIGH)
  {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  }


  //direction: left
  if(left==HIGH)
  {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  } */
