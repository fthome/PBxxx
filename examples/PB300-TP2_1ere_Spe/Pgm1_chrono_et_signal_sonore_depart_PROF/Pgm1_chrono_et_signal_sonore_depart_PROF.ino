// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à  + String(...,3) +

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int LED_ROUGE = 7; 
const int LED_VERT = 5;
const int BUZZER = 9;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(LED_ROUGE,OUTPUT);
    pinMode(LED_VERT,OUTPUT);
    pinMode(BUZZER,OUTPUT);       // déclarez la broche 9 comme une sortie
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   CHRONOMETREZ");  
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("  une course avec");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print(" le microcontroleur");
    EcranLCD.setCursor(6, 3);
    EcranLCD.print("ARDUINO");
    delay(4000);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   Lachez l'objet   ");
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("    sur la rampe    ");
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("   de la maquette ");
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("       PB300    ");
}

void loop(){
float topDepart = 0;
float t;

    if(analogRead(A1) < 950){
        topDepart = millis();                 // top chrono
        digitalWrite(LED_VERT,0);
        digitalWrite(LED_ROUGE,1);
        tone(BUZZER,600,100);              // Ligne à compléter par l'élève
        while(analogRead(A2) > 950)   // arrêt chrono

        t =(millis() - topDepart) / 1000.0;  // ainsi définie l'unité de t est la milliseconde.

        EcranLCD.clear();
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   duree = " + String(t,3) + " s");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("* Relancez l'objet *");
     }
       else{
        digitalWrite(LED_VERT,1);
        digitalWrite(LED_ROUGE,0);
        }
}


