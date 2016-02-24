#include <SoftwareSerial.h>
#include <math.h>

//Setup Sensor Pins
const uint8_t SenSig = A3;
const uint8_t SenVCC = 4;

//Sensor Bluetooth Pins
const uint8_t RX = 0;
const uint8_t TX = 1;
const uint8_t BVCC = 2;

SoftwareSerial ss(RX,TX);

void setup() {
    // put your setup code here, to run once:
  
    //Setup VCC on sensor and set it to off
  pinMode(SenVCC,OUTPUT);
  digitalWrite(SenVCC,HIGH);
  
    //Setup Bluetooth receiving and transmitting pins
  pinMode(RX,INPUT_PULLUP);
  pinMode(TX,OUTPUT);
  ss.begin(1200);

  //Setup VCC on bluetooth. We will turn on later
  pinMode(BVCC,OUTPUT);
  digitalWrite (BVCC,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

//I assume it's base 0 like usual. Let me know if this is wrong
int senVal[9];
double WaterContent[9];
double sum=0;
double average=0;

for (int i=0 ; i<10;i++){
  senVal[i]=analogRead(SenSig);
  WaterContent[i]=0.0072*exp(0.0053*senVal[i]);
  sum=WaterContent[i]+sum;
  delay(1000);
  }
//Now I want to send this average value
average=sum/10;


ss.print(average);

}
