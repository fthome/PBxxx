// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°2 :
// Lorsque j’appuie sur le BP JAUNE, la DEL JAUNE s’allume.
// Lorsque j’appuie sur le BP ROUGE, la DEL ROUGE s’allume.
// Lorsque j’appuie sur le BP BLEU, la DEL BLEUE s’allume.
// Lorsque j’appuie sur le BP VERT, la DEL VERTE s’allume.
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
    
  /*
    pinMode(12,INPUT);
    pinMode(11,INPUT);
    pinMode(10,INPUT);    
    pinMode(9,INPUT);
    pinMode(8,INPUT);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(6,OUTPUT);
    */
}

void loop(){
  
    if(digitalRead(BP_JAUNE)==HIGH)
     {
      digitalWrite(DEL_JAUNE,HIGH);
     }
      else
       {
        digitalWrite(DEL_JAUNE,LOW);
       }
       
    if(digitalRead(BP_ROUGE)==HIGH)
     {
      digitalWrite(DEL_ROUGE,HIGH);
     }
      else
       {
        digitalWrite(DEL_ROUGE,LOW);
       }
   
    if(digitalRead(BP_BLEU)==HIGH)
     {
      digitalWrite(DEL_BLEU,HIGH);
     }
      else
       {
        digitalWrite(DEL_BLEU,LOW);
       }
          
    if(digitalRead(BP_VERT)==HIGH)
     {
      digitalWrite(DEL_VERT,HIGH);
     }
      else
       {
        digitalWrite(DEL_VERT,LOW);
       }

   
}



