
#include <pbduino.h>
Pb100 pb100;

float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void setup(){
    pb100.init();
    pinMode(4,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(2,OUTPUT);
}

void loop(){

    if( (getDistance(8,9)) < (20) ){
        digitalWrite(4,1);
        digitalWrite(3,0);
        tone(2,600,125); 
        delay(125);


          pb100.lcd->setCursor(0, 0);
          pb100.lcd->print(" Radar de recul");
          pb100.lcd->setCursor(0, 1);
          pb100.lcd->print("   d = " + String(getDistance(8,9),0) + " cm"); 
        
    }else{
        if((getDistance(8,9)) <= (40)){
            digitalWrite(4,1);
            digitalWrite(3,0);
            tone(2,600,125); 
          delay(300);


              pb100.lcd->setCursor(0, 0);
              pb100.lcd->print(" Radar de recul");
              pb100.lcd->setCursor(0, 1);
              pb100.lcd->print("   d = " + String(getDistance(8,9),0) + " cm"); 

      }else{
        if((getDistance(8,9)) > (40)){
            digitalWrite(4,0);
            digitalWrite(3,1);
                

              pb100.lcd->setCursor(0, 0);
              pb100.lcd->print(" Radar de recul");
              pb100.lcd->setCursor(0, 1);
              pb100.lcd->print("   d = " + String(getDistance(8,9),0) + " cm");  }
               
delay(1000);
  } } }



