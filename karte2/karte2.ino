void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);
pinMode(0, OUTPUT);
pinMode(5, OUTPUT);
pinMode(16, OUTPUT);

analogWrite(2, 128); //links gelb
delay(250);
analogWrite(0, 128); //zweite von links gelb
delay(250);
analogWrite(16, 128); //zweite von rechts gelb
delay(250);
analogWrite(5, 128); //gelb rechts
}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite(4, 128); //oben rot
delay(100);
analogWrite(4, 0);
delay(2000);

}
