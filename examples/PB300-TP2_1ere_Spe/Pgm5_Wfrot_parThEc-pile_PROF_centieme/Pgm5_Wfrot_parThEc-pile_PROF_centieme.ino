
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float m = 0.048 ; // masse de l'ojet en kg
float L = 0.048 ;  // Longueur de l'objet en m
float g = 9.81 ;  // intensité de la pesanteur en m/s^2
float h = 0.25 ;  // hauteur de chute en m


float delta_T1 = 0;
float topDepart1 = 0;
float delta_t1(){
        return delta_T1 = ( millis() - topDepart1 ) /1000.0 ;
                    }
float t1;
float v1;
float Ec1;
         
float delta_T2 = 0;
float topDepart2 = 0;
float delta_t2(){
        return delta_T2 = ( millis() - topDepart2 ) /1000.0 ;
                    }
float t2;
float v2;
float Ec2;
float DeltaEc;
float Epp;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    lcd.begin(20, 4);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Travail W des forces"); 
    lcd.setCursor(0, 1);
    lcd.print("   de frottements"); 
    lcd.setCursor(0, 2);
    lcd.print("    d'un objet"); 
    lcd.setCursor(0, 3);
    lcd.print("  Lance cet objet !"); 
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
Ec1 = 0.5*m*v1*v1;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    Ec1 = ");
        lcd.print(Ec1);
        lcd.print(" J");
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
Ec2 = 0.5*m*v2*v2;
DeltaEc = Ec2-Ec1;
Epp = m*g*h;

      lcd.setCursor(0, 1);
      lcd.print("    Ec2 = ");
      lcd.print(Ec2);
      lcd.print(" J");

      lcd.setCursor(0, 2);
      lcd.print(" Ec2 - Ec1 = ");
      lcd.print(DeltaEc);
      lcd.print(" J");

      lcd.setCursor(0, 3);
      lcd.print("     W = ");
      lcd.print(DeltaEc-Epp);
      lcd.print(" J");     
    }
     }
      }
