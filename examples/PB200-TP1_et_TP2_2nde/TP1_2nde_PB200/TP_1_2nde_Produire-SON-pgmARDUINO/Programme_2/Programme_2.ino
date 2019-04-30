// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// Programme n°2 :
// J’entends la sirène des pompiers indéfiniment !

const int pin_buzzer = 12;

void setup(){
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    tone(pin_buzzer,435); 
    delay(500);
    tone(pin_buzzer,488);
    delay(500);
}


