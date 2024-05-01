#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the pins for the proximity sensors
const int sensor1Pin = 2;
const int sensor2Pin = 3;
const int sensor3Pin = 4;

// Define the pins for the relays
const int relay1Pin = 5;
const int relay2Pin = 6;
const int relay3Pin = 7;

void setup() {
  // Initialize the LCD display
  lcd.init();
  lcd.backlight();

  // Set the pins for the proximity sensors as input
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);

  // Set the pins for the relays as output
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);

  // Set the initial state of the relays to off
  digitalWrite(relay1Pin, HIGH);
  digitalWrite(relay2Pin, HIGH);
  digitalWrite(relay3Pin, HIGH);

 
}

void loop() {
  // Read the state of the proximity sensors
  int sensor1State = digitalRead(sensor1Pin);
  int sensor2State = digitalRead(sensor2Pin);
  int sensor3State = digitalRead(sensor3Pin);


  
  if (sensor1State == HIGH&&sensor2State==LOW&&sensor3State==LOW) {
    // Turn on relay 1
    digitalWrite(relay1Pin, LOW);

    // Print a message to the LCD display
  lcd.setCursor(0, 0);
    lcd.print("VALVE_1-ON MTR_1");
    lcd.setCursor(0, 1);
    lcd.print("TANK_1-LOADING");
  }
  else if(sensor1State == LOW&&sensor2State==HIGH&&sensor3State==HIGH)
  {
     digitalWrite(relay1Pin, LOW);

    // Print a message to the LCD display
  lcd.setCursor(0, 0);
    lcd.print("       INVALID     ");
    lcd.setCursor(0, 1);
    lcd.print("     CHOICE    ");
  } else {
    // Turn off relay 1
    digitalWrite(relay1Pin, HIGH);
  }

  if (sensor1State == LOW&&sensor2State==HIGH&&sensor3State==LOW) {

    // Turn on relay 2
    digitalWrite(relay2Pin, LOW);

    // Print a message to the LCD display
    lcd.setCursor(0, 0);
    lcd.print("VALVE_2-ON MTR_2");
    lcd.setCursor(0, 1);
    lcd.print("TANK_2-LOADING");
  } 
  else if(sensor1State == HIGH&&sensor2State==LOW&&sensor3State==HIGH)
  {
     digitalWrite(relay1Pin, LOW);

    // Print a message to the LCD display
  lcd.setCursor(0, 0);
    lcd.print("       INVALID     ");
    lcd.setCursor(0, 1);
    lcd.print("     CHOICE    ");
  } else {
    // Turn off relay 2
    digitalWrite(relay2Pin, HIGH);
  }

  if (sensor1State == LOW&&sensor2State==LOW&&sensor3State==HIGH) {
    // Turn on relay 3
    digitalWrite(relay3Pin, LOW);

    // Print a message to the LCD display
    lcd.setCursor(0, 0);
    lcd.print("VALVE_3-ON MTR_3");
    lcd.setCursor(0, 1);
    lcd.print("TANK_3-LOADING"); 
  
  }
  else if(sensor1State == HIGH&&sensor2State==HIGH&&sensor3State==LOW)
  {
     digitalWrite(relay1Pin, LOW);

    // Print a message to the LCD display
  lcd.setCursor(0, 0);
    lcd.print("       INVALID     ");
    lcd.setCursor(0, 1);
    lcd.print("     CHOICE    ");
  } 
   else {
    // Turn off relay 3
    digitalWrite(relay3Pin, HIGH);
    
  }
   if(sensor1State ==sensor2State==sensor3State== LOW)
  {
  
  lcd.setCursor(0, 0);
  lcd.print("VALVE METER AND ");
  lcd.setCursor(0, 1);
  lcd.print("  TANK STATUS  ");
  } 
}