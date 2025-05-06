/* 
  The following variables are automatically generated and updated when changes are made to the Thing
  float distance;
  float duration;
*/

#include "thingProperties.h"
#define TRIG_PIN   26 // ESP32 pin GIOP26 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN   25 // ESP32 pin GIOP25 connected to Ultrasonic Sensor's ECHO pin
#define BUZZER_PIN 17 // ESP32 pin GIOP17 connected to Piezo Buzzer's pin
#define DISTANCE_THRESHOLD 10 // centimeters

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);	       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set ESP32 pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set ESP32 pin to input mode

  // Configure LEDC timer
  ledcSetup(0, 2000, 8);       // LEDC channel 0, 2000 Hz, 8-bit resolution
  ledcAttachPin(BUZZER_PIN, 0); // Attach buzzer pin to LEDC channel 0
 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  digitalWrite(TRIG_PIN, HIGH);  // generate 10-microsecond pulse to TRIG pin
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH); // measure duration of pulse from ECHO pin
  distance = 0.017 * duration;  // calculate the distance

  if (distance < DISTANCE_THRESHOLD) {
    ledcWriteTone(0, 2000); // Set LEDC channel 0 to generate a tone of 2000 Hz
  } else {
    ledcWriteTone(0,0);    // Turn off the tone
  }
    
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
  
}
