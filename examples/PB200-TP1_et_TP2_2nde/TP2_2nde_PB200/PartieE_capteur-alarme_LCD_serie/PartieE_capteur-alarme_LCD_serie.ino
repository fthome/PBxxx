// Alarme à incendie qui se déclenche 
// lorsque T>25°C environ soit N<512

// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB200 : 
// Afficher la valeur de N et Uth d'un capteur sur un écran LCD et moniteur série.



// Fonctionne avec PB100 car PB200 n'a pas d'afficheur LCD

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C EcranLCD(0x20,16,2);

const int DEL_ROUGE = 7;
const int DEL_VERTE = 6;
const int BUZZER = 5;

void setup() {                 

    pinMode(A1,INPUT);
    pinMode(DEL_ROUGE,OUTPUT);
    pinMode(DEL_VERTE,OUTPUT);
    pinMode(BUZZER,OUTPUT);
    
    EcranLCD.begin(16, 2);
    Serial.begin(9600); // ouvir un port série
}

void loop()  {
  
    int N = analogRead(A1); 
    float U = N * 5.0 / 1023;
    
    if(N < 512){
        digitalWrite(DEL_VERTE,LOW);
        digitalWrite(DEL_ROUGE,HIGH);
        tone(BUZZER,650,500); 
        delay(500);
        digitalWrite(DEL_ROUGE,LOW);
        tone(BUZZER,750,500); 
        delay(500);
    }
    else{
        digitalWrite(DEL_VERTE,HIGH);
        digitalWrite(DEL_ROUGE,LOW);
    }


    
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





