// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°7 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 8, je joue une mélodie bien connue.

const int BP_BLEU = 8;
const int BUZZER = 15;

void setup(){
    pinMode(BP_BLEU,INPUT);
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    if(digitalRead(BP_BLEU) == HIGH){
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,294,500);
        delay(500);
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,349,500);
        delay(500);
        tone(BUZZER,330,500);
        delay(500);
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,294,500);
        delay(500);
        tone(BUZZER,262,500);
        delay(500);
        tone(BUZZER,392,500);
        delay(500);
        tone(BUZZER,349,500);
        delay(2000);
    }
}



