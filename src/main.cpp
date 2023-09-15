#include <Arduino.h>
// clang-format off
// Needed because Adafruit_Arcade needs Adafruit_ImageReader which needs Adafruit_EPD
#include <Adafruit_EPD.h>
// Go to .pio\libdeps\adafruit_pygamer_m4\Adafruit Arcada Library\Boards\Adafruit_Arcada_PyGamer.h
// (or your respective board) and comment out #define ARCADA_USE_JSON because it breaks compilation
// Go to .pio\libdeps\adafruit_pygamer_m4\Adafruit GFX Library\Adafruit_SPITFT.h
// and comment out #define USE_SPI_DMA because it does not work when compiled with PlatformIO
// clang-format on
#include <Adafruit_Arcada.h>

Adafruit_Arcada arcada;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  if (!arcada.arcadaBegin()) {
    Serial.print("Failed to begin Arcada");
    digitalWrite(LED_BUILTIN, HIGH);
    while (true) {
      ;
    }
  }

  arcada.displayBegin();
  arcada.setBacklight(255);
  arcada.display->fillScreen(ARCADA_BLACK);

  if (!arcada.filesysBegin(ARCADA_FILESYS_SD)) {
    Serial.println("No SD card found!");
    arcada.display->fillScreen(ARCADA_RED);
    arcada.haltBox("Could not find SD card!");
  }
}

void loop() {}
