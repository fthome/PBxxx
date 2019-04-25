// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°7 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 9, je joue une mélodie bien connue.

void setup(){
    pinMode(9,INPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    if(digitalRead(9)==(1)){
        tone(13,262,500);
        delay(500);
        tone(13,262,500);
        delay(500);
        tone(13,294,500);
        delay(500);
        tone(13,262,500);
        delay(500);
        tone(13,349,500);
        delay(500);
        tone(13,330,500);
        delay(500);
        tone(13,262,500);
        delay(500);
        tone(13,262,500);
        delay(500);
        tone(13,294,500);
        delay(500);
        tone(13,262,500);
        delay(500);
        tone(13,392,500);
        delay(500);
        tone(13,349,500);
        delay(2000);
    }
}



