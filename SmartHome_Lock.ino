// include the library code:
#include <LiquidCrystal.h> // library for LCD

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int RedLED = 5;
const int GreenLED = 6;
const int Buzzer = 7;

String id = "";
int wait = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("_____SMART HOME____ ");
  lcd.setCursor(0, 1);
  lcd.print(" RFID BASED LOCK SYS");
  lcd.setCursor(0, 2);
  lcd.print(" CARD:   ");
  lcd.setCursor(0, 3);
  lcd.print(" NAME:   ");

  Serial.println("Please scan your RFID Card:");
  Serial.print("> ");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    // Echo the character back to the Virtual Terminal
    Serial.print(c);

    // If Enter key is pressed, process the ID
    if (c == '\n' || c == '\r') {
      id.trim(); // remove unwanted spaces/newlines

      if (id.length() == 0) return;

      Serial.println();
      Serial.print("Scanned ID: ");
      Serial.println(id);

      // Check for valid IDs
      if (id == "12345") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: KIRUTHIKA   ");
        Serial.println("Valid Card - KIRUTHIKA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "67890") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: RAGA  ");
        Serial.println("Valid Card - RAGA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "QWERT") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: PRIYA    ");
        Serial.println("Valid Card - PRIYA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "YUIOP") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: BHARATHI  ");
        Serial.println("Valid Card - BHARATHI");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "ASDFG") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: VIJAY   ");
        Serial.println("Valid Card - VIJAY");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "HJKKL") {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: KUMAR  ");
        Serial.println("Valid Card - KUMAR");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: INVALID  ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: UNKNOWN  ");
        Serial.println("Invalid Card!");
        digitalWrite(RedLED, HIGH);
        digitalWrite(Buzzer, HIGH);
        delay(500);
        digitalWrite(Buzzer, LOW);
        delay(4000);
        digitalWrite(RedLED, LOW);
      }

      // Reset the display and serial prompt
      lcd.setCursor(0, 2);
      lcd.print(" CARD:          ");
      lcd.setCursor(0, 3);
      lcd.print(" NAME:          ");
      id = ""; // clear the string
      Serial.println();
      Serial.println("Please scan your RFID Card:");
      Serial.print("> ");
    } else {
      id += c; // build the RFID ID
    }
  }
}
