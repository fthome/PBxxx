// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float d = 0.80 ;  // distance entre les deux capteurs en m

float Delta_T = 0;
float topDepart = 0;
float Delta_t(){
      return Delta_T = ( millis() - topDepart ) / 1000.0 ;  // ainsi définie l'unité de Delta_t est la milliseconde.
                }
float t;
float v;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(13,OUTPUT);
    lcd.begin(20, 4);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Chronometrer et");
    lcd.setCursor(2, 1);
    lcd.print("en deduire Vmoy");    
    lcd.setCursor(0, 3);
    lcd.print("  Lachez l'objet !"); 
}

void loop(){
    if((analogRead(A1)) < (950))
     {
        topDepart = millis();                   // top chrono
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(13,600,100);
        while(!((analogRead(A2)) < (950)))       // arrêt chrono

t = Delta_t();                                   // affecte le résultat de la fonction Delta_t() à la variable t pour simplifier l'écriture de la suite du programme.
v = d/t;

          lcd.clear();
          lcd.setCursor(3, 0);
          lcd.print(" t = " + String(t,3) + " ms");
          lcd.setCursor(0, 1);
          lcd.print("  Vmoy = " + String(v,3) + " m/s");      
          lcd.setCursor(0, 3);
          lcd.print("* Relachez l'objet *"); 
       }
    else{
        digitalWrite(2,1);
        digitalWrite(4,0);
        } 
}
