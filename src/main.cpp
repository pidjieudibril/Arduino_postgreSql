#include <Arduino.h>


// la bibliothèque Wire permet de communiquer avec les périphériques I2C
#include <Wire.h>

// definition des constante de preprocesseur:
#define trigPin 9           // defini la broche Trig
#define echoPin 8           //definir la broche echo
#define LED_JAUNE 1         //defini la LED jaune 
#define LED_ROUGE 7         //defini la Led rouge  

//déclaration des  variables:
long duration;
int distance;


// Instruction d'initialisation de la carte Arduino
//--------------- FONCTION SETUP = Code d'initialisation -----------------------------
// La fonction setup() est exécutée en premier et 1 seule fois, au démarrage du programme
void setup()
{ 
    // Définir les entrées et les sorties:
    pinMode(trigPin, OUTPUT);            // trigPin en mode sortie
    pinMode(echoPin, INPUT);             // echoPin en mode entreé 
    // Commencez la communication série à un débit de 9600 bauds:
    Serial.begin(9600); 
    
}

void loop()
{
    digitalWrite(trigPin, LOW); 
    /*Met un niveau logique LOW (BAS en anglais) sur une broche numérique 9. 
    Si la broche a été configurée en SORTIE avec l'instruction pinMode(), sa tension est mise à la valeur correspondante : 5V  pour le niveau HAUT, 0V (masse) pour le niveau BAS.*/ 

    delayMicroseconds(2);
    //La fonction delayMicroseconds() accepte un unique paramètre obligatoire qui correspond à la durée en microsecondes de la temporisation. Cette fonction accepte uniquement des nombres entiers. 

    digitalWrite(trigPin, HIGH);
    /*Met un niveau logique HIGH (HAUT en anglais) sur une broche numérique 9. 
    Si la broche a été configurée en SORTIE avec l'instruction pinMode(), sa tension est mise à la valeur correspondante : 5V  pour le niveau HAUT, 0V (masse) pour le niveau BAS.*/ 

    delayMicroseconds(10);
    //La fonction delay() permet de mettre en pause le programme pendant un certain nombre de millisecondes. C'est une fonction bloquante. 
    //La fonction delayMicroseconds() accepte un unique paramètre obligatoire qui correspond à la durée en microsecondes de la temporisation. Cette fonction accepte uniquement des nombres entiers. 
    
    digitalWrite(trigPin, LOW);
    /*Met un niveau logique LOW (BAS en anglais) sur une broche numérique 9. 
    Si la broche a été configurée en SORTIE avec l'instruction pinMode(), sa tension est mise à la valeur correspondante : 5V  pour le niveau HAUT, 0V (masse) pour le niveau BAS.*/  
    // Lire le echoPin, pulseIn () renvoie la durée (longueur de l'impulsion) en microsecondes:
    duration = pulseIn(echoPin, HIGH);
    // Calculez la distance:
    distance = duration * 0.034 / 2;
    // Affiche la distance sur le moniteur série (Ctrl + Maj + M):
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
   
    //utiliser les led pour signaler l'obstacle 
    //affiche la led rouge 
    if (distance < 35) 
       {
        digitalWrite(LED_JAUNE, LOW);
        digitalWrite(LED_ROUGE, HIGH);
       }
    else if (distance > 35)
      {
        digitalWrite(LED_JAUNE, HIGH);
        digitalWrite(LED_ROUGE, LOW);
       }

    // affiche la led jaune   
    
    // afficher la distance a l'ecran 
   /*
    Serial.print("ATTENTION!!! "); // affiche la chaîne texte - message de test (Ici Temps:)
    
    Serial.print("OBSTACLE A"); // affiche la chaîne texte - message de test (Ici un espace)
    
   Serial.print(distance);// affiche le calcul de la distance en cm  entre l'émétteur et l'objet
   Serial.print(" cm");*/
      //lcd.write(12); // affiche le caractère µ pour micro
    //lcd.write(11); // affiche le caractère s pour seconde
    delay(2000); //La fonction delay() permet de mettre en pause le programme pendant 2 seconde. C'est une fonction bloquante.   
}

