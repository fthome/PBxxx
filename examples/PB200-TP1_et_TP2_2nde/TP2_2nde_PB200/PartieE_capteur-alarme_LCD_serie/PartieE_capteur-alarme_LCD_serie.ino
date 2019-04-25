// Alarme à incendie qui se déclenche 
// lorsque T>25°C environ soit N<512

// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB200 : 
// Afficher la valeur de N et Uth d'un capteur sur un écran LCD et moniteur série.

#include <LiquidCrystal.h>                
LiquidCrystal EcranLCD(12, 11, 9, 8, 7, 6);                                        

void setup() {                 

    pinMode(A1,INPUT);
    pinMode(5,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(13,OUTPUT);
    
    EcranLCD.begin(16, 2);
    Serial.begin(9600); // ouvir un port série
}

void loop()  {

    if(analogRead(A1) < (512)){
        digitalWrite(5,LOW);
        digitalWrite(2,HIGH);
        tone(13,650,500); 
        delay(500);
        digitalWrite(2,LOW);
        tone(13,750,500); 
        delay(500);
    }
     else{
        digitalWrite(5,HIGH);
        digitalWrite(2,LOW);
         }
    
 int N = analogRead(A1); 
 float U = N*4.64/1023;

   Serial.print("Valeur numerique mesuree par le capteur : N = ");
   Serial.print(N);
   Serial.print("    Tension : U = ");
   Serial.print(U);
   Serial.println(" V ");
   
    EcranLCD.clear();                 
    EcranLCD.setCursor(0, 0);       
    EcranLCD.print(" nombre N = ");
    EcranLCD.print(N);     
    EcranLCD.setCursor(0, 1);           
    EcranLCD.print("    U = ");
    EcranLCD.print(U);  
    EcranLCD.print(" V");
                       
}   





