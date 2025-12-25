#include <Servo.h>

Servo servo;

int irPin = 2;              // IR sensor pin
int metal_Pin = 3;          // Metal sensor pin (NPN type)
int moisture_Pin = A0;      // Moisture sensor pin
int servo_Pin = 9;          // Servo motor pin

int moistureThreshold = 600; // Threshold for wet/organic waste

void setup() {
  servo.attach(servo_Pin);

  pinMode(irPin, INPUT);
  pinMode(metal_Pin, INPUT_PULLUP); // NPN metal sensor
  pinMode(moisture_Pin, INPUT);

  Serial.begin(9600);

  servo.write(90); // Default neutral position
}

void loop() {
  int irValue = digitalRead(irPin);
  int metalValue = digitalRead(metal_Pin);
  int moisture_Value = analogRead(moisture_Pin);

  // Check if waste is detected by IR sensor
  if (irValue == LOW) {   // Object detected
    Serial.print("Moisture Sensor Value: ");
    Serial.println(moisture_Value);

    // Check for metal waste
    if (metalValue == LOW) {
      Serial.println(">> WASTE TYPE: METAL");
      servo.write(0);   // Metal bin position
    }
    // Check for wet/organic waste
    else if (moisture_Value < moistureThreshold) {
      Serial.println(">> WASTE TYPE: ORGANIC / WET");
      servo.write(180); // Wet bin position
    }
    // Otherwise dry waste
    else {
      Serial.println(">> WASTE TYPE: DRY / NON-METAL");
      servo.write(90);  // Dry bin position
    }

    delay(1500);        // Allow servo to move
    servo.write(90);    // Return to default
    delay(1000);
  }
}
