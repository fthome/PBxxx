
#include "pbduino.h"

int voltage;
Pb300 pb300; // Déclaration de ma maquette PB100
int clignotant = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("PIERRON - PB300");
  pb300.init();
  //TEST FONCTIONNEL
  pb300.buzzer();
  pb300.set_led_rouge(HIGH);
  delay(1000);
  pb300.buzzer(880);
  pb300.set_led_verte(HIGH);
  delay(1000);
  pb300.noBuzzer();
  pb300.eteint_led_rouge();
  pb300.eteint_led_verte();
}

void loop() {
  voltage = pb300.get_photo1();
  pb300.affiche(voltage,1);
  voltage = pb300.get_photo2();
  pb300.affiche(voltage,2);
  // CLIGNOTANT
  if (clignotant){
    pb300.eteint_led_rouge();
    pb300.allume_led_verte();
    clignotant = 0;
  }else{
    pb300.allume_led_rouge();
    pb300.eteint_led_verte();
    clignotant++;
  }
  delay(500);
}
