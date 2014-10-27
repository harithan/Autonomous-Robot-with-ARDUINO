int sensorF = A0;
int sensorR = A1;
int sensorL = A2;
int senf = 0;
int senr = 0;
int senl = 0;
int rc = 2;
int lc = 5;
int r1 = 3;
int r2 = 4;
int l1 = 6;
int l2 = 7;
int led = 13;
int flag = 1;

void setup()
{
  pinMode(rc, OUTPUT);
  pinMode(lc, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(led, OUTPUT);
 
  
}

void loop()
{
   while(1){
  digitalWrite(rc, HIGH);
  digitalWrite(lc, HIGH);
  
  digitalWrite(13, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  
  
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
 
  delay(250);
 digitalWrite(13, HIGH);
 digitalWrite(rc, LOW);
  digitalWrite(lc, LOW);
  delay(250);
   senf = analogRead(sensorF);
  senr = analogRead(sensorR);
  senl = analogRead(sensorL);
  
  if(senf > 200)
  {
if(senr > 200 && senl < 200) // left turn
{   
    digitalWrite(rc, HIGH);
    digitalWrite(lc, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    delay(1000); 
    flag = 1;

}
else if(senl > 200 && senr < 200) // right turn
{    
    digitalWrite(rc, HIGH);
    digitalWrite(lc, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    delay(1000);
    flag = 2;
}
else if(senl < 200 && senr < 200)
{
if(flag == 1)
{
    digitalWrite(rc, HIGH);
    digitalWrite(lc, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
    delay(1000);
    flag = 2;
}
else if(flag == 2)
{
digitalWrite(rc, HIGH);
    digitalWrite(lc, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    delay(1000); 
    flag = 1;
}






}
else
{
digitalWrite(rc, LOW);
 digitalWrite(lc, LOW);

}
}

  
  
  }
 
  
  
  
}
