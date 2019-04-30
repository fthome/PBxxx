// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°6 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 8, j’entends la sirène de la Police !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 7, j’entends la sirène de la Gendarmerie !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 6, j’entends la sirène du SAMU !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, j’entends la sirène de l’ambulance !

const int BP_JAUNE = 6;
const int BP_ROUGE = 7;
const int BP_BLEU = 8;
const int BP_VERT = 5;
const int BUZZER = 15;

void setup(){
    pinMode(BP_JAUNE,INPUT);
    pinMode(BP_ROUGE,INPUT);
    pinMode(BP_BLEU,INPUT);
    pinMode(BP_VERT,INPUT);
    pinMode(BUZZER,OUTPUT);
}

void loop(){
    if(digitalRead(BP_BLEU) == HIGH){    
        tone(BUZZER,435,500); 
        delay(500);
        tone(BUZZER,580,500);
        delay(500);
    }
    if(digitalRead(BP_ROUGE) == HIGH){   
        tone(BUZZER,435,500); 
        delay(500);
        tone(BUZZER,732,500);
        delay(500);
    }
    if(digitalRead(BP_JAUNE) == HIGH){ 
        tone(BUZZER,435,500); 
        delay(500);
        tone(BUZZER,488,500);
        delay(500);
    }
    if(digitalRead(BP_VERT) == HIGH){  
        tone(BUZZER,420,250); 
        delay(250);
        tone(BUZZER,516,250);
        delay(250);
        tone(BUZZER,420,250);
        delay(250);
        delay(1000);
    }    
}


