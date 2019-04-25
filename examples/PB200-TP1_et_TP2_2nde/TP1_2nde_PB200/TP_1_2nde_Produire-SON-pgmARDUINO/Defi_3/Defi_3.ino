// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°3 :
// Réalise un chenillard

void setup(){
    pinMode(9,INPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
}

void loop(){
    if(digitalRead(9)==(1)){
        digitalWrite(2,1);
        delay(100);
        digitalWrite(2,0);
        digitalWrite(3,1);
        delay(100);
        digitalWrite(3,0);
        digitalWrite(4,1);
        delay(100);
        digitalWrite(4,0);
        digitalWrite(5,1);
        delay(100);
        digitalWrite(5,0);
        digitalWrite(4,1);
        delay(100);
        digitalWrite(4,0);
        digitalWrite(3,1);
        delay(100);
        digitalWrite(3,0);
        digitalWrite(2,1);
        delay(100);
        digitalWrite(2,0);
    }
}






