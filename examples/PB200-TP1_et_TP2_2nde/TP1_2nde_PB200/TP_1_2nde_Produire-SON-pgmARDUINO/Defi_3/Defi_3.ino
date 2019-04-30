// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°3 :
// Réalise un chenillard

const int DEL_JAUNE = 13;
const int BP_JAUNE = 6;
const int DEL_ROUGE = 12;
const int BP_ROUGE = 7;
const int DEL_BLEU = 11;
const int BP_BLEU = 8;
const int DEL_VERT = 14;
const int BP_VERT = 5;

void setup(){
    pinMode(BP_JAUNE,INPUT);
    pinMode(BP_ROUGE,INPUT);
    pinMode(BP_BLEU,INPUT);
    pinMode(BP_VERT,INPUT);

    pinMode(DEL_JAUNE,OUTPUT);
    pinMode(DEL_ROUGE,OUTPUT);
    pinMode(DEL_BLEU,OUTPUT);
    pinMode(DEL_VERT,OUTPUT);
}

void loop(){


    if(digitalRead(BP_BLEU)==HIGH){

        digitalWrite(DEL_ROUGE,LOW);
        digitalWrite(DEL_BLEU,HIGH);
        delay(100);

        digitalWrite(DEL_BLEU,LOW);
        digitalWrite(DEL_ROUGE,HIGH);
        delay(100);
        
        digitalWrite(DEL_ROUGE,LOW);
        digitalWrite(DEL_JAUNE,HIGH);
        delay(100);

        digitalWrite(DEL_JAUNE,LOW);
        digitalWrite(DEL_VERT,HIGH);
        delay(100);

        digitalWrite(DEL_VERT,LOW);
        digitalWrite(DEL_JAUNE,HIGH);
        delay(100);

        digitalWrite(DEL_JAUNE,LOW);
        digitalWrite(DEL_ROUGE,HIGH);
        delay(100);
    }
    else
    {
        digitalWrite(DEL_JAUNE,LOW);
        digitalWrite(DEL_VERT,LOW);
        digitalWrite(DEL_ROUGE,LOW);
        digitalWrite(DEL_BLEU,LOW);
    }
        
  /*
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
    */
}






