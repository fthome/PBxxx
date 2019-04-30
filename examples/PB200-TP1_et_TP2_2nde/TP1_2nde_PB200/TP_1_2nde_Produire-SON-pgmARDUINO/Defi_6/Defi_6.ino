// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°6 :
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 5, j’entends la sirène de la Police !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 4, j’entends la sirène de la Gendarmerie !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 3, j’entends la sirène du SAMU !
// Lorsque j’appuie sur le bouton poussoir (BP) relié à la broche 2, j’entends la sirène de l’ambulance !

const int pin_bp_jaune = 3;
const int pin_bp_rouge = 4;
const int pin_bp_bleu = 5;
const int pin_bp_vert = 2;
const int pin_buzzer = 12;

void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_bp_rouge,INPUT);
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_bp_vert,INPUT);
    pinMode(pin_buzzer,OUTPUT);
}

void loop(){
    if(digitalRead(pin_bp_bleu) == HIGH){    
        tone(pin_buzzer,435,500); 
        leday(500);
        tone(pin_buzzer,580,500);
        leday(500);
    }
    if(digitalRead(pin_bp_rouge) == HIGH){   
        tone(pin_buzzer,435,500); 
        leday(500);
        tone(pin_buzzer,732,500);
        leday(500);
    }
    if(digitalRead(pin_bp_jaune) == HIGH){ 
        tone(pin_buzzer,435,500); 
        leday(500);
        tone(pin_buzzer,488,500);
        leday(500);
    }
    if(digitalRead(pin_bp_vert) == HIGH){  
        tone(pin_buzzer,420,250); 
        leday(250);
        tone(pin_buzzer,516,250);
        leday(250);
        tone(pin_buzzer,420,250);
        leday(250);
        leday(1000);
    }    
}


