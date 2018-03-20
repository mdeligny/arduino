#include <Servo.h>
#include <Firmata.h>

// commun
int attentePosition=500;

// Bouton power
int pinServoPower=8; // pin pour le servo-moteur
int pinInputPower=5; // signal pour déclancher l'action
int positionInitialePower=160; // angle de départ du servo
int positionActionPower=50;
Servo servoPower;

// Bouton bluetooth
int pinServoBluetooth=9; // pin pour le servo-moteur
int pinInputBluetooth=6; // signal pour déclancher l'action
int positionInitialeBluetooth=160; // angle de départ du servo
int positionActionBluetooth=60;
Servo servoBluetooth;

// Bouton Aux
int pinServoAux=10; // pin pour le servo-moteur
int pinInputAux=7; // signal pour déclancher l'action
int positionInitialeAux=80; // angle de départ du servo
int positionActionAux=170;
Servo servoAux;

void setup() {
  //Serial.begin(9600);
  pinMode(pinInputPower,INPUT_PULLUP); // bouton en lecture
  servoPower.attach(pinServoPower); // on relie l'objet au pin de commande
  servoPower.write(positionInitialePower); // on dit à l'objet de mettre le servo à l'initiale
}

void loop() { 
  boolean etatBoutonPower = digitalRead(pinInputPower);
  if(!etatBoutonPower) {
      actionBouton(servoPower, positionActionPower, positionInitialePower);
  }

  boolean etatBoutonBluetooth = digitalRead(pinInputBluetooth);
  if(!etatBoutonBluetooth) {
      actionBouton(servoBluetooth, positionActionBluetooth, positionInitialeBluetooth);
  }

  boolean etatBoutonAux = digitalRead(pinInputAux);
  if(!etatBoutonAux) {
      actionBouton(servoAux, positionActionAux, positionInitialeAux);
  }
  delay(200);
}

void actionBouton(Servo servo,int positionAction, int positionRepos) {
  servo.write(positionAction); // on dit à l'objet de mettre le servo à la position d'action
  delay(attentePosition);
  servo.write(positionRepos); // retour en position initiale
}

