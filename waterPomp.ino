#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

void clearValue() {
   
 lcd.setCursor(12,1);
 lcd.print(" ");
 lcd.setCursor(13,1);
 lcd.print(" ");
 lcd.setCursor(14,1);
 lcd.print(" ");
 
  }
  void setSign() {
    lcd.setCursor(15,1);
    lcd.print("%");
    }

    
void setup() {
  
  pinMode(13, OUTPUT);   
  lcd.begin(16, 2);
  
  // initialize serial communication at 9600 bits per second: 
  Serial.begin(9600);
} 

void loop() {  
  int sensorValue = analogRead(A1);
  int outputValue = map(sensorValue,1023,201,0,100);
  
  Serial.println(sensorValue);
  delay(1000);

  clearValue();
  setSign();

  if(outputValue<50) {
        
        lcd.setCursor(0,0); 
        lcd.print("POMPA DZIALA"); 
        
        lcd.setCursor(0,1); 
        lcd.print("WILGOTNOSC:" ); 
        lcd.setCursor(12,1);
        lcd.print(outputValue);
        
        digitalWrite(13, LOW);       // sets the digital pin 13 on
        delay(1000);  
        digitalWrite(13, HIGH);        // sets the digital pin 13 off
        delay(10000); 
  } else {
                  
        lcd.setCursor(0,0); 
        lcd.print("POMPA CZEKA "); 
        lcd.setCursor(0,1); 
        lcd.print("WILGOTNOSC:" ); 
        lcd.setCursor(12,1);
        lcd.print(outputValue);
        
        digitalWrite(13, HIGH);        // sets the digital pin 13 off
        delay(1000);                  // waits for a second
       
     }
     
  if (outputValue==50) {
      delay(36000);
  }
}
