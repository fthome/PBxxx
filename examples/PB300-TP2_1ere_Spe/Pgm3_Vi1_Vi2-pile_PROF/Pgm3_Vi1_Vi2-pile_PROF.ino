// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à  + String(v1,3) + 

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int pin_led_rouge = 4; 
const int pin_led_verte = 2;
const int pin_buzzer = 6;

const float L = 0.048 ;  // L = Longueur de la pile en m



void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT); 
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("     Chronometre"); 
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("     et calcule"); 
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("   Vi1   et   Vi2"); 
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" Lance la pile !"); 
   }

void loop(){
  float top_depart_1 = 0;
  float t1;
  float v1;


  float top_depart_2 = 0;
  float t2;
  float v2;

  if(analogRead(A1) < 950){
        top_depart_1 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(A1) < 950)

        t1 = (millis() - top_depart_1) /1000.0;
        v1 = L/t1;
          
        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("   V1 = " + String(v1,3) + " m/s");

   }
   
   else{
        digitalWrite(pin_led_verte,1);
        digitalWrite(pin_led_rouge,0);

        if(analogRead(A2) < 950){
            top_depart_2 = millis();
            digitalWrite(pin_led_verte,0);
            digitalWrite(pin_led_rouge,1);
            tone(pin_buzzer,600,100);
            while(analogRead(A2) < 950)

            t2 = (millis() - top_depart_2) /1000.0;
            v2 = L/t2;

            EcranLCD.setCursor(0, 1);
            EcranLCD.print("   V2 = " + String(v2,3) + " m/s");
               
            EcranLCD.setCursor(0, 3);
            EcranLCD.print("Relance la pile !");
        }
  }
}

