#ifndef ULTRASON // constante de preprocesseur
#define ULTRASON
#include <Arduino.h>

class Ultrason
{ // definition de la classe pour gerer notre capacitive touchh sensor

    int _pinUltrason; // attribut de classe declare en prive/

public:
    Ultrason(int pinUltrason); // definition du contructeur pour la classe touchsensor

   
    String traitementUltrason(); // definition d'une methode
};
#endif