
#include "pbduino.h"

float distance;
Pb100 pb100; // Déclaration de ma maquette PB100

void setup() {
  Serial.begin(9600);
  Serial.print("PIERRON - PB100");
  pb100.init();
  pb100.eteintEcran(); // ou pb100.lcd->noBacklight()
}

void loop() {
  distance = pb100.distance();
  Serial.println("Mesure : " + String(distance,4) + "mm");
  if (distance ==0){
    pb100.lcd->setCursor(0,1);
    pb100.lcd->print("Distance: ???   "); //Syntaxe qui permet d'utiliser toutes les méthodes de LiquidCristal
  }else{
    pb100.affiche("Distance: " + String(distance,0) + "mm ",1); //Syntaxe simplifiée
  }
  if (distance > 100){
    pb100.allume_led_verte();
    pb100.eteint_led_rouge();
    pb100.noBuzzer();
    //pb100.eteintEcran();// ou pb100.lcd->noBacklight();
  }else if (distance != 0){
    pb100.allume_led_rouge();
    pb100.eteint_led_verte();
    pb100.buzzer();
    //pb100.allumeEcran();//ou pb100.lcd->backlight();
  }
    delay(500);
}
