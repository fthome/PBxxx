// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°5 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 9, j’entends la sirène de la Police !

void setup(){
    pinMode(9,INPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    if( digitalRead(9)==(1) )
    {
        tone(13,435,500); 
        delay(500);
        tone(13,580,500); 
        delay(500);
    }
}



