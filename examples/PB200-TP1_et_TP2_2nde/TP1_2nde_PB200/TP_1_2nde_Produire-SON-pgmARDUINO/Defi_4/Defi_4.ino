// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°4 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, un son de 440 Hz est émis par le buzzer relié à la broche 12.

const int pin_bp_bleu = 5;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if( digitalRead(pin_bp_bleu) == HIGH )
    {
        tone(pin_buzzer,440,500);    // durée du son 500 ms
    }
}


