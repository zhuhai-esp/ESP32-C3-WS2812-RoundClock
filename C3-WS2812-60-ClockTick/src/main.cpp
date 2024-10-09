#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#define PIN_LED1 12
#define PIN_LED2 13

// Matrix Data PIN
#define PIN_PIXS 9
#define PIX_NUM 60

Adafruit_NeoPixel pixels(PIX_NUM, PIN_PIXS, NEO_GRB + NEO_KHZ800);
long check1s = 0, check10ms = 0, check300ms = 0;
uint8_t curTick = 0;
uint8_t fastTick = 0;

void inline initBoard() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  pixels.begin();
  pixels.setBrightness(80);
  pixels.clear();
  digitalWrite(PIN_LED1, HIGH);
  delay(500);
  digitalWrite(PIN_LED1, LOW);
}

void inline showFatsTick() {
  pixels.clear();
  auto cur = PIX_NUM - curTick - 1;
  pixels.setPixelColor(cur, 0xff0000);
  cur = (PIX_NUM - curTick - 1 + fastTick) % PIX_NUM;
  if (cur != PIX_NUM - curTick - 1) {
    pixels.setPixelColor(cur, 0x002200);
  }
  cur = (PIX_NUM - curTick - 1 + fastTick + PIX_NUM / 2) % PIX_NUM;
  if (cur != PIX_NUM - curTick - 1) {
    pixels.setPixelColor(cur, 0x000022);
  }
  pixels.show();
}

void setup() { initBoard(); }

void loop() {
  auto ms = millis();
  if (ms - check1s > 1000) {
    check1s = ms;
    curTick += 1;
    if (curTick > 59) {
      curTick = 0;
    }
  }
  if (ms - check300ms > 300) {
    check300ms = ms;
  }
  if (ms - check10ms >= 10) {
    check10ms = ms;
    fastTick += 1;
    if (fastTick > 59) {
      fastTick = 0;
    }
    showFatsTick();
  }
}
