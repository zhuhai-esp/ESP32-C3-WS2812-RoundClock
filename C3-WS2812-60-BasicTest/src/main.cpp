#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#define PIN_LED1 12
#define PIN_LED2 13

// Matrix Data PIN
#define PIN_PIXS 9
#define PIX_NUM 60

Adafruit_NeoPixel pixels(PIX_NUM, PIN_PIXS, NEO_GRB + NEO_KHZ800);

void inline initBoard() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  pixels.begin();
  pixels.setBrightness(40);
  pixels.clear();
}

void inline pixelsCheck() {
  pixels.fill(0xFF0000, 0, 60);
  pixels.show();
  sleep(1);
  pixels.fill(0xFF00, 0, 60);
  pixels.show();
  sleep(1);
  pixels.fill(0xFF, 0, 60);
  pixels.show();
  sleep(1);
  pixels.fill(0xFFFFFF, 0, 60);
  pixels.show();
  sleep(1);
  pixels.clear();
}

void setup() {
  initBoard();
  pixelsCheck();
}

void loop() {
  for (uint16_t i = 0; i < 65536; i += 60) {
    pixels.rainbow(i, 1, 255, 255);
    pixels.show();
  }
}
