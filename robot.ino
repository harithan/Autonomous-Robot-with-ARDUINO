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
int flag = 0;

void setup()
{
  pinMode(rc, OUTPUT);
  pinMode(lc, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(led, OUTPUT);
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
  }
  
}

void loop()
{
  senf = analogRead(sensorF);
  senr = analogRead(sensorR);
  senl = analogRead(sensorL);
  
  if(senf > 300)
  {
  if(senr > 300)
  {
    flag = 1;
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    delay(1000);  
  }
  else if(flag ==1 | senl > 300)
  {
    flag = 2;
  digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
  delay(1000);
  }
  else{    
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    delay(1000); 
  
  }


}
  
  
  
}
