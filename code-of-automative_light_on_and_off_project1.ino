// C++ code
#include <Servo.h> // include the library that enables me using my servo motor
int sensor = 6; // connect pin # 6 to the OUT or SIGNAl pin of the sound sensor
int servoPin = 10; // connect pin # 10 to the yellow wire of the servo motor
int LED = 13; // connect pin # 13 to the positive or longer leg of a LED
Servo myservo; // defy "myservo" to be the word I will be using throughout my coding process
const int servoMoveDuration = 1500; // the time it takes for the servo to fully turn to the desired angle (approximately)
bool servoBusy = false; // make the current cindition of the servo to be not "BUSY" -- "bull" can be used when the veriable can be only "TRUE" or "FALSE"
unsigned long servoStartTime = 0; // this variable records the time (in milliseconds) when the servo started its movement
void setup() {
  // put your setup code here, to run once:
pinMode(sensor, INPUT); // sound sensor is giving me information so I will set it to be INPUT
pinMode(LED, OUTPUT); // LED is getting something (power) from me so it will be OUTPUT
myservo.attach(servoPin); // identifying on which pin my servo is getting the commands
myservo.write(90); // initial starting angle is 90 degrees
Serial.begin(9600); // for debugging purposes I set serial monitor to 9600, which dictates how fast my communication is.
digitalWrite(LED, LOW); // initially start the program with the LED being off 

}

void loop() {
  // put your main code here, to run repeatedly:
int reading = digitalRead(sensor); // read the digital signals sound sensor is sending and record them as "reading"
int status = digitalRead(LED); // check the status of the LED and record the status of the LED as "status"



if (reading == 1 && digitalRead(LED) == LOW && !servoBusy) { // if there is a noise and the LED's status is OFF and the servo motor is not working
myservo.write(120); // turn the servo motor to 120 degree
digitalWrite(LED, HIGH); // turn the LED on
servoStartTime = millis(); // record the time as soon as the servo motor starts moving
servoBusy = true; // make the condition of the servo motor to be working

}
//delay(1000);
if (reading == 1 && digitalRead(LED) == HIGH &&  (millis() - servoStartTime) > servoMoveDuration ) { // if there is a noise and the LED's status is ON and the time after the servo motor started moving is greater than the time it takes for the servo motor to move to the desired angle
myservo.write(60); // turn the servo motor to 60 degree
digitalWrite(LED, LOW); // turn the LED off
servoBusy = false; // make the condition of the servo to be not working
delay(1500); // wait for 1.5 seconds before going over to the next command
} 

}