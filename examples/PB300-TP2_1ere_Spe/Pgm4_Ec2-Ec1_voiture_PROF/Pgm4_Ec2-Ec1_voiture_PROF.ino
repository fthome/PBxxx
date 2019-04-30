// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à + String(...,3) +

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int LED_ROUGE = 7; 
const int LED_VERT = 5;
const int BUZZER = 9;

const float m = 0.036 ; // masse de l'objet en kg (ici objet = petite voiture jaune métallique !)
const float L = 0.070 ;  // Longueur de l'objet en m (ici objet = petite voiture jaune métallique !)



void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(LED_ROUGE,OUTPUT);
    pinMode(LED_VERT,OUTPUT);
    pinMode(BUZZER,OUTPUT); 
    
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
    float topDepart1 = 0;
    float t1;
    float v1;
    float Ec1;
         
    float topDepart2 = 0;
    float t2;
    float v2;
    float Ec2;

    float DeltaEc;

  
    if(analogRead(A1) < 950){
        topDepart1 = millis();
        digitalWrite(LED_VERT,0);
        digitalWrite(LED_ROUGE,1);
        tone(BUZZER,600,100);
        while(analogRead(A1) < 950)

        t1 = (millis() - topDepart1) /1000.0 ;
        v1 = L / t1;
        Ec1 = 0.5 * m * v1 * v1;
        
        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("    Ec1 = " + String(Ec1,3) + " J");
   }
   
   else{
        digitalWrite(LED_VERT,1);
        digitalWrite(LED_ROUGE,0);

        if(analogRead(A2) < 950){
            topDepart2 = millis();
            digitalWrite(LED_VERT,0);
            digitalWrite(LED_ROUGE,1);
            tone(BUZZER,600,100);
            while(analogRead(A2) < 950)

            t2 = (millis() - topDepart2) /1000.0 ;
            v2 = L / t2;
            Ec2 = 0.5 * m * v2 * v2;
            DeltaEc = Ec2 - Ec1;

            EcranLCD.setCursor(0, 1);
            EcranLCD.print("    Ec2 = " + String(Ec2,3) + " J");
            EcranLCD.setCursor(0, 3);
            EcranLCD.print("Ec2 - Ec1 = " + String(DeltaEc,3) + " J");
        }
  }
}

