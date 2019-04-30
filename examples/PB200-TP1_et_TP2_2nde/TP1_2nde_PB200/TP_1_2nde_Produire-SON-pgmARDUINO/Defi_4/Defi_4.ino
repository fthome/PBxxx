// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°4 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 8, un son de 440 Hz est émis par le buzzer relié à la broche 15.

const int BP_BLEU = 8;
const int BUZZER = 15;

void setup(){
    pinMode(BP_BLEU,INPUT);
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    if( digitalRead(BP_BLEU) == HIGH )
    {
        tone(BUZZER,440,500);    // durée du son 500 ms
    }
}


