#include <FastLED.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WS2812B LED setup
#define LED_PIN 5
#define NUM_LEDS 16  // Adjust to match your LED strip
#define LED_BRIGHTNESS 50
CRGB leds[NUM_LEDS];

// LCD setup (adjust address and size as needed)
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Initialize LCD
  lcd.init();  // Pass required arguments
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Merry Christmas");
  lcd.setCursor(0, 1);
  lcd.print("David!");

  // Initialize LEDs
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(LED_BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // Alternate pattern: start with LED 0 white
  alternateColors(CRGB::White, CRGB::Red);
  delay(500);

  // Alternate pattern: start with LED 0 red
  alternateColors(CRGB::Red, CRGB::White);
  delay(500);
}

// Helper function to alternate colors
void alternateColors(CRGB color1, CRGB color2) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i % 2 == 0) ? color1 : color2;
  }
  FastLED.show();
}
