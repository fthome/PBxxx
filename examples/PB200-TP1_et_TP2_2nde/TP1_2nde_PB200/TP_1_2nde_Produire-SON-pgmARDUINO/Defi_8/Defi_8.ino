// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°8 :
// Lorsque j’appuie sur le bouton poussoir relié à la broche 10, j’entends la sirène de la Police et je vois la
// DEL bleue clignoter au rythme du changement de fréquence de la sirène.

void setup(){
    pinMode(10,INPUT);
    pinMode(13,OUTPUT);
    pinMode(5,OUTPUT);
}

void loop(){
    if(digitalRead(10)==(1)){
        digitalWrite(5,1);       
        tone(13,435,500);
        delay(500);
        digitalWrite(5,0);
        tone(13,580,500);
        delay(500);
    }
}



