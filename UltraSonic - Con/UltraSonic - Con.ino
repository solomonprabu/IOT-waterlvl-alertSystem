const int buzz = 6;
const int trigPin=9;
const int echoPin=10;
long duration;
float distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(115200);
}

void loop() {
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration=pulseIn(echoPin,HIGH);
distance=(duration*0.034/2/100);      //calculating distance and converting to meters
if(distance <= 0.10 && distance >=0.05){
  Serial.println(distance);
  digitalWrite(buzz,HIGH);
}
else
{
  digitalWrite(buzz,LOW);
}
delay(500);
}
