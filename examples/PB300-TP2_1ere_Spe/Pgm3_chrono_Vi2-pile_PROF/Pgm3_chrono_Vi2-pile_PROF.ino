// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +


#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int pin_led_rouge = 4; 
const int pin_led_verte = 2;
const int pin_buzzer = 6;

const float L = 0.048 ;  // L = Longueur de la pile en m


void setup(){
    pinMode(A2,INPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT); 
    
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
    float top_depart_2 = 0;
    float t2;
    float v2;    
    
    if(analogRead(A2) < 950){
        top_depart_2 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(A2) < 950)
        
        t2 = (millis() - top_depart_2) / 1000.0;
        v2 = L / t2;

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    t2 = " + String(t2,3) + " ms");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("   Vi2 = " + String(v2,3) + " m/s");
        EcranLCD.setCursor(0, 3);
        EcranLCD.print("  Relachez la pile ");

    }else{
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);
    }
}


