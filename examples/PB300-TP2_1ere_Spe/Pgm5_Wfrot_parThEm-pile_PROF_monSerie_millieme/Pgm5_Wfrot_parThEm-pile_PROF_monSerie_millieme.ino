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

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float m = 0.048 ;  // masse de l'ojet en kg (ici objet = pile 9V)
float L = 0.048 ;  // Longueur de l'objet en m (ici objet = pile 9V)
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
char st1[20];
char sv1[20]; 
char sEc1[20];
char sEpp1[20];
char sEm1[20];
         
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
char st2[20];
char sv2[20]; 
char sEc2[20]; 
char sEpp2[20]; 
char sEm2[20];
char sDeltaEm[20];

void setup(){
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
    lcd.begin(20, 4);
    Serial.begin(9600);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Travail W des forces"); 
    lcd.setCursor(0, 1);
    lcd.print("   de frottements"); 
    lcd.setCursor(0, 2);
    lcd.print("    d'un objet."); 
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
Epp1 = m*g*h;
Em1 = Ec1+Epp1;
dtostrf(t1,5,3,st1);  
dtostrf(v1,5,3,sv1);
dtostrf(Ec1,5,3,sEc1);
dtostrf(Epp1,5,3,sEpp1);
dtostrf(Em1,5,3,sEm1);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("   Em1 = ");
        lcd.print(sEm1);
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
dtostrf(t2,5,3,st2);  
dtostrf(v2,5,3,sv2);
dtostrf(Ec2,5,3,sEc2);
dtostrf(Epp2,5,3,sEpp2);
dtostrf(Em2,5,3,sEm2);
dtostrf(DeltaEm,5,3,sDeltaEm);

      lcd.setCursor(0, 1);
      lcd.print("   Em2 = ");
      lcd.print(sEm2);
      lcd.print(" J");

      lcd.setCursor(0, 2);
      lcd.print("Em2 - Em1 = ");
      lcd.print(sDeltaEm);
      lcd.print(" J");

      lcd.setCursor(0, 3);
      lcd.print("   -->  W = ");
      lcd.print(sDeltaEm);
      lcd.print(" J");  

      Serial.println(st1);Serial.println(st2);Serial.println(sDeltaEm);
    }
     }
      }
