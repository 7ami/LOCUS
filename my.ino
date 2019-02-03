#include <Servo.h>
Servo servo1;
int buzzer=10;
int trigPin = 12;
int echoPin = 13;
int servoPin=3;
void object(int,int);
int color();
long unsigned int duration;
float distance;
float dist();
void disp(float,int);
float dis;
int i;
void buzz();
const int s[4]={4,5,6,7};
const int sensOut=8;
int frequency;
int red();
int blue();int green();
void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  servo1.attach(servoPin);
  //digitalWrite(servoPin,HIGH);
  servo1.write(30);
  pinMode(buzzer,OUTPUT);
  pinMode(s[0],OUTPUT);
  pinMode(s[1],OUTPUT);
  pinMode(s[2],OUTPUT);
  pinMode(s[3],OUTPUT);
  pinMode(sensOut,INPUT);
  pinMode(s[0],HIGH);
  pinMode(s[1],LOW);
}
void loop() {
  for (i=5;i<175;i+=3)
  {
    servo1.write(i);
    dis=dist();
    if (dis<20) {disp(dis,i);}
    
    delay(200);
  }
  for(i=175;i>5;i-=3)
  {
    servo1.write(i);
    dis=dist();
    if (dis<20) {disp(dis,i);}
    
    delay(200);
  }
}
float dist()
  {
  digitalWrite(trigPin,LOW);
  delay(10);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*330)/20000;
  return distance;
  }
  void disp(float d,int p)
  {
    
    Serial.print(d);
    Serial.print(",");
    Serial.print(red());
    Serial.print(",");
    Serial.print(green());
    Serial.print(",");
    Serial.println(blue());
    buzz();
  }
  void buzz()
  {
   tone(buzzer,1000);
   delay(100);
   noTone(buzzer);
  }
  int red()
  {
    digitalWrite(s[2],LOW);
    digitalWrite(s[3],LOW);
    frequency = pulseIn(sensOut, LOW);
    return frequency;
  }
  int green()
  {
    digitalWrite(s[2],HIGH);
    digitalWrite(s[3],HIGH);
    frequency = pulseIn(sensOut, LOW);
    return frequency;
  }
  int blue()
  {
    digitalWrite(s[2],LOW);
    digitalWrite(s[3],HIGH);
    frequency = pulseIn(sensOut, LOW);
    return frequency;
  }
