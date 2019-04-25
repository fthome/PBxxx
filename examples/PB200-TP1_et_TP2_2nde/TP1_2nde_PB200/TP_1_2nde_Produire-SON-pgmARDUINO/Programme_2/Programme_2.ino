// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// Programme n°2 :
// J’entends la sirène des pompiers indéfiniment !

void setup(){
    pinMode(13,OUTPUT);
}

void loop(){
    tone(13,435); 
    delay(500);
    tone(13,488);
    delay(500);
}


