// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°6 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 9, j’entends la sirène de la Police !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 10, j’entends la sirène de la Gendarmerie !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 11, j’entends la sirène du SAMU !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 12, j’entends la sirène de l’ambulance !

void setup(){
    pinMode(9,INPUT);
    pinMode(10,INPUT);
    pinMode(11,INPUT);
    pinMode(12,INPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    if(digitalRead(9)==(1)){
        tone(13,435,500); 
        delay(500);
        tone(13,580,500);
        delay(500);
    }
    if(digitalRead(10)==(1)){
        tone(13,435,500); 
        delay(500);
        tone(13,732,500);
        delay(500);
    }
    if(digitalRead(11)==(1)){
        tone(13,435,500); 
        delay(500);
        tone(13,488,500);
        delay(500);
    }
    if(digitalRead(12)==(1)){
        tone(13,420,250); 
        delay(250);
        tone(13,516,250);
        delay(250);
        tone(13,420,250);
        delay(250);
        delay(1000);
    }    
}


