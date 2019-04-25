#include <pbduino.h>                
Pb100 pb100;               

void setup()                          // La fonction setup s'execute une seule fois au démarrage du programme.
{                
pb100.init();
    pinMode(8, OUTPUT);               // La broche 8 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
    pinMode(9, INPUT);                // La broche 9 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
    digitalWrite(8, LOW);
}

void loop()                           // La fonction loop s'execute en boucle.     
{
   digitalWrite(8, HIGH);             // met la broche 8 TRIGGER à l'état haut pendant 10 microsecondes, puis envoi une salve d'ondes ultrasonores.
   delayMicroseconds(10);             
   digitalWrite(8, LOW);              // met la broche 8 TRIGGER à l'état bas, en attendant la prochaine boucle.

   unsigned long dureear = pulseIn(9, HIGH);    // Le dispositif reçoit l'ECHO de la salve sur la broche 9, mesure le temps de vol Aller-Retour en microsecondes,
                                                // et enregitre la valeur dans la variable nommée ici "dureear"(=durée aller retour).

pb100.lcd->clear();                               // Efface l'écran
pb100.lcd->setCursor(0, 0);                       // Positionne le curseur Colonne 0, Ligne 0
pb100.lcd->print("temps A-R onde");               // Ecrit "temps A-R onde"
pb100.lcd->setCursor(0, 1);                       // Positionne le curseur Colonne 0, Ligne 1
pb100.lcd->print(" t = ");                        // Ecrit " t = "
pb100.lcd->setCursor(5, 1);                       // Positionne le curseur Colonne 5, Ligne 1
pb100.lcd->print(dureear/1000.0);                 // Afiche la mesure du temps de vol de l'onde en millisecondes.
pb100.lcd->setCursor(10, 1);                      // Positionne le curseur Colonne 10, Ligne 1
pb100.lcd->print("ms");                           // Ecrit l'unité de la mesure "ms"
delay(1000);                                    // Petite pause de 1 seconde avant de faire une autre mesure (= une autre boucle ici).     
}

