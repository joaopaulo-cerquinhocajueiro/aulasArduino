/*
  Display LCD com LM35
 
 Demonstra o uso de um display LCD mostrando a temperatura
 medida com um lm35.
 */

// inclui a biblioteca do LCD
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
/* Incializa o LCD
 * Circuito:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2  */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// O LM35 é simples e não precisa de uma biblioteca
const int lm35Pin = A0;

// Uma variável para guardar a medida
float value; //float para fazermos uma média
// E outra para guardar a temperatura
float temperature;

void setup() {
  // Não necessário para usar o analogRead, mas útil para legibilidade
  pinMode(lm35Pin,INPUT);
  // Utilizado para aumentar a precisão
  analogReference(INTERNAL1V1); // para arduino MEGA
  //analogReference(INTERNAL); // para arduino UNO
  // Inicializa o LCD, de acordo com o número de colunas e linhas 
  lcd.begin(16, 2);
  // Imprime cabeçalho no LCD
  lcd.print("Medida  Temp.");
  // Inicializa a serial
  Serial.begin(9600);
}

void loop() {

  //Faz a média de 5 medidas seguidas da temperatura
  value = 0;
  for(int i=0;i<5;i++){
    value = value +  analogRead(lm35Pin);
  }
  value = value/5.0;
  
  // Converte para graus.
  temperature = value*110.0/1023;

  // Move o cursor do LCD para começo da segunda linha
  lcd.setCursor(0, 1);
  // Imprime o valor:
  lcd.print(value);
  lcd.print("  ");
  // Imprime a temperatura
  lcd.setCursor(8, 1);
  lcd.print(temperature);
  lcd.print("   ");

  // E envia pela serial para gerar um gráfico  
//  Serial.print(value);
//  Serial.print(' ');
  Serial.println(temperature);
  delay(300);
}

