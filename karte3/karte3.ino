void setup() {
  // put your setup code here, to run once:
pinMode(A1, OUTPUT);
pinMode(A2, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A5, OUTPUT);

digitalWrite(A1, HIGH);
delay(500);
digitalWrite(A5, HIGH);
delay(500);
digitalWrite(A2, HIGH);
digitalWrite(A4, HIGH);
delay(500);
digitalWrite(A3, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(5000);
digitalWrite(A1, LOW);
delay(200);
digitalWrite(A1, HIGH);
digitalWrite(A5, LOW);
delay(200);
digitalWrite(A5, HIGH);
digitalWrite(A2, LOW);
digitalWrite(A4, LOW);
delay(200);
digitalWrite(A2, HIGH);
digitalWrite(A4, HIGH);
digitalWrite(A3, LOW);
delay(200);
digitalWrite(A3, HIGH);
}
