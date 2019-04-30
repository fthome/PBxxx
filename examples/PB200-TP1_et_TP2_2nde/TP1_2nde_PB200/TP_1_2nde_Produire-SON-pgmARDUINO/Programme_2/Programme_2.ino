// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// Programme n°2 :
// J’entends la sirène des pompiers indéfiniment !

const int BUZZER = 15;

void setup(){
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    tone(BUZZER,435); 
    delay(500);
    tone(BUZZER,488);
    delay(500);
}


