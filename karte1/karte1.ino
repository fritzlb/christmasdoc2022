void setup() {
  // put your setup code here, to run once:
    pinMode(9, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(6, OUTPUT);

    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);
  delay(4000);
  digitalWrite(8, LOW);
  delay(4000);
}
//PIN 9: LED Grün rechts
//PIN 6: Grün links
//PIN 7: Gelb Mitte
//PIN8: rot