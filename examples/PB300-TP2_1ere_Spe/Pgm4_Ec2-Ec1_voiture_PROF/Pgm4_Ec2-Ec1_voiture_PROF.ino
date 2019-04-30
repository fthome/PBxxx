// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int pin_led_rouge = 4; 
const int pin_led_verte = 2;
const int pin_buzzer = 6;

const float m = 0.036 ; // masse de l'objet en kg (ici objet = petite voiture jaune métallique !)
const float L = 0.070 ;  // Longueur de l'objet en m (ici objet = petite voiture jaune métallique !)

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT); 
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("  Mesurer V1 et V2"); 
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" Afficher Ec2 - Ec1"); 
    EcranLCD.setCursor(0, 3);
    EcranLCD.print(" Lance la voiture !"); 
   }

void loop(){
    float top_depart_1 = 0;
    float t1;
    float v1;
    float ec1;
         
    float top_depart_2 = 0;
    float t2;
    float v2;
    float ec2;

    float delta_ec;

  
    if(analogRead(A1) < 950){
        top_depart_1 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(A1) < 950)

        t1 = (millis() - top_depart_1) /1000.0 ;
        v1 = L / t1;
        ec1 = 0.5 * m * v1 * v1;
        
        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    Ec1 = " + String(ec1,3) + " J");
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

            t2 = (millis() - top_depart_2) /1000.0 ;
            v2 = L / t2;
            ec2 = 0.5 * m * v2 * v2;
            delta_ec = ec2 - ec1;

            EcranLCD.setCursor(0, 1);
            EcranLCD.print("    Ec2 = " + String(ec2,3) + " J");
            EcranLCD.setCursor(0, 3);
            EcranLCD.print("Ec2 - Ec1 = " + String(delta_ec,3) + " J");
        }
  }
}

