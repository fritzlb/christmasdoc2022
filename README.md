# christmasdoc2022

LED-Karten Dokumentation, ursprünglich für Weihnachten 2022 WIP

AtMega328 basierte Karten:\
16MHz Quartz\
Arduino Uno Bootloader\
3 bis 4 WS2812 LEDs an D9\
standardmäßig ist eine abgeänderte Version von strandtest installiert (nur rainbow(20) und brightness 20)

claas_karte.ino benötigt LEDs an Pins 9 und 10 sowie eine WS28-kompatible LED an Pin 19/A5. Programmierung mit Arduino as ISP (Google)
\
\
karte_fr ist auf Pico-Basis

karte1: Pico-Basis, Karte zeigt Leuchtturm
karte2: ESP8266 Basis, Karte zeigt Funkturm
karte3: bel. Baum bei Nacht, 5x5mm LED
