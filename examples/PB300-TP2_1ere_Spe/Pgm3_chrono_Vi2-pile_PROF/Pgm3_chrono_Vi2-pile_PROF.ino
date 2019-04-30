// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +


#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int LED_ROUGE = 7; 
const int LED_VERT = 5;
const int BUZZER = 9;

const float L = 0.048 ;  // L = Longueur de la pile en m


void setup(){
    pinMode(A2,INPUT);
    pinMode(LED_ROUGE,OUTPUT);
    pinMode(LED_VERT,OUTPUT);
    pinMode(BUZZER,OUTPUT); 
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("   Mesurer la Vi"); 
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("      au niveau"); 
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("    du capteur 2"); 
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("   Lachez la pile !"); 
    
   }

void loop(){
    float topDepart2 = 0;
    float t2;
    float v2;    
    
    if(analogRead(A2) < 950){
        topDepart2 = millis();
        digitalWrite(LED_VERT,0);
        digitalWrite(LED_ROUGE,1);
        tone(BUZZER,600,100);
        while(analogRead(A2) < 950)
        
        t2 = (millis() - topDepart2) / 1000.0;
        v2 = L / t2;

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    t2 = " + String(t2,3) + " ms");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   Vi2 = " + String(v2,3) + " m/s");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("  Relachez la pile ");

    }else{
        digitalWrite(LED_VERT,1);
        digitalWrite(LED_ROUGE,0);
    }
}


