#ifndef TOUCH_SENSOR // constante de preprocesseur
#define TOUCH_SENSOR
#include <Arduino.h>

class TouchSensor
{ // definition de la classe pour gerer notre capacitive touchh sensor

    int _pinTouchSensor; // attribut de classe declare en prive/

public:
    TouchSensor(int pinTouchSensor); // definition du contructeur pour la classe touchsensor

   
    String traitementTouch(); // definition d'une methode
};
#endif