#include "LedControl.h"

// Initialization of the LED matrix
LedControl lc = LedControl(12, 11, 10, 1);
unsigned long delaytime = 1000; // Set delay time between updates

// Bitmap for a simple smiley face
byte face[8] = {
  B00111100, // Eyes on this row
  B01000010, 
  B01000010, 
  B01000010, 
  B00111100, 
  B00000000, 
  B01100110, // Mouth on this row
  B00000000
};

// Bitmap for the eyes blinking
byte blink[8] = {
  B00000000, // Eyes off
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000,
  B01100110, // Mouth stays the same
  B00000000
};

void setup() {
  lc.shutdown(0, false); // Wake up the display
  lc.setIntensity(0, 8); // Set brightness level
  lc.clearDisplay(0);    // Clear display register
}

// Function to display the smiley face
void displayFace(byte bitmap[]) {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, bitmap[i]);
  }
}

void loop() {
  displayFace(face); // Display the normal face
  delay(delaytime);  // Wait for a second
  displayFace(blink); // Blink eyes
  delay(delaytime);  // Wait for a second
  displayFace(face); // Display the normal face again
  delay(delaytime * 3);  // Keep the normal face for 3 seconds
}
