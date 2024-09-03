##Arduino-based Digital Safe Lock##

This project demonstrates how to create a digital safe lock system using an Arduino, a 4x4 keypad, and a 16x2 LCD display. The system prompts the user to enter a numerical passcode via the keypad, compares it with a predefined passcode, and grants or denies access accordingly. It also includes a lockout mechanism after a certain number of failed attempts.

#Components Used


Arduino (any compatible board),
4x4 Keypad,
16x2 LCD Display (I2C),
Jumper Wires,
Breadboard (optional),


#Circuit Diagram
Keypad Connections:


1.Row 1 (R1): Arduino Pin 2
2.Row 2 (R2): Arduino Pin 3
3.Row 3 (R3): Arduino Pin 4
4.Row 4 (R4): Arduino Pin 5
5.Column 1 (C1): Arduino Pin 6
6.Column 2 (C2): Arduino Pin 7
7.Column 3 (C3): Arduino Pin 8
8.Column 4 (C4): Arduino Pin 9


#LCD Display Connections (I2C):


1.SDA: Arduino A4
2.SCL: Arduino A5
3.VCC: Arduino 5V
4.GND: Arduino GND


#Code Overview


The Arduino code initializes the keypad and LCD display, and then it waits for the user to enter a 4-digit passcode. If the passcode matches the predefined correct passcode, the LCD displays "Access Granted." If the passcode is incorrect, the user is given feedback, and after three failed attempts, the system locks out for a few seconds.

#Code Breakdown


1.Keypad Initialization: The code sets up the keypad using the Keypad library, mapping each key to its respective character.
LCD Initialization: The code initializes the LCD with 16 columns and 2 rows, and turns on the backlight.
2.Passcode Handling:
The user enters the passcode using the keypad.
Pressing # checks if the entered passcode matches the predefined one.
Pressing * clears the current input.
#Lockout Mechanism: After three failed attempts, the system locks the user out for 5 seconds.
