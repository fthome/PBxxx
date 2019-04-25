// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°2 :
// Lorsque j’appuie sur le BP JAUNE, la DEL JAUNE s’allume.
// Lorsque j’appuie sur le BP ROUGE, la DEL ROUGE s’allume.
// Lorsque j’appuie sur le BP BLEU, la DEL BLEUE s’allume.
// Lorsque j’appuie sur le BP VERT, la DEL VERTE s’allume.


void setup(){
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
}

void loop(){
  
    if(digitalRead(12)==(1))
     {
      digitalWrite(3,HIGH);
     }
      else
       {
        digitalWrite(3,LOW);
       }
       
    if(digitalRead(11)==(1))
     {
      digitalWrite(2,1);
     }
      else
       {
        digitalWrite(2,0);
       }
   
    if(digitalRead(10)==(1))
     {
      digitalWrite(5,1);
     }
      else
       {
        digitalWrite(5,0);
       }
          
    if(digitalRead(9)==(1))
     {
      digitalWrite(4,1);
     }
      else
       {
        digitalWrite(4,0);
       }

    if(digitalRead(8)==(1))
     {
      digitalWrite(6,1);
     }
      else
       {
        digitalWrite(6,0);
       }
}



