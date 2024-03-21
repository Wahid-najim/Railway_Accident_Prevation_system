#include <LiquidCrystal.h>
#include <Wire.h>

// Defining the pins for ultrasonic sensor
const int trigPin = 11;
const int echoPin = 12;

// LCD display connection
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Defining the variables
long duration;
int distance;

// void setup
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print("Accident Prevention");
  lcd.setCursor(0, 1);
  lcd.print("System");
}

void loop() {
  // Clear LCD
  lcd.clear();
  
  // Send pulse to trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the pulse duration from echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance
  distance = duration * 0.034 / 2;
  
  // Print distance on LCD and Serial Monitor
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if the distance is less than a threshold (threshold can be adjusted)
  if (distance < 20) {
    lcd.setCursor(0, 1);
    lcd.print("Railway Alert!");
    // You can add further actions here such as triggering an alarm or stopping the train.
  }
  
  // Delay for stability
  delay(1000);
}
