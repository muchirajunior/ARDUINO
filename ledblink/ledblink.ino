
int led=16;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,LOW);
  delay(1000);
  digitalWrite(led,HIGH);

  delay(1000);

}
