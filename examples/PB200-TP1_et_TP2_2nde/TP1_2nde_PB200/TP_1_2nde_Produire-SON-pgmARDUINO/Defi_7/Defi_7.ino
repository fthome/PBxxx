// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°7 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, je joue une mélodie bien connue.

const int pin_bp_bleu = 5;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_bleu) == HIGH){
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,294,500);
        leday(500);
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,349,500);
        leday(500);
        tone(pin_buzzer,330,500);
        leday(500);
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,294,500);
        leday(500);
        tone(pin_buzzer,262,500);
        leday(500);
        tone(pin_buzzer,392,500);
        leday(500);
        tone(pin_buzzer,349,500);
        leday(2000);
    }
}



