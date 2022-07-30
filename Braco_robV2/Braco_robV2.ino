// Biblioteca de interface dos servos
#include <Servo.h>

// Entradas analogicas dos potenciometros
int pot_base = A0;
int potpin2 = A1;
int potpin3 = A2;
int potpin4 = A3;
int potpin5 = A4;

// Numero de amostras do filtro
const int num_amostras 10;

// Criando os objetos dos servos
Servo sm_base;

// Variaveis de leitura dos pot ana
int pot_base = 0;

// Array amostras
float array_amostras [num_amostras];

void setup() {
  Serial.begin(9600);

  // identificação dos pinos para os servos
  sm_base.attach(4);

  // Setando os valores do array
  for (int i = 0; i < num_amostras; i++) {
    array_amostras[i] = 0;
  }
}



void loop() {
  // put your main code here, to run repeatedly:

}



////////////////////////////////////////////////////////////////////
int media_movel(int pino) {
  float soma = 0.0;
  
  for (int i = 0; i < num_amostras; i++) {
    soma += analogRead(pino);
    // adicionar delay contando micros
  }
  
  return soma / num_amostras;
}
