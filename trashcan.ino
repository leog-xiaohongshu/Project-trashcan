#include <Servo.h> // Include the Servo library

// Define pins for the ultrasonic sensor
const int trigPin = 10; // Pin connected to the Trigger
const int echoPin = 11; // Pin connected to the Echo
const int servoPin = 9; // Pin connected to the Servo

// Variables to store the duration and distance
long duration;
int distance;

// Create a Servo object
Servo myServo;

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor with Servo Control");

  // Set the trigPin as an OUTPUT and echoPin as an INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach the servo to the specified pin
  myServo.attach(servoPin);
  
  // Set the servo to an initial position
  myServo.write(90); 
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send the pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, and measure the duration of the pulse in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the servo based on distance
  if (distance < 10) {
    myServo.write(90); // Move servo to 90 degrees
    Serial.println("Servo set to 90 degrees");
  } else {
    delay(500);
    myServo.write(180); // Move servo to 180 degrees
    Serial.println("Servo set to 180 degrees");
  }

  // Wait 500 milliseconds before the next reading
  delay(500);
}
