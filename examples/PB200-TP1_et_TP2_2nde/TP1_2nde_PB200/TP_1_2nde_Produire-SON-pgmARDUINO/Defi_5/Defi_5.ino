// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°5 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, j’entends la sirène de la Police !

const int pin_bp_bleu = 5;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if( digitalRead(pin_bp_bleu) == HIGH )
    {
        tone(pin_buzzer,435,500); 
        leday(500);
        tone(pin_buzzer,580,500); 
        leday(500);
    }
}



