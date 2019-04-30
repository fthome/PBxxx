

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);


void setup(){
    pinMode(A1,INPUT);  // entrée analogique capteur 1
    pinMode(A2,INPUT);  // entrée analogique capteur 2

    Serial.begin(9600);
    EcranLCD.begin(20, 4);

    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("TEST entree A1 et A2");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" sur Moniteur serie");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("  et sur ecran LCD");
}

void loop(){
    int Capteur1 = analogRead(A1);
    int Capteur2 = analogRead(A2);
 
    Serial.print("     Capteur1 : ");
    Serial.print(Capteur1); 
    Serial.print("     Capteur2 : ");
    Serial.println(Capteur2);
    
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" A1 = "); 
    EcranLCD.print(Capteur1);
    EcranLCD.print("  A2 = "); 
    EcranLCD.print(Capteur2);
   
    delay(1000);
}
