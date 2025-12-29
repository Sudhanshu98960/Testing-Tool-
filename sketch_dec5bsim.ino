HardwareSerial SIM(2);

void setup() {
  Serial.begin(115200);
  SIM.begin(9600, SERIAL_8N1, 26, 27); // RX=26, TX=27
  
  delay(2000);
  SIM.println("AT");
  delay(1000);
  SIM.println("AT+CMGF=1");
  delay(1000);

  SIM.print("AT+CMGS=\"9336565250\"\r");
  delay(500);
  SIM.print("SIM TEST OK");
  delay(500);
  SIM.write(26);
}

void loop() {}
