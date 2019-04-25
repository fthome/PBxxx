// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°1 :
// Lorsque j’appuie sur le bouton poussoir (BP) jaune relié à la broche 12 de la carte ArduinoTM , la DEL jaune reliée à la boche 3 s’allume. 
// Lorsque je n’appuie plus sur le BP, la DEL s’éteint.

void setup(){
    pinMode(12,INPUT);
    pinMode(3,OUTPUT);
}

void loop(){
    if(digitalRead(12)==HIGH)
     {
      digitalWrite(3,HIGH);
     }
      else
       {
        digitalWrite(3,LOW);
       }
}





