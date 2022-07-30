// Biblioteca de interface dos servos
#include <Servo.h>

// Entradas analogicas dos potenciometros
int potpin = A0;
int potpin2 = A1;
int potpin3 = A2;
int potpin4 = A3;
int potpin5 = A4;

// Controle quantidade de amostras
int cont_npontos = A5;

// servos 
int npontos_val = 0;
int npontos_valal = 0;

#define n_pontos 10


Servo myservos;
Servo myservos2;
Servo myservo3;
Servo myservos4;
Servo myservos5;
Servo myservo6;
Servo myservo7;


int analol = 0, val = 0;

int analo2 = 0, val2 = 0;

int analo3 = 0, val3 = 0;

int analo4 = 0, val4 = 0;

int analo5 = 0, val5 = 0;


float amostras [n_pontos];
float amostras2 [n_pontos];
float amostras3 [n_pontos];
float amostras4 [n_pontos];
float amostras5 [n_pontos];


int media_movel();
int media_movel2();
int media_movel3();
int media_movel4();
int media_movel5();



void setup() {
  
  myservos.attach(2);
  myservos2.attach(3);

  myservo3.attach(4);

  myservos4.attach(5);
  myservos5.attach(6);

  myservo6.attach(8);

  myservo7.attach(9);
  
  Serial.begin(9600);

  for (int i = 0; i < n_pontos; i++) {
    amostras[i] = 0;
    amostras2[i] = 0;
    amostras3[i] = 0;
    amostras4[i] = 0;
    amostras5[i] = 0;
  }
}


int media_movel(float ) {
  
  for (int i = n_pontos - 1; i > 0; i--) {
    amostras[i] = amostras[i - 1];
  }
  
  amostras[0] = analogRead(potpin);

  float soma = 0.0;

  for (int i = 0; i < n_pontos; i++) {
    soma += amostras[i];
  }
  return soma / n_pontos;
}
///////////////////////
int media_movel2() {
  for (int i = n_pontos - 1; i > 0; i--) {
    amostras2[i] = amostras2[i - 1];
  }
  amostras2[0] = analogRead(potpin2);

  float soma = 0.0;

  for (int i = 0; i < n_pontos; i++) {
    soma += amostras2[i];
  }
  return soma / n_pontos;
}
///////////////////////
int media_movel3() {
  for (int i = n_pontos - 1; i > 0; i--) {
    amostras3[i] = amostras3[i - 1];
  }
  amostras3[0] = analogRead(potpin3);

  float soma = 0.0;

  for (int i = 0; i < n_pontos; i++) {
    soma += amostras3[i];
  }
  return soma / n_pontos;
}
///////////////////////
int media_movel4() {
  for (int i = n_pontos - 1; i > 0; i--) {
    amostras4[i] = amostras4[i - 1];
  }
  amostras4[0] = analogRead(potpin4);

  float soma = 0.0;

  for (int i = 0; i < n_pontos; i++) {
    soma += amostras4[i];
  }
  return soma / n_pontos;
}
///////////////////////
int media_movel5() {
  for (int i = n_pontos - 1; i > 0; i--) {
    amostras5[i] = amostras5[i - 1];
  }
  amostras5[0] = analogRead(potpin5);

  float soma = 0.0;

  for (int i = 0; i < n_pontos; i++) {
    soma += amostras5[i];
  }
  return soma / n_pontos;
}
///////////////////////



void loop() {
 /*
  Serial.print(" ");
  Serial.print(analogRead(potpin));
  Serial.print(" ");
  Serial.print(media_movel());
  Serial.print(" ");
  Serial.print(analogRead(potpin2));
  Serial.print(" ");
  Serial.print(media_movel2());
  Serial.print(" ");
  Serial.print(analogRead(potpin3));
  Serial.print(" ");
  Serial.print(media_movel3());
  Serial.print(" ");
  Serial.print(analogRead(potpin4));
  Serial.print(" ");
  Serial.print(media_movel4());
  Serial.print(" ");
  Serial.print(analogRead(potpin5));
  Serial.print(" ");
  Serial.println(media_movel5());
*/
  npontos_val = analogRead(cont_npontos);
  npontos_valal = map(npontos_val, 0, 1023, 1, 65);
  
  Serial.print(npontos_valal);
  Serial.println(n_pontos);

  val = map(media_movel(), 0, 800, 0, 180);

  val2 = map(media_movel2(), 0, 800, 0, 180);

  val3 = map(media_movel3(), 0, 800, 0, 180);

  val4 = map(media_movel4(), 0, 1614, 180, 0);

  val5 = map(media_movel5(), 0, 800, 180, 0);


  myservos.write(val);
  myservos2.write(180 - val);

  myservo3.write(val2);

  myservos4.write(val3);
  myservos5.write(180 - val3);

  myservo6.write(val4);

  myservo7.write(val5);
}
