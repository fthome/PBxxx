


// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB100 : Simulation d'un radar de recul à l'aide d'un microcontrôleur (demo prof)

#include <LiquidCrystal_I2C.h>                // on importe la bibliothèque.
LiquidCrystal_I2C EcranLCD(0x20,16,2);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100.

const int pin_E = 11;
const int pin_R = 12;
const int DEL_ROUGE = 7;
const int DEL_VERTE = 6;
const int BUZZER = 5;

float getDistance()
{
unsigned long temps1;
unsigned long dureear;

  
   digitalWrite(pin_E, HIGH);             // met la broche 11 TRIGGER à l'état haut pendant 10 microsecondes, puis envoi une salve d'ondes ultrasonores.
   delayMicroseconds(10);             
   digitalWrite(pin_E, LOW);              // met la broche 11 TRIGGER à l'état bas, en attendant la prochaine boucle.

   temps1 = millis();
   while(pin_R == HIGH) 
   {
    // Attente retour ECHO
   }

   dureear = millis() - temps1; 

   return dureear / 58.8;
}


//float getDistance(int trig,int echo){
//    pinMode(trig,OUTPUT);
//    digitalWrite(trig,LOW);
//    delayMicroseconds(2);
//    digitalWrite(trig,HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trig,LOW);
//    pinMode(echo, INPUT);
//   return pulseIn(echo,HIGH,30000)/58.0;
//}



void setup(){
   EcranLCD.begin(16, 2);            // on initialise la communication entre l'Arduino et l'afficheur (16 colonnes et 2 lignes).
   pinMode(pin_E, OUTPUT);               // La broche 11 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
   pinMode(pin_R, INPUT);                // La broche 12 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
   digitalWrite(pin_E, LOW);
   pinMode(DEL_ROUGE, OUTPUT); 
   pinMode(DEL_VERTE, OUTPUT); 
   pinMode(BUZZER, OUTPUT); 
}


void loop(){

unsigned long distance;

    distance = getDistance();
    
    if(distance < 50)
    {
      digitalWrite(DEL_ROUGE,1);
      digitalWrite(DEL_VERTE,0);
      tone(BUZZER,600,125); 
      delay(125);

      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);

      EcranLCD.print(" cm");
    }
    else if(distance < 100)
    {
      digitalWrite(DEL_ROUGE,1);
      digitalWrite(DEL_VERTE,0);
      tone(BUZZER,600,125); 
      delay(300);

      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);

      EcranLCD.print(" cm");
    }
    else
    {
      digitalWrite(DEL_ROUGE,0);
      digitalWrite(DEL_VERTE,1);
                
      EcranLCD.clear();
      EcranLCD.setCursor(0, 0);
      EcranLCD.print(" Radar de recul");
      EcranLCD.setCursor(0, 1);
      EcranLCD.print(" d = ");
      EcranLCD.print(distance);
 
      EcranLCD.print(" cm");
      delay(2000);
    }
    
    /*
    if((getDistance(8,9)) < (50)){
        digitalWrite(6,1);
        digitalWrite(7,0);
        tone(13,600,125); 
        delay(125);

      lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" Radar de recul");
lcd.setCursor(0, 1);
lcd.print(" d = ");
lcd.print(getDistance(8,9));

lcd.print(" cm");
        
    }
    
    else{
        if((getDistance(8,9)) < (100)){
            digitalWrite(6,1);
            digitalWrite(7,0);
            tone(13,600,125); 
          delay(300);

                  lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" Radar de recul");
lcd.setCursor(0, 1);
lcd.print(" d = ");
lcd.print(getDistance(8,9));

lcd.print(" cm");

        }else{
            digitalWrite(6,0);
            digitalWrite(7,1);
                
                  lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" Radar de recul");
lcd.setCursor(0, 1);
lcd.print(" d = ");
lcd.print(getDistance(8,9));
 
lcd.print(" cm");
delay(2000);
  } }
  */ 
}



