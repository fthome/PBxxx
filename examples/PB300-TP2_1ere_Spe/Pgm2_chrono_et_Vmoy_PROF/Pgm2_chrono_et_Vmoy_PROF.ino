// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +


#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int LED_ROUGE = 7; 
const int LED_VERT = 5;
const int BUZZER = 9;

const float d = 0.80;   // distance entre les deux capteurs en m


void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(LED_ROUGE,OUTPUT);
    pinMode(LED_VERT,OUTPUT);
    pinMode(BUZZER,OUTPUT);       
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(2, 0);
    EcranLCD.print("Chronometrer et");
    EcranLCD.setCursor(2, 1);
    EcranLCD.print("en deduire Vmoy");    
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("  Lachez l'objet !"); 
}

void loop(){
float topDepart = 0;
float t;
float v;
    
    if(analogRead(A1) < 950)
     {
        topDepart = millis();                   // top chrono
        digitalWrite(LED_VERT,0);
        digitalWrite(LED_ROUGE,1);
        tone(BUZZER,600,100);
        while(analogRead(A2) > 950)       // arrêt chrono

        t =(millis() - topDepart) / 1000.0;  // ainsi définie l'unité de t est la milliseconde.
        v = d / t;

        EcranLCD.clear();
        EcranLCD.setCursor(3, 0);
        EcranLCD.print(" t = " + String(t,3) + " ms");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("  Vmoy = " + String(v,3) + " m/s");      
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("* Relachez l'objet *"); 
       }
    else{
        digitalWrite(LED_VERT,1);
        digitalWrite(LED_ROUGE,0);
        } 
}
