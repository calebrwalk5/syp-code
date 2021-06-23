void setup() {
	pinMode(12, OUTPUT);
}

void loop() {
	for(;;)  {
		for (int i = 0; i < 1000; i++) {
			digitalWrite(12, HIGH);
			delay(.5);
			digitalWrite(12, LOW);
			delay(.5);
		}
 		for (int x = 0; x < 1500; x++) {
			digitalWrite(12, HIGH);
			delay(1);
			digitalWrite(12, LOW);
			delay(1);
		}
	}
}
