// Alarme à incendie qui se déclenche 
// lorsque T>25°C environ soit N<512

// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB200 : 
// Afficher la valeur de N et Uth d'un capteur sur un écran LCD et moniteur série.



// Fonctionne avec PB100 car PB200 n'a pas d'afficheur LCD

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C EcranLCD(0x20,16,2);

const int pin_led_verte = 3;
const int pin_led_rouge = 4;
const int pin_buzzer = 2;

void setup() {                 

    pinMode(A1,INPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
    pinMode(pin_buzzer,OUTPUT);
    
    EcranLCD.begin(16, 2);
    Serial.begin(9600); // ouvir un port série
}

void loop()  {
  
    int N = analogRead(A1); 
    float U = N * 5.0 / 1023;
    
    if(N < 512){
        digitalWrite(pin_led_verte,LOW);
        digitalWrite(pin_led_rouge,HIGH);
        tone(pin_buzzer,650,500); 
        delay(500);
        digitalWrite(pin_led_rouge,LOW);
        tone(pin_buzzer,750,500); 
        delay(500);
    }
    else{
        digitalWrite(pin_led_verte,HIGH);
        digitalWrite(pin_led_rouge,LOW);
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





