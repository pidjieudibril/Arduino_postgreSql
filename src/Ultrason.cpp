#include "Ultrason.hpp"
#define  MAX_RANG      (520) // la valeur de mesure maximale du module est de 520 cm (un peu plus longue que la plage maximale effective)
#define  ADC_SOLUTION      (1023.0)// La précision ADC d'Arduino UNO est de 10 bits
// implementation des constructeur et methode
// implemetation de notre constructeur
Ultrason::Ultrason(int pinUltrason) : _pinUltrason(pinUltrason)
{

    pinMode(pinUltrason, INPUT);
   
}


// implementation des methodes
String Ultrason::traitementUltrason()
{
String b ;
float dist_t, sensity_t;
  // read the value from the sensor:
 sensity_t = analogRead(_pinUltrason);
 
 dist_t = sensity_t * MAX_RANG  / ADC_SOLUTION;
 //Serial.print(dist_t,0);
 //Serial.print("cm");
// Serial.print("\t");

 if (dist_t <= 30)
 {
  b = "cogner_voiture";
 }
 else if (dist_t  >= 30 && dist_t <= 250)
 {
   b = "tantative_de_cogner";

 }
 else
 {
   b = "na_jamais_cogner";
 }
 
 
return b;
 


}