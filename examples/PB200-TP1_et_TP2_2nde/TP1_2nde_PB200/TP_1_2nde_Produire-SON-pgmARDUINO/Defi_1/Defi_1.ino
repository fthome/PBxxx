// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°1 :
// Lorsque j’appuie sur le bouton poussoir (BP) jaune relié à la broche 6 de la carte ArduinoTM , la DEL jaune reliée à la boche 13 s’allume. 
// Lorsque je n’appuie plus sur le BP, la DEL s’éteint.

const int DEL_JAUNE = 13;
const int BP_JAUNE = 6;


void setup(){
    pinMode(BP_JAUNE,INPUT);
    pinMode(DEL_JAUNE,OUTPUT);
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
}





