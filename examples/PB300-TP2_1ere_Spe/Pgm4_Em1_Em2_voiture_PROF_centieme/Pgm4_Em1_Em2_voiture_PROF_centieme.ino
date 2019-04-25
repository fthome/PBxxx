
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float m = 0.036 ; // masse de l'objet en kg (ici objet = petite voiture jaune métallique !)
float L = 0.070 ;  // Longueur de l'objet en m (ici objet = petite voiture jaune métallique !)
float g = 9.81 ;
float h = 0.25 ;

float delta_T1 = 0;
float topDepart1 = 0;
float delta_t1(){
        return delta_T1 = ( millis() - topDepart1 ) /1000.0 ;
                    }
float t1;
float v1;
float Ec1;
float Epp1;
float Em1;
         
float delta_T2 = 0;
float topDepart2 = 0;
float delta_t2(){
        return delta_T2 = ( millis() - topDepart2 ) /1000.0 ;
                    }
float t2;
float v2;
float Ec2;
float Epp2;
float Em2;
float DeltaEm;

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    lcd.begin(20, 4);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Bilan d'ENERGIE"); 
    lcd.setCursor(0, 1);
    lcd.print(" Affiche Em1 et Em2"); 
    lcd.setCursor(0, 3);
    lcd.print("   Lance l'objet !"); 
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
Epp1 = m*g*h;
Em1 = Ec1 + Epp1;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Ec1=");
        lcd.print(Ec1);
        lcd.print("J ");
        lcd.print("Epp1=");
        lcd.print(Epp1);
        lcd.print("J ");
        lcd.setCursor(0, 1);
        lcd.print("    Em1 = ");
        lcd.print(Em1);
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
Epp2 = 0;
Em2 = Ec2 + Epp2;
DeltaEm = Em2-Em1;

        lcd.setCursor(0, 2);
        lcd.print("Ec2=");
        lcd.print(Ec2);
        lcd.print("J ");
        lcd.print("Epp2=");
        lcd.print(Epp2);
        lcd.print("J ");
        lcd.setCursor(0, 3);
        lcd.print("    Em2 = ");
        lcd.print(Em2);
        lcd.print(" J");
      
    }
     }
      }

