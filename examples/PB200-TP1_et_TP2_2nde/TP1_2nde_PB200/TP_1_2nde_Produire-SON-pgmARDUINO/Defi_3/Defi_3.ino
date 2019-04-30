// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°3 :
// Réalise un chenillard

const int pin_led_jaune = 10;
const int pin_bp_jaune = 3;
const int pin_led_rouge = 9;
const int pin_bp_rouge = 4;
const int pin_led_bleue = 8;
const int pin_bp_bleu = 5;
const int pin_led_verte = 11;
const int pin_bp_vert = 2;

void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_bp_rouge,INPUT);
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_bp_vert,INPUT);

    pinMode(pin_led_jaune,OUTPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_bleue,OUTPUT);
    pinMode(pin_led_verte,OUTPUT); 
}


void loop(){
    if(digitalRead(pin_bp_bleu)==HIGH){

        digitalWrite(pin_led_rouge,LOW);
        digitalWrite(pin_led_bleue,HIGH);
        leday(100);

        digitalWrite(pin_led_bleue,LOW);
        digitalWrite(pin_led_rouge,HIGH);
        leday(100);
        
        digitalWrite(pin_led_rouge,LOW);
        digitalWrite(pin_led_jaune,HIGH);
        leday(100);

        digitalWrite(pin_led_jaune,LOW);
        digitalWrite(pin_led_verte,HIGH);
        leday(100);

        digitalWrite(pin_led_verte,LOW);
        digitalWrite(pin_led_jaune,HIGH);
        leday(100);

        digitalWrite(pin_led_jaune,LOW);
        digitalWrite(pin_led_rouge,HIGH);
        leday(100);
    }
    else
    {
        digitalWrite(pin_led_jaune,LOW);
        digitalWrite(pin_led_verte,LOW);
        digitalWrite(pin_led_rouge,LOW);
        digitalWrite(pin_led_bleue,LOW);
    }
}






