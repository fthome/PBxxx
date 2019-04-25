/*
Une librairie pour piloter les modules didactiques PIERRON PB100, PB200, PB300 et suivants.
Il s'agit de modules pour Arduino nano débiés à l'éducation.

Développés et commercialisés par www.pierron.fr à partir d'idées originales de Patrice Buffet.

Auteur : fthome
*/


#include "pbduino.h"

/*
********************   Classe Pbduino   ********************
*/


/*
CONSTRUCTEUR
*/
Pbduino::Pbduino():  _pin_led_verte(0), _pin_led_rouge(0), _pin_led_jaune(0), _pin_led_bleu(0), _pin_buzzer(0), _tone_frequency(440){
  //Serial.println("Creation Pbduino");
}

Pbduino::~Pbduino(){

}


void Pbduino::init(){
  //Initialisation des leds
  if (_pin_led_verte>0){
    pinMode(_pin_led_verte, OUTPUT);
  }
  if (_pin_led_rouge>0){
    pinMode(_pin_led_rouge, OUTPUT);
  }
  if (_pin_led_jaune>0){
    pinMode(_pin_led_jaune, OUTPUT);
  }
  if (_pin_led_bleu>0){
    pinMode(_pin_led_bleu, OUTPUT);
  }
  //Initialisation du buzzer
  if (_pin_buzzer>0){
    pinMode(_pin_buzzer, OUTPUT);
  }
}


/////////////////
// LES LEDS    //
/////////////////

// Definit l'etat de la led verte LOW | HIGH
void Pbduino::set_led_verte(uint8_t state) const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, state);
  }else{
    Serial.print("Erreur : _pin_led_verte non assignée.");
  }
}
// Allume la led verte
void Pbduino::allume_led_verte() const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, HIGH);
  }else{
    Serial.print("Erreur : _pin_led_verte non assignée.");
  }
}
// Eteint la led verte
void Pbduino::eteint_led_verte() const{
  if (_pin_led_verte >0){
    digitalWrite(_pin_led_verte, LOW);
  }else{
    Serial.print("Erreur : _pin_led_verte non assignée.");
  }
}
// Definit l'etat de la led rouge LOW | HIGH
void Pbduino::set_led_rouge(uint8_t state) const{
  if (_pin_led_rouge > 0){
    digitalWrite(_pin_led_rouge, state);
  } else{
    Serial.print("Erreur : _pin_led_rouge non assignée.");
  }
}
// Allume la led rouge
void Pbduino::allume_led_rouge() const{
  if (_pin_led_rouge >0){
    digitalWrite(_pin_led_rouge, HIGH);
  } else{
    Serial.print("Erreur : _pin_led_rouge non assignée.");
  }
}
// Eteint la led rouge
void Pbduino::eteint_led_rouge() const{
  if (_pin_led_rouge >0){
    digitalWrite(_pin_led_rouge, LOW);
  } else{
    Serial.print("Erreur : _pin_led_rouge non assignée.");
  }
}
// Definit l'etat de la led jaune LOW | HIGH
void Pbduino::set_led_jaune(uint8_t state) const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, state);
  } else{
    Serial.print("Erreur : _pin_led_jaune non assignée.");
  }
}
// Allume la led jaune
void Pbduino::allume_led_jaune() const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, HIGH);
  }else{
    Serial.print("Erreur : _pin_led_jaune non assignée.");
  }
}
// Eteint la led jaune
void Pbduino::eteint_led_jaune() const{
  if (_pin_led_jaune >0){
    digitalWrite(_pin_led_jaune, LOW);
  }else{
    Serial.print("Erreur : _pin_led_jaune non assignée.");
  }
}
// Definit l'etat de la led bleu LOW | HIGH
void Pbduino::set_led_bleu(uint8_t state) const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, state);
  }else{
    Serial.print("Erreur : _pin_led_bleu non assignée.");
  }
}
// Allume la led bleu
void Pbduino::allume_led_bleu() const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, HIGH);
  }else{
    Serial.print("Erreur : _pin_led_bleu non assignée.");
  }
}
// Eteint la led bleu
void Pbduino::eteint_led_bleu() const{
  if (_pin_led_bleu >0){
    digitalWrite(_pin_led_bleu, LOW);
  }else{
    Serial.print("Erreur : _pin_led_bleu non assignée.");
  }
}

/////////////////
// LE BUZZER   //
/////////////////

// Joue un son selon une frequence
void Pbduino::buzzer(unsigned int frequency){
  if (_pin_buzzer > 0){
    _tone_frequency = frequency;
    tone(_pin_buzzer, frequency);
  }else{
    Serial.print("Erreur : _pin_buzzer non assignée.");
  }
}
//  Joue un son selon une frequence pendant une durée
void Pbduino::buzzer(unsigned int frequency, unsigned long duration){
  if (_pin_buzzer > 0){
    _tone_frequency = frequency;
    tone(_pin_buzzer, frequency, duration);
  }else{
    Serial.print("Erreur : _pin_buzzer non assignée.");
  }
}
// Joue le meme son que precedement
void Pbduino::buzzer() const{
  if (_pin_buzzer>0){
    if (_tone_frequency>0){
      tone(_pin_buzzer, _tone_frequency);
    }else{
      Serial.print("Erreur : _tone_frequency =0");
    }
  }else{
    Serial.print("Erreur : _pin_buzzer non assignée.");
  }
}
// Un peu de silence!
void Pbduino::noBuzzer()const{
  if (_pin_buzzer > 0){
    noTone(_pin_buzzer);
  //TODO, si play, stopper
  }else{
    Serial.print("Erreur : _pin_buzzer non assignée.");
  }
}
/*
// Jour une liste de notes, indéfiniment
void Pb100::play(int n, ...) const{
  va_list va;
  va_start (va, n);
  va_end(va);
  //TODO : un timer qui change les frequences en 'tache de fond'
}
*/

/*
********************   Classe Pbduino_lcd   ********************
Une sous classe de Pbduino pour les modules avec afficheur LCD
*/

Pbduino_lcd::Pbduino_lcd(): Pbduino(), _lcd_cols(16), _lcd_rows(2){
}
Pbduino_lcd::~Pbduino_lcd(){
  delete lcd;
}
void Pbduino_lcd::init(){
  Pbduino::init();
  lcd = new LiquidCrystal_I2C(0x20,_lcd_cols,_lcd_rows);
  lcd->init();
  lcd->backlight();
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("PIERRON - " + _name);
  lcd->setCursor(0,1);
}

//LiquidCrystal_I2C* Pbduino_lcd::lcd(){
//  return _lcd;
//}

void Pbduino_lcd::affiche(String txt){
  affiche(txt, 0,0);
}
void Pbduino_lcd::affiche(String txt, int row){
  affiche(txt,row,0);
}
void Pbduino_lcd::affiche(String txt, int row, int col){
  while (txt.length()<_lcd_cols){
    txt += " ";
  }
  lcd->setCursor(col, row);
  lcd->print(txt);
}
void Pbduino_lcd::affiche(int val){
  affiche(String(val));
}
void Pbduino_lcd::affiche(int val, int row){
  affiche(String(val), row);
}
void Pbduino_lcd::affiche(int val, int row, int col){
  affiche(String(val), row, col);
}
void Pbduino_lcd::affiche(float val){
  affiche(String(val));
}
void Pbduino_lcd::affiche(float val, int row){
  affiche(String(val), row);
}
void Pbduino_lcd::affiche(float val, int row, int col){
  affiche(String(val), row, col);
}

void Pbduino_lcd::allumeEcran(){
  lcd->backlight();
}
void Pbduino_lcd::eteintEcran(){
  lcd->noBacklight();
}
void Pbduino_lcd::effaceEcran(){
  lcd->clear();
}

/*
********************   Classe Pb100   ********************
Une sous classe pour la maquette Pb100
elle contient :
  - une led verte
  - une led rouge
  - un buzzer
  - un module HC-SR04 pour mesurer une distance
  _ un afficheur LCD 16x2
*/

Pb100::Pb100(): Pbduino_lcd(), _pin_trigger(8), _pin_echo(9){
  _pin_led_verte = 3;
  _pin_led_rouge = 4;
  _pin_buzzer=2;
  _name = "PB100";
}

void Pb100::init(){
  Pbduino_lcd::init();
  pinMode(_pin_trigger, OUTPUT);
  digitalWrite(_pin_trigger, LOW);
  pinMode(_pin_echo, INPUT);
}

// Mesure la distance ou 0 si echec
float Pb100::distance() const{
  //Déclenche le trigger
  digitalWrite(_pin_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_pin_trigger, LOW);
  //Attend le retour du signal et renvoie la distance calculée
  return pulseIn(_pin_echo, HIGH, TIMEOUT) / 2.0 * VITESSE_DU_SON;
}


/*
********************   Classe Pb200   ********************
    Une sous classe pour la maquette Pb200
    elle contient :
      - une led verte
      - une led rouge
      - une led jaune
      - une led bleu
      - un bouton vert
      - un bouton bleu
      - un bouton jaune
      - un bouton rouge
      - un buzzer
*/

Pb200::Pb200(){
  _pin_led_verte = 4;
  _pin_led_rouge = 2;
  _pin_led_bleu = 5;
  _pin_led_jaune = 3;
  _pin_buzzer = 13;
  _pin_bt_bleu = 10;
  _pin_bt_vert = 9;
  _pin_bt_jaune = 12;
  _pin_bt_rouge = 11;
  _name = "PB200";
}

//void Pb200::init(){} Pas necessaire de surchager!

int Pb200::get_bouton_vert() const{
  return digitalRead(_pin_bt_vert);
}
int Pb200::get_bouton_rouge() const{
  return digitalRead(_pin_bt_rouge);
}
int Pb200::get_bouton_bleu() const{
  return digitalRead(_pin_bt_bleu);
}
int Pb200::get_bouton_jaune() const{
  return digitalRead(_pin_bt_jaune);
}
int Pb200::get_bouton(uint8_t buton_no) const{
  return digitalRead(_pin_bt_vert + buton_no); //Bof!
}

/*
********************   Classe Pb300   ********************

     Une sous classe pour la maquette Pb300
    elle contient :
      - une led verte
      - une led rouge
      - un buzzer
      - deux leds blanches non pilotées
      - deux photoresistances branchées en diviseur de tension sur deux entrées analogiques
*/

Pb300::Pb300():Pbduino_lcd(), _pin_photo_1(A0), _pin_photo_2(A1){
  _pin_led_verte = 2;
  _pin_led_rouge = 4;
  _pin_buzzer = 6;
  _name = "PB300";
  _lcd_cols = 20;
  _lcd_rows = 4;
}

void Pb300::init(){
  Pbduino_lcd::init();
  pinMode(_pin_photo_1, INPUT);
  pinMode(_pin_photo_2, INPUT);
}

int Pb300::get_photo1() const{
  return analogRead(_pin_photo_1);
}
int Pb300::get_photo2() const{
  return analogRead(_pin_photo_2);
}
