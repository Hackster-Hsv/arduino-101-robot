#include <BlynkSimpleCurieBLE.h>
#include <CurieBLE.h>

char auth[] = "-------Auth Token From BlynkApp-------";

BLEPeripheral  blePeripheral;

void setup() {
  Serial.begin(1200);
  delay(1000);

  blePeripheral.setLocalName("Arduino-Rover");
  blePeripheral.setDeviceName("Arduino-Rover");
  blePeripheral.setAppearance(384);

  Blynk.begin(auth, blePeripheral);

  blePeripheral.begin();

  Serial.println("Waiting for connections...");
}

void loop() {
  Blynk.run();
  blePeripheral.poll();
}
