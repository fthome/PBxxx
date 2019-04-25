// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°4 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 9, un son de 440 Hz est émis par le buzzer relié à la broche 13.

void setup(){
    pinMode(9,INPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    if( digitalRead(9)==(1) )
    {
        tone(13,440,500);    // durée du son 500 ms
    }
}


