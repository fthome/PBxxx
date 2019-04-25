// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à  + String(...,3) +

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float Delta_T = 0;
float topDepart = 0;
float Delta_t(){
  return Delta_T = ( millis() - topDepart ) / 1000.0;  // ainsi définie l'unité de Delta_t est la milliseconde.
               }
float t;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(13,OUTPUT);       // déclarez la broche 13 comme une sortie
    
    lcd.begin(20, 4);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   CHRONOMETREZ");  
    lcd.setCursor(0, 1);
    lcd.print("  une course avec");
    lcd.setCursor(0, 2);
    lcd.print(" le microcontroleur");
    lcd.setCursor(6, 3);
    lcd.print("ARDUINO");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Lachez l'objet   ");
    lcd.setCursor(0, 1);
    lcd.print("    sur la rampe    ");
    lcd.setCursor(0, 2);
    lcd.print("   de la maquette ");
    lcd.setCursor(0, 3);
    lcd.print("       PB300    ");
}

void loop(){
    if((analogRead(A1)) < (950)){
        topDepart = millis();                 // top chrono
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(13,600,100);              // Ligne à compléter par l'élève
        while(!((analogRead(A2)) < (950)))   // arrêt chrono

t=Delta_t();                                 // affecte le résultat de la fonction Delta_t() à la variable t pour simplifier l'écriture de la suite du programme.

        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("   duree = " + String(t,3) + " s");
        lcd.setCursor(0, 3);
        lcd.print("* Relancez l'objet *");
     }
       else{
        digitalWrite(2,1);
        digitalWrite(4,0);
        }
}


