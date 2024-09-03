#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD (I2C address 0x27 for a 16x2 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 columns and 2 rows

// Define keypad layout and pins
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const String correctPasscode = "1234"; // Predefined passcode
String inputPasscode = ""; // Stores the entered passcode
int attemptCount = 0; // Counter for failed attempts
const int maxAttempts = 3; // Maximum allowed attempts

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.backlight(); // Turn on the LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      // Check if the entered passcode is correct
      if (inputPasscode == correctPasscode) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Granted");
        attemptCount = 0; // Reset attempt count on success
        delay(2000); // Show the message for 2 seconds
        lcd.clear();
        lcd.print("Enter Password:");
      } else {
        attemptCount++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        delay(2000); // Show the message for 2 seconds
        lcd.clear();
        lcd.print("Enter Password:");
        
        // Lockout mechanism after 3 failed attempts
        if (attemptCount >= maxAttempts) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Locked Out");
          delay(5000); // Lockout for 5 seconds
          attemptCount = 0; // Reset attempt count after lockout
          lcd.clear();
          lcd.print("Enter Password:");
        }
      }
      inputPasscode = ""; // Clear the input passcode
    } else if (key == '*') {
      inputPasscode = ""; // Clear the input passcode
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
    } else {
      // Append the key to the input passcode
      inputPasscode += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPasscode);
    }
  }
}
