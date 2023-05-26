
/*
  Titre      : gestion des prime en fonction de la conduite
  Auteur     : Pidjieu dibril
  Date       : 26/05/2023
  Description: ce programme consiste a enregistrer les donnees du capteur dans une base de donnee
  Version    : 0.0.1
*/

// inclusion des bibliotheque
#include <Arduino.h>
#include "TouchSensor.hpp"
#include "Ultrason.hpp"

// definition des constante pour les differnts pins
#define touchPin 2
#define ultrasonPin A0

// creation d'UN objets pour le capacitive touch sensor
TouchSensor touch(touchPin);
// creation d'UN objet pour le capteur ultrason
Ultrason ultrason(ultrasonPin);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{

  // afficharge des information dans le moniteur serie
  String toucher = touch.traitementTouch(); // Renvoie  touche
  String ultra = ultrason.traitementUltrason();
  Serial.print(toucher);
  Serial.print("\t");
  Serial.println(ultra);
  delay(2000);
}
