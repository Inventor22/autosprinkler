#include <SoftwareSerial.h>

const uint8_t RX = 0;
const uint8_t TX = 1;

SoftwareSerial ss(RX, TX);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(RX,INPUT_PULLUP);
  pinMode(TX,OUTPUT);
  ss.begin(1200);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  delay(200);
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
}

uint32_t tNow = 0;
uint32_t tPrev = 0;
int timeout = 2000;

// the loop function runs over and over again forever
void loop() {
//  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);              // wait for a second
//  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);              // wait for a second

  while (!ss.available()) {}
  delay(100);

  char buf[20];
  int i = 0;

  while (ss.available() > 0) {
    //ss.print("Received: ");
    buf[i++] = (char) ss.read();
    //ss.print((char)ss.read());
    //delay(20);
  }

  if (buf[0] == 'A'
  && buf[1] == 'B'
  && buf[2] == 'C'
  && buf[3] == 'D'
  ) {
    digitalWrite(2, !digitalRead(2));
    byte sensorReading = analogRead(3) / 4;
  }
  buf[4] = '\0';

  String s(buf);
  ss.print(s);
  

//  tNow = millis();
//  if (tNow - tPrev > timeout) {
//    tPrev = tNow;
//    ss.println("Alive");
//  }

//  ss.println("Hello World");
//  delay(1000);
}
