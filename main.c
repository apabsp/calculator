#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

Construa uma calculadora programador didática (didática significa que deve ser mostrado os passos na tela das operações efetuadas),  implementada na linguagem C, que tenha as seguintes conversões
1 - de base 10 para:
a)base 2,
b) base 8,
c) base16, 
d) código BCD Codificação binária decimal

2 - de base 10  para base com sinal com 16 bits, (complemento a 2)
3 - converter real em decimal para float e double, mostrando os respectivos bits de sinal , expoente, expoente com viés e fração 
OBS: deve ser entregue o executável "zipado" com o codigo C com as iniciais do email e link do git com código.  A cada questão implementada deve ser feito um commit no git . O codigo fonte deve conter um cabeçalho dos dados do autor e  revisões/ atualizações com datas e hora

*/


int main(void) {
  char answer[50];
  
  printf("Calculadora!\n");
  printf("Y para continuar\nN para encerrar o programa");
  char continuar;
  float numeroParaCalcular;
  int opcao;

  
  scanf("%c", &continuar);
  
  while (continuar != 'N' || continuar != 'n') {
    printf("Digite o número: ");
    scanf("%f", &numeroParaCalcular);
    printf("Escolha a opção: ");
  }

  return 0;
}

void calculandoBase2(float paraConverter, char answer[50]){
  char string[50]; 
  int intParaConverter = (int)paraConverter; // delete decimals from the equation
  int i = 0;
  while(intParaConverter != 0){
    string[i] = (char)(intParaConverter % 2); //guarantee casting. check this again
    intParaConverter= intParaConverter/2;
    i++;
  }
  strcpy(answer, string);
  
}
