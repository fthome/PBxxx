

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


void setup(){
 pinMode(A1,INPUT);  // entrée analogique capteur 1
 pinMode(A2,INPUT);  // entrée analogique capteur 2

 Serial.begin(9600);
 lcd.begin(20, 4);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("TEST entree A1 et A2");
lcd.setCursor(0, 1);
lcd.print(" sur Moniteur serie");
lcd.setCursor(0, 2);
lcd.print("  et sur ecran LCD");
}

void loop(){
    int Capteur1=analogRead(A1);
    int Capteur2=analogRead(A2);
 
   Serial.print("     Capteur1 : ");Serial.print(Capteur1); Serial.print("     Capteur2 : ");Serial.println(Capteur2);
   lcd.setCursor(0, 3);
   lcd.print(" A1 = "); lcd.print(Capteur1);
   lcd.print("  A2 = "); lcd.print(Capteur2);
   
delay(1000);
}
