// Programme et maquette PB300 réalisés par patrice.buffet@ac-amiens.fr
// intégration dans ce programme de 3 chiffres après la virgule au lieu de 2 grâce à 
// char st1[20];
// char sv1[20]; 
// char sEc1[20];        
// dtostrf(t1,5,3,st1);  
// dtostrf(v1,5,3,sv1);
// dtostrf(Ec1,5,3,sEc1);
// lcd.print(st1);
// lcd.print(sv1);     
// lcd.print(Ec1);     idem avec indice 2

#include <LiquidCrystal_I2C.h>                
LiquidCrystal_I2C EcranLCD(0x20,20,4);

const int LED_ROUGE = 4; 
const int LED_VERT = 2;
const int BUZZER = 6;

const float m = 0.048 ;  // masse de l'ojet en kg (ici objet = pile 9V)
const float L = 0.048 ;  // Longueur de l'objet en m (ici objet = pile 9V)
const float g = 9.81 ;   // intensité de la pesanteur en m/s^2
const float h = 0.25 ;   // hauteur de chute en m



void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(LED_ROUGE,OUTPUT);
    pinMode(LED_VERT,OUTPUT);
    pinMode(BUZZER,OUTPUT); 
    
    EcranLCD.begin(20, 4);
    Serial.begin(9600);
    
    EcranLCD.clear();
    EcranLCD.setCursor(0, 0);
    EcranLCD.print("Travail W des forces"); 
    EcranLCD.setCursor(0, 1);
    EcranLCD.print("   de frottements"); 
    EcranLCD.setCursor(0, 2);
    EcranLCD.print("    d'un objet."); 
    EcranLCD.setCursor(0, 3);
    EcranLCD.print("  Lance cet objet !"); 
   }

void loop(){
    float topDepart1 = 0;
    float t1;
    float v1;
    float Ec1;
    float Epp1;
    float Em1;

    float topDepart2 = 0;
    float t2;
    float v2;
    float Ec2;
    float Epp2;
    float Em2;
    float DeltaEm;

if(analogRead(A1) < 950){
        topDepart1 = millis();
        digitalWrite(LED_VERT,0);
        digitalWrite(LED_ROUGE,1);
        tone(BUZZER,600,100);
        while(analogRead(A1) < 950)

        t1 = (millis() - topDepart1) /1000.0 ;
        v1 = L / t1;
        Ec1 = 0.5 * m * v1 * v1;
        Epp1 = m * g * h;
        Em1 = Ec1 + Epp1;

        EcranLCD.clear();
        EcranLCD.setCursor(0, 0);
        EcranLCD.print("   Em1 = " + String(Em1,3) + " J");
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
            Epp2 = 0;
            Em2 = Ec2 + Epp2;
            DeltaEm = Em2 - Em1;
            

            EcranLCD.setCursor(0, 1);
            EcranLCD.print("   Em2 = " + String(Em2,3) + " J");

            EcranLCD.setCursor(0, 2);
            EcranLCD.print("Em2 - Em1 = " + String(DeltaEm,3) + " J");

            EcranLCD.setCursor(0, 3);
            EcranLCD.print("   -->  W = " + String(DeltaEm,3) + " J");


       
            Serial.println(String(t1,3));
            Serial.println(String(t2,3));
            Serial.println(String(DeltaEm,3));
        }
   }
}