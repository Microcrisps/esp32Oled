#include <Arduino.h>
// TTGO Test. This is a test script for a "TTGO" ESP32 Dev Board
// including an LCD module and a 18650 battery pack.
//
// There is an integrated LED on digital pin 16 - woohoo!!
//
// The built in OLED is a 128*64 mono pixel display
// i2c address = 0x3c
// SDA = 5
// SCL = 4
//
// I use the ThingPulse ESP8266 OLED library, found here:
// https://github.com/ThingPulse/esp8266-oled-ssd1306
//
// Please see the library for more detail on OLED commands
//
// Aidan Taylor
// March 2018
// Electric Noodle Box

#include "wire.h"
#include "SSD1306.h"

uint8_t ledPin = 16; // Onboard LED reference

SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

void setup() {
    pinMode(ledPin, OUTPUT);

    display.init(); // initialise the OLED
    // display.flipScreenVertically(); // does what is says
    display.setFont(ArialMT_Plain_24); // does what is says
    // Set the origin of text to top left
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
}

void loop() {
  // blink the LED a few times - LED is lit when LOW for me
  for(uint8_t n = 0; n < 10; n++) {
    digitalWrite(ledPin, LOW);
    delay(30);
    digitalWrite(ledPin, HIGH);
    delay(30);
  }

  // Horizontal scroll OLED text
  for(int16_t n = -127; n < 210; n++) {
    display.drawString(n, 31, "Peanut butter!!");
    display.display();
    delay(10);
    display.clear();
  }

  // Upwards scroll OLED text
  for(int8_t n = 112; n > -72; n--) {
    display.drawString(63, n, "Well");
    display.drawString(63, n+24, "was");
    display.drawString(63, n+48, "easy");
    display.display();
    delay(10);
    display.clear();
  }
}
