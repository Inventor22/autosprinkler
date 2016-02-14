
#include <SoftwareSerial.h>

const int RX_BT = 11;
const int TX_BT = 10;

const int STATUS_LED = 13;

SoftwareSerial softSerial(RX_BT, TX_BT);


//Setup Arduino function
void setup() {
	Serial.begin(9600);
	Serial.println("USB Connected");

	softSerial.begin(1200);

	pinMode(STATUS_LED, OUTPUT);
	digitalWrite(STATUS_LED, LOW);

	//setBaud("1");
	//setName("WEC_Organizer");
	setName("Usensor2");
	//setPin(1234);
}

void setBaud(char* baud) {
	String command = "AT+BAUD";
	command += baud;

	Serial.println(command);
	softSerial.print(command);

	delay(2000);
	if (softSerial.available()) {
		while (softSerial.available()) {
			Serial.print((char)softSerial.read());
		}
		Serial.println();
	}
}

void setName(char* name) {
	String command = "AT+NAME";
	command += name;
	Serial.println(command);
	softSerial.print(command);

	delay(2000);
	if (softSerial.available()) {
		while (softSerial.available()) {
			Serial.print((char)softSerial.read());
		}
		Serial.println();
	}
}

void setPin(int pin) {
	if (pin > 9999 || pin < 0) return;
	String command = "AT+PIN";
	command += pin;
	Serial.println(command);
	softSerial.print(command);

	delay(2000);
	if (softSerial.available()) {
		while (softSerial.available()) {
			Serial.print((char)softSerial.read());
		}
		Serial.println();
	}
}
//Loop Arduino function

char command[50];

void loop() {

}
