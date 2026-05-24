#include <Wire.h>
#include <Adafruit_HX711.h>  // Include Adafruit HX711 library

// Pin definitions
#define DOUT  4  // HX711 Data pin
#define CLK   5  // HX711 Clock pin

// Create HX711 object
Adafruit_HX711 scale(DOUT, CLK);

// LED pin definitions
#define RED_LED   2
#define GREEN_LED 6

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Initialize the HX711
  scale.begin(DOUT, CLK);
  scale.set_scale();  // Adjust the scale factor if needed
  scale.tare();  // Reset the scale to zero
  
  // Set LED pins as output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  // Read the weight from the load cell
  long weight = scale.get_units(10);  // Average of 10 readings
  
  // Print the weight for debugging
  Serial.print("Weight: ");
  Serial.println(weight);

  // Check the weight and control LEDs
  if (weight > 400) {
    // If weight is more than 400g, turn on red LED, turn off green LED
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    // If weight is less than or equal to 400g, turn on green LED, turn off red LED
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(500);  // Wait for 500ms before taking another reading
}
