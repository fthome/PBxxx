


// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB100 : Déterminer la célérité d'une onde à l'aide d'un microcontrôleur

#include <LiquidCrystal_I2C.h>                // on importe la bibliothèque.
LiquidCrystal_I2C EcranLCD(0x20,16,2);

//#include <LiquidCrystal.h>                   
//LiquidCrystal EcranLCD(12, 11, 5, 4, 3, 2);  // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100,
                                             // il est relié aux broches 12, 11, 5, 4, 3 et 2 de l'Arduino.
const int pin_E = 8;
const int pin_R = 9;

void setup()                          // La fonction setup s'execute une seule fois au démarrage du programme.
{                
    EcranLCD.begin(16, 2);            // on initialise la communication entre l'Arduino et l'afficheur (16 colonnes et 2 lignes).
    pinMode(pin_E, OUTPUT);               // La broche 8 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
    pinMode(pin_R, INPUT);                // La broche 9 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
    digitalWrite(pin_E, LOW);
}

void loop()                           // La fonction loop s'execute en boucle.     
{
   digitalWrite(pin_E, HIGH);             // met la broche 8 TRIGGER à l'état haut pendant 10 microsecondes, puis envoi une salve d'ondes ultrasonores.
   delayMicroseconds(10);             
   digitalWrite(pin_E, LOW);              // met la broche 8 TRIGGER à l'état bas, en attendant la prochaine boucle.

   unsigned long dureear = pulseIn(pin_R, HIGH);    // Le dispositif reçoit l'ECHO de la salve sur la broche 9, mesure le temps de vol Aller-Retour en microsecondes,
                                                // et enregitre la valeur dans la variable nommée ici "dureear"(=durée aller retour).

EcranLCD.clear();                               // Efface l'écran
EcranLCD.setCursor(0, 0);                       // Positionne le curseur Colonne 0, Ligne 0
EcranLCD.print("temps A-R onde");               // Ecrit "temps A-R onde"
EcranLCD.setCursor(0, 1);                       // Positionne le curseur Colonne 0, Ligne 1
EcranLCD.print(" t = ");                        // Ecrit " t = "
EcranLCD.setCursor(5, 1);                       // Positionne le curseur Colonne 5, Ligne 1
EcranLCD.print(dureear/1000.0);                 // Afiche la mesure du temps de vol de l'onde en millisecondes.
EcranLCD.setCursor(10, 1);                      // Positionne le curseur Colonne 10, Ligne 1
EcranLCD.print("ms");                           // Ecrit l'unité de la mesure "ms"
delay(1000);                                    // Petite pause de 1 seconde avant de faire une autre mesure (= une autre boucle ici).     
}

