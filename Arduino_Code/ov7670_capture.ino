#include <OV7670.h>
#include <Wire.h>

OV7670 camera;

void setup() {
  Serial.begin(115200);
  if (!camera.begin()) {
    Serial.println("Camera init failed!");
    while (1);
  }
  Serial.println("Camera initialized.");
}

void loop() {
  camera.captureFrame();

  // Send image bytes via Serial
  for (int i = 0; i < camera.frameSize(); i++) {
    Serial.write(camera.frameBuffer()[i]);
  }

  delay(5000); // Capture every 5s
}
