// Define the analog pins for the LDRs
const int ldrPins[5] = {A0, A1, A2, A3, A4};

// Define the digital pins for the LEDs
const int ledPins[5] = {13, 12, 11, 10, 9};

// Variable to store the LDR readings
int ldrValues[5];

// Threshold value
const int threshold = 300;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set LED pins as outputs
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read values from each LDR and store them in the array
  for (int i = 0; i < 5; i++) {
    ldrValues[i] = analogRead(ldrPins[i]);
  }

  // Print the LDR readings to the Serial Monitor
  Serial.print("LDR Values: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(ldrValues[i]);
    if (i < 4) {
      Serial.print(", ");
    }
  }
  Serial.println();

  // Check if LDR values are greater than the threshold and control the LEDs accordingly
  for (int i = 0; i < 5; i++) {
    if (ldrValues[i] > threshold) {
      digitalWrite(ledPins[i], HIGH);  // Turn on the corresponding LED
    } else {
      digitalWrite(ledPins[i], LOW);   // Turn off the LED
    }
  }

  // Wait for a short while before the next reading
  //delay(500);
}
