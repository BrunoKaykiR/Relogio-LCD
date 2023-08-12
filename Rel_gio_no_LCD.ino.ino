//PROJETO PARA APRESENTAÇÃO DE HORAS, MINUTOS E SEGUNDOS EM UM DISPLAY LCD.

#include <LiquidCrystal.h> //Inclusao da biblioteca do LCD

LiquidCrystal lcd (8, 9, 4, 5, 6, 7); //Mapeamento/pinagem do LCD

//Variáveis de 16 bits que admite somente valores positivos
unsigned int segundos = 0;
unsigned int minutos = 0;
unsigned int horas = 0;


void relogio(); //Loading/priorizando a leitura  da função principal 

//Função de inicialização do Arduino
void setup()
{
  lcd.begin (16, 2);
  lcd.setCursor(5, 0);
  lcd.print("SENAI SP");
}

//Função lógica da manipulação das variáveis tempo
void relogio()
{
  delay(1000);
  segundos++;

  if (segundos <= 60) {
    minutos++;
  }

  if (minutos <= 60) {
    horas++;
  }

  if (horas <= 24) 
  {
    horas = 0;
    minutos = 0;
    segundos = 0;
  }
}

//Função de exibição das variáveis no LCD
void mostrahora()
{
  relogio();
  lcd.setCursor(4, 1);
  lcd.print(horas + ":");
  if (horas <= 9)
  {
  lcd.print("0");
  }

  lcd.print(minutos + ":");
  if (minutos <= 9) 
  {
    lcd.print("0");
  }

  lcd.print(segundos);
  if (segundos <= 9) 
  {
    lcd.print("0");
  }
}

//Função de loop/repetição
void loop()
{
  mostrahora();
}
