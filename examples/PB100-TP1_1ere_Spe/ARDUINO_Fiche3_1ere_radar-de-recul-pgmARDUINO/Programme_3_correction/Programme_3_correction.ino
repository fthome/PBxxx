
// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB100 : Déterminer une distance à l'aide d'un microcontrôleur

#include <LiquidCrystal.h>                   // on importe la bibliothèque.
LiquidCrystal EcranLCD(12, 11, 5, 4, 3, 2);  // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100,
                                             // il est relié aux broches 12, 11, 5, 4, 3 et 2 de l'Arduino.

void setup()                          // La fonction setup s'execute une seule fois au démarrage du programme.
{                
    EcranLCD.begin(16, 2);            // on initialise la communication entre l'Arduino et l'afficheur (16 colonnes et 2 lignes).
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

  unsigned long distance = dureear/58.8 ;                  // teste la différence entre float et (int ou unsigned long)   Rq : variable dont on peut se dispenser                     

EcranLCD.clear();                               // Efface l'écran
EcranLCD.setCursor(0, 0);                       // Positionne le curseur Colonne 0, Ligne 0
EcranLCD.print("distance");               // Ecrit "temps A-R onde"
EcranLCD.setCursor(0, 1);                       // Positionne le curseur Colonne 0, Ligne 1
EcranLCD.print(" d = ");                        // Ecrit " t = "
EcranLCD.setCursor(5, 1);                       // Positionne le curseur Colonne 5, Ligne 1
EcranLCD.print(distance);                 // Afiche la distance qui sépare le télémètre à l'obstacle en cm
EcranLCD.setCursor(11, 1);                      // Positionne le curseur Colonne 11, Ligne 1
EcranLCD.print("cm");                           // Ecrit l'unité de la mesure "cm"
delay(1000);                                    // Petite pause de 1 seconde avant de faire une autre mesure (= une autre boucle ici).     
}

