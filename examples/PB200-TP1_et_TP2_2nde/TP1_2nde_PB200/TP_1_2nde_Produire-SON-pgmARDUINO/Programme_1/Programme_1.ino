// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// Programme n°1 :
// J’entends un son de 440 Hz après avoir téléversé le programme.

const int BUZZER = 15;

void setup(){
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    tone(BUZZER,440); 
}





