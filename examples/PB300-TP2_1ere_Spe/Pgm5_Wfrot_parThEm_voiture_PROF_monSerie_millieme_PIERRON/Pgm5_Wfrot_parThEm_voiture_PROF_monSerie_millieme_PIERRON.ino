
#include <pbduino.h>
Pb300 pb300;

float m = 0.036 ;  // masse de l'ojet en kg (ici objet = petite voiture jaune métallique !)
float L = 0.070 ;  // Longueur de l'objet en m (ici objet = petite voiture jaune métallique !)
float g = 9.81 ;   // intensité de la pesanteur en m/s^2
float h = 0.25 ;   // hauteur de chute en m


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
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
pb300.init();
    Serial.begin(9600);
    
    pb300.lcd->clear();
    pb300.lcd->setCursor(0, 0);
    pb300.lcd->print("W Travail des forces"); 
    pb300.lcd->setCursor(0, 1);
    pb300.lcd->print("   de frottements"); 
    pb300.lcd->setCursor(0, 2);
    pb300.lcd->print("    d'un objet."); 
    pb300.lcd->setCursor(0, 3);
    pb300.lcd->print(" Lance la voiture !"); 
   }

void loop(){
    if((analogRead(A0)) < (400)){
        topDepart1 = millis();
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(6,600,100);
        while(!((analogRead(A0)) > (400)))

t1 = delta_t1();
v1 = L/t1;
Ec1 = 0.5*m*v1*v1;
Epp1 = m*g*h;
Em1 = Ec1+Epp1;

    pb300.lcd->clear();
    pb300.lcd->setCursor(0, 0);
    pb300.lcd->print("   Em1 = " + String(Em1,3) + " J");
   }
   
   else{
        digitalWrite(2,1);
        digitalWrite(4,0);

        if((analogRead(A1)) < (400)){
        topDepart2 = millis();
        digitalWrite(2,0);
        digitalWrite(4,1);
        tone(6,600,100);
        while(!((analogRead(A1)) > (400)))

t2 = delta_t2();
v2 = L/t2;
Ec2 = 0.5*m*v2*v2;
Epp2 = 0;
Em2 = Ec2 + Epp2;
DeltaEm = Em2-Em1;

    pb300.lcd->setCursor(0, 1);
    pb300.lcd->print("   Em2 = " + String(Em2,3) + " J");

    pb300.lcd->setCursor(0, 2);
    pb300.lcd->print("Em2 - Em1 = " + String(DeltaEm,3) + " J");

    pb300.lcd->setCursor(0, 3);
    pb300.lcd->print("   -->  W = " + String(DeltaEm,3) + " J");

      Serial.println(DeltaEm);
    }
     }
      }
