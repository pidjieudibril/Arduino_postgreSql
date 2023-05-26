#include "TouchSensor.hpp"

// implementation des constructeur et methode
// implemetation de notre constructeur
TouchSensor::TouchSensor(int pinTouchSensor) : _pinTouchSensor(pinTouchSensor)
{

    pinMode(pinTouchSensor, INPUT);
   
}


// implementation des methodes
String TouchSensor::traitementTouch()
{
String a;
    if(digitalRead(_pinTouchSensor)==HIGH) {      //lire le toucher du capteur 
      a = "mauvais_chauffeur";   // si on touche le capteur de 
     }
   else{
      a= "rien_a_signaler";    // if Touch sensor is LOW, then turn off the led
     }
     return a;
}