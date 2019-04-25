
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float L = 0.048 ;  // L = Longueur de la pile en m

float delta_T1 = 0;
float topDepart1 = 0;
float delta_t1(){
        return delta_T1 = ( millis() - topDepart1 ) /1000.0;
                    }
float t1;
float v1;

float delta_T2 = 0;
float topDepart2 = 0;
float delta_t2(){
        return delta_T2 = ( millis() - topDepart2 ) /1000.0;
                    }
float t2;
float v2;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    lcd.begin(20, 4);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     Chronometre"); 
    lcd.setCursor(0, 1);
    lcd.print("     et calcule"); 
    lcd.setCursor(0, 2);
    lcd.print("   Vi1   et   Vi2"); 
    lcd.setCursor(0, 3);
    lcd.print(" Lance la pile !"); 
   }

void loop(){
  
  if((analogRead(A1)) < (950)){
        topDepart1 = millis();
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(13,600,100);
        while(!((analogRead(A1)) > (950)))

t1 = delta_t1();
v1 = L/t1;
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("   V1 = ");
          lcd.print(v1);
          lcd.print(" m/s");
   }
   
   else{
        digitalWrite(2,1);
        digitalWrite(4,0);

        if((analogRead(A2)) < (950)){
        topDepart2 = millis();
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(13,600,100);
        while(!((analogRead(A2)) > (950)))

t2 = delta_t2();
v2 = L/t2;
          lcd.setCursor(0, 1);
          lcd.print("   V2 = ");
          lcd.print(v2);
          lcd.print(" m/s");
               
          lcd.setCursor(0, 3);
          lcd.print("Relance la voiture !");
    }
     }
      }

