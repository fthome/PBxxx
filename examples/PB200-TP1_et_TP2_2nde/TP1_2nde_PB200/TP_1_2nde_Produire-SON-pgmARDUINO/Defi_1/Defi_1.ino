// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°1 :
// Lorsque j’appuie sur le bouton poussoir (BP) jaune relié à la broche 3 de la carte ArduinoTM , la led jaune reliée à la boche 10 s’allume. 
// Lorsque je n’appuie plus sur le BP, la led s’éteint.

const int pin_led_jaune = 10;
const int pin_bp_jaune = 3;


void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_led_jaune,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_jaune)==HIGH)
    {
        digitalWrite(pin_led_jaune,HIGH);
    }
    else
    {
        digitalWrite(pin_led_jaune,LOW);
    }
}





