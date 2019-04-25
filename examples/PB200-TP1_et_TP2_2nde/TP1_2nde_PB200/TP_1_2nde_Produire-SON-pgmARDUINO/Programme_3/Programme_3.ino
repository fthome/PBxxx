// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// Programme n°3 :
// J’entends 3 fois la sirène des pompiers « PIN-PON »

void setup(){
    pinMode(13,OUTPUT);
    for(int i=0 ; i<3 ; ++i )
    {   tone(13,435);
        delay(500);
        tone(13,488,500);
        delay(500);  
    }  
}

void loop(){
}





