#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(1, 19, NEO_GRB + NEO_KHZ800);

#define debug 1

void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
strip.begin();
strip.show();
strip.setBrightness(255);

if (debug) {
  Serial.begin(115200);
}
}

unsigned long Green_saved_millis = 0;
unsigned long Red_saved_millis = 0;
unsigned long Sun_saved_millis = 0;
byte red_count = 0;

byte r = 0;
byte g = 0;
byte b = 0;
int sun_count = 0;

void loop() {
  if (millis() - 1000 > Green_saved_millis) {
    Green_saved_millis = millis();
    if (digitalRead(10) == HIGH) {
      digitalWrite(10, LOW);
    }
    else {
      digitalWrite(10, HIGH);
    }
  }

  if (millis() - 50 > Red_saved_millis) {
    Red_saved_millis = millis();
    if (red_count == 0 or red_count == 4 or red_count == 8) {
      digitalWrite(9, HIGH);
    }
    else {
      digitalWrite(9, LOW);
    }

    red_count = red_count + 1;
    if (red_count > 60) red_count = 0;
  }

  if (millis() - 100 > Sun_saved_millis) {
    Sun_saved_millis = millis();
    if (debug) Serial.println("Animation");
    sun_count = sun_count + 1;

   
    g = sun_count/2.55;
    if (sun_count > 255){
      r = 255;
      g = 100;
    }
    else {
      r = sun_count;
    }
    setLED(r, g, b);
    
  }
  
}

void setLED(byte r_p, byte g_p, byte b_p) {
  strip.setPixelColor(0, r_p, g_p, b_p);
  strip.show();
  if (debug) Serial.println(String(r) + " " + String(g) + " " + String(b));
}
