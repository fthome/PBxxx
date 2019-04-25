// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float L = 0.07 ;  // L = Longueur de la voiture en m

float delta_T2 = 0;
float topDepart2 = 0;
float delta_t2(){
        return delta_T2 = ( millis() - topDepart2 )/1000.0;
                    }
float t2;
float v2;

void setup(){
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    lcd.begin(20, 4);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Mesurer la Vi"); 
    lcd.setCursor(0, 1);
    lcd.print("      au niveau"); 
    lcd.setCursor(0, 2);
    lcd.print("    du capteur 2"); 
    lcd.setCursor(0, 3);
    lcd.print(" Lachez la voiture !"); 
    
   }

void loop(){
    if((analogRead(A2)) < (950)){
        topDepart2 = millis();
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(13,600,100);
        while(!((analogRead(A2)) > (950)))
        
t2 = delta_t2();
v2 = L/t2;

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("    t2 = " + String(t2,3) + " ms");
          lcd.setCursor(0, 1);
          lcd.print("   Vi2 = " + String(v2,3) + " m/s");
          lcd.setCursor(0, 3);
          lcd.print(" Relachez la voiture");

    }else{
        digitalWrite(2,1);
        digitalWrite(4,0);
    }
}


