#include <pbduino.h>
Pb300 pb300;

void setup(){
 
 pb300.init();
 pinMode(A0,INPUT);  // entrée analogique capteur 1
 pinMode(A1,INPUT);  // entrée analogique capteur 2

 Serial.begin(9600);

pb300.lcd->clear();
pb300.lcd->setCursor(0, 0);
pb300.lcd->print("TEST entree A1 et A2");
pb300.lcd->setCursor(0, 1);
pb300.lcd->print(" sur Moniteur serie");
pb300.lcd->setCursor(0, 2);
pb300.lcd->print("  et sur ecran LCD");
}

void loop(){
    int Capteur1=analogRead(A0);
    int Capteur2=analogRead(A1);
 
   Serial.print("     Capteur1 : ");Serial.print(Capteur1); Serial.print("     Capteur2 : ");Serial.println(Capteur2);
pb300.lcd->setCursor(0, 3);
pb300.lcd->print(" A0 = "); 
pb300.lcd->print(Capteur1);
pb300.lcd->print(" A1 = "); 
pb300.lcd->print(Capteur2);
   
delay(1000);
}
