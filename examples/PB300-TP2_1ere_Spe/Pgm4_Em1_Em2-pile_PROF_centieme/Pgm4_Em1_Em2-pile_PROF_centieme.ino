
#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int pin_led_rouge = 4; 
const int pin_led_verte = 2;
const int pin_buzzer = 6;

const float m = 0.048 ; // masse de l'objet en kg (ici objet = petite voiture jaune métallique !)
const float L = 0.048 ;  // Longueur de l'objet en m (ici objet = petite voiture jaune métallique !)
const float g = 9.81 ;
const float h = 0.25 ;




void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT); 
    
    EcranLCD.begin(20, 4);
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("  Bilan d'ENERGIE"); 
    EcranLCD.setCursor(0, 1);
    EcranLCD.print(" Affiche Em1 et Em2"); 
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("   Lance l'objet !"); 
   }

void loop(){
    float top_depart_1 = 0;
    float t1;
    float v1;
    float ec1;
    float epp1;
    float em1;

    float top_depart_2 = 0;
    float t2;
    float v2;
    float ec2;
    float epp2;
    float em2;

    float delta_em;
  
    if(analogRead(A1) < 950){
        top_depart_1 = millis();
        digitalWrite(pin_led_verte,0);
        digitalWrite(pin_led_rouge,1);
        tone(pin_buzzer,600,100);
        while(analogRead(A1) < 950)

        t1 = (millis() - top_depart_1) /1000.0 ;
        v1 = L / t1;
        ec1 = 0.5 * m * v1 * v1;
        epp1 = m * g * h;
        em1 = ec1 + epp1;

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("Ec1=");
        EcranLCD.print(ec1);
        EcranLCD.print("J ");
        EcranLCD.print("Epp1=");
        EcranLCD.print(epp1);
        EcranLCD.print("J ");
        EcranLCD.setCursor(0, 1);
        EcranLCD.print("    Em1 = ");
        EcranLCD.print(em1);
        EcranLCD.print(" J");
        
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
            epp2 = 0;
            em2 = ec2 + epp2;
            delta_em = em2 - em1;

            EcranLCD.setCursor(0, 2);
            EcranLCD.print("Ec2=");
            EcranLCD.print(ec2);
            EcranLCD.print("J ");
            EcranLCD.print("Epp2=");
            EcranLCD.print(epp2);
            EcranLCD.print("J ");
            EcranLCD.setCursor(0, 3);
            EcranLCD.print("    Em2 = ");
            EcranLCD.print(em2);
            EcranLCD.print(" J");
      
      } 
  }
}

