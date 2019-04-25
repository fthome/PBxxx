
// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB100 : Simulation d'un radar de recul à l'aide d'un microcontrôleur (demo prof)

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}



void setup(){
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(13,OUTPUT);
      lcd.begin(16, 2);
}

void loop(){


  
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
        
    }else{
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
  } } }



