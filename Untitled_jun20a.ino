#include "arduino_secrets.h"
#include "thingProperties.h"
#include <NewPing.h>

#define TRIGGER_PIN  D1 
#define ECHO_PIN     11 
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

#define buz D3

bool nilai = false;
float jarak = 0;


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  jarak = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(jarak);
  Serial.println("cm");
 if (jarak <= 20) {
    maling = true;
    nilai = 1;
  }
}

void onBuzzerChange()  {
  // Add your code here to act upon Buzzer change
  if (buzzer == true) {
    nilai != nilai;
    maling != maling;
    digitalWrite(buz,nilai);
  }
}

void onMalingChange()  {
  // Add your code here to act upon Maling change
}