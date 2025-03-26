
// Define pin connections
const int trigPin = 9;   // Trigger pin for ultrasonic sensor
const int echoPin = 10;  // Echo pin for ultrasonic sensor
const int ledPin = 13;   // LED pin

// Define variables for duration and distance
long duration;
float distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set trigPin as output, echoPin as input, and ledPin as output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Send a 10-microsecond pulse to trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance
  duration = pulseIn(echoPin, HIGH); // Measure the duration of the echo signal
  distance = (duration * 0.034) / 2; // Convert to distance in centimeters

  // Display the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED Blinking Logic Based on Distance
  if (distance > 0 && distance <= 50) {  // Object detected within 50 cm
    int blinkSpeed = map(distance, 0, 50, 100, 500); // Map distance to blink speed
    digitalWrite(ledPin, HIGH);
    delay(blinkSpeed);
    digitalWrite(ledPin, LOW);
    delay(blinkSpeed);
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED if no object detected
  }

  // Wait before next measurement
  delay(100);
}
