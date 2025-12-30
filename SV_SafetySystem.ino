#define ultraPin 9       // Ultrasonic sensor SIG pin to digital pin 9
#define greenLED 2       // Green LED to digital pin 2
#define yellowLED 3      // Yellow LED to digital pin 3
#define redLED 4         // Red LED to digital pin 4

long duration;          // Time for ultrasonic pulse to return (in microseconds)
int distance;           // Calculated distance in centimeters

void setup() {
  // Set LED pins as OUTPUT
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  /* Trigger ultrasonic pulse 
        LOW → HIGH → LOW = trigger pulse /Complete pulse
        Duration matters → the sensor expects at least 10 microseconds HIGH
        After this, the sensor emits a sound wave (ultrasound) into the environment */
  pinMode(ultraPin, OUTPUT);      // Set sensor pin as output to send pulse

  //Ensure the pin starts at LOW before sending HIGH  for a short moment- like resetting the sensor
  digitalWrite(ultraPin, LOW);    // Ensure LOW for a short moment
  delayMicroseconds(2);           // Wait 2 microseconds
  digitalWrite(ultraPin, HIGH);   // Send HIGH pulse for 10 microseconds. This is the actual trigger pulse that tells the sensor to send out an ultrasonic pulse!
  delayMicroseconds(10);  
  digitalWrite(ultraPin, LOW);    // LOW → end pulse

  // Listen for echo
  pinMode(ultraPin, INPUT);            // Set pin to input to read the echo
  duration = pulseIn(ultraPin, HIGH);  // Measure how long the pin stays HIGH

  // Convert time to distance
  distance = duration * 0.034 / 2;  // Speed of sound = 0.034 cm/µs, divide by 2 for round trip

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Step 4: Decision logic for LEDs
  if (distance > 50) {
    // Safe distance → turn on green LED
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  } 
  else if (distance > 20) {
    // Medium distance → warning → turn on yellow LED
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  } 
  else {
    // Close distance → danger → turn on red LED
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  // Small delay to stabilize readings
  delay(200);
}
