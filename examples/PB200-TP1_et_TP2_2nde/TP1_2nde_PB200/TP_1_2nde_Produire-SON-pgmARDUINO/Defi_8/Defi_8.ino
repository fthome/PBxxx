// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°8 :
// Lorsque j’appuie sur le bouton poussoir relié à la broche 8, j’entends la sirène de la Police et je vois la
// DEL bleue clignoter au rythme du changement de fréquence de la sirène.

const int DEL_BLEU = 11;
const int BP_BLEU = 8;
const int BUZZER = 15;

void setup(){
    pinMode(BP_BLEU,INPUT);
    pinMode(DEL_BLEU,OUTPUT);
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    if(digitalRead(BP_BLEU) == HIGH){
        digitalWrite(DEL_BLEU,HIGH);       
        tone(BUZZER,435,500);
        delay(500);
        digitalWrite(DEL_BLEU,LOW);
        tone(BUZZER,580,500);
        delay(500);
    }
}



