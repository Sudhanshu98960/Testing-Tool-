#include <TinyGPS++.h>

TinyGPSPlus gps;
HardwareSerial GPS(1);

void setup() {
  Serial.begin(115200);
  GPS.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17
}

void loop() {
  while (GPS.available()) {
    gps.encode(GPS.read());
    if (gps.location.isValid()) {
      Serial.print("Lat: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Lng: ");
      Serial.println(gps.location.lng(), 6);
    }
  }
}
