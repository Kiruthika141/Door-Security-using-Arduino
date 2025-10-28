#include <LiquidCrystal.h> 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int RedLED = 5;
const int GreenLED = 6;
const int Buzzer = 7;
String id = "";
int wait = 5000;
void setup() 
{
  Serial.begin(9600);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  lcd.begin(20, 4); 
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
void loop() 
{
  if (Serial.available() > 0) 
  {
    char c = Serial.read();
    Serial.print(c);
    if (c == '\n' || c == '\r') 
    {
      id.trim(); 
      if (id.length() == 0) return;
      Serial.println();
      Serial.print("Scanned ID: ");
      Serial.println(id);
      if (id == "11111") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: PRIYA   ");
        Serial.println("Valid Card - PRIYA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "22222") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: RIYA  ");
        Serial.println("Valid Card - RIYA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "33333") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: AMIR    ");
        Serial.println("Valid Card - AMIR");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "44444") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: ARUN  ");
        Serial.println("Valid Card - ARUN");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "55555") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: IMRAN   ");
        Serial.println("Valid Card - IMRAN");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else if (id == "66666") 
      {
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: MEERA  ");
        Serial.println("Valid Card - MEERA");
        digitalWrite(GreenLED, HIGH);
        delay(wait);
        digitalWrite(GreenLED, LOW);
      }
      else 
      {
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
      lcd.setCursor(0, 2);
      lcd.print(" CARD:          ");
      lcd.setCursor(0, 3);
      lcd.print(" NAME:          ");
      id = ""; 
      Serial.println();
      Serial.println("Please scan your RFID Card:");
      Serial.print("> ");
    } 
    else 
    {
      id += c; 
    }
  }
}

