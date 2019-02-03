int S2= 6; 
int S3= 7; 
int outPin = 8; 
int rColorStrength; 
int gColorStrength; 
int bColorStrength; 
unsigned int pulseWidth;
void setup() {
  
  Serial.begin(115200);   
  pinMode(S2, OUTPUT); 
  pinMode(S3, OUTPUT); 
  pinMode(outPin, INPUT); 
  }

void loop() {
  

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  
  pulseWidth =  pulseIn(outPin, LOW); 
  
  rColorStrength = pulseWidth/400. -1; 
  
  rColorStrength = (255- rColorStrength); 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  
  pulseWidth =  pulseIn(outPin, LOW); 
  
  gColorStrength = pulseWidth/400. -1;   
  gColorStrength = (255- gColorStrength);
  
  gColorStrength=gColorStrength + 2;
 
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  
  pulseWidth =  pulseIn(outPin, LOW); 
  
  bColorStrength = pulseWidth/400. -1;
  
  bColorStrength = (255- bColorStrength);
  
 if(rColorStrength>gColorStrength && gColorStrength>bColorStrength) {
   
   rColorStrength = 255;
   gColorStrength = gColorStrength/2;
   bColorStrength = 0;
 }
 
  if(rColorStrength>bColorStrength && bColorStrength>gColorStrength) {
   
   rColorStrength = 255;
   bColorStrength = bColorStrength/2;
   gColorStrength = 0;
 }
 
  if(gColorStrength>rColorStrength && rColorStrength>bColorStrength) {
   
   gColorStrength = 255;
   rColorStrength = rColorStrength/2;
   bColorStrength = 0;
 }
 
   if(gColorStrength>bColorStrength && bColorStrength>rColorStrength) {
   
   gColorStrength = 255;
   bColorStrength = bColorStrength/2;
   rColorStrength = 0;
 }
 
   if(bColorStrength>rColorStrength && rColorStrength>gColorStrength) {
   
   bColorStrength = 255;
   rColorStrength = rColorStrength/2;
   gColorStrength = 0;
 }
 
    if(bColorStrength>gColorStrength && gColorStrength>rColorStrength) {
   
   bColorStrength = 255;
   gColorStrength = gColorStrength/2;
   rColorStrength = 0;
 }
 
  Serial.print(rColorStrength);
  Serial.print(",");
  Serial.print(gColorStrength);
  Serial.print(",");
  Serial.println(bColorStrength);
  delay(2000);
  
}
