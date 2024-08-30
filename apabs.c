//Antonio Paulo Araujo de Barros e Silva - apabs 
// Calculando base 2 e função de inverter feito - 21/08/2024 22:17
// Calculando Base 8, Base 16 e BCD - 25/08/2024 15:55
// Questao 2 e 3 finalizadas - 30/08 18:10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>  
/*

Construa uma calculadora programador didática (didática significa que deve ser
mostrado os passos na tela das operações efetuadas),  implementada na linguagem
C, que tenha as seguintes conversões 1 - de base 10 para: a)base 2, b) base 8,
c) base16,
d) código BCD Codificação binária decimal

2 - de base 10  para base com sinal com 16 bits, (complemento a 2)
3 - converter real em decimal para float e double, mostrando os respectivos bits
de sinal , expoente, expoente com viés e fração OBS: deve ser entregue o
executável "zipado" com o codigo C com as iniciais do email e link do git com
código.  A cada questão implementada deve ser feito um commit no git . O codigo
fonte deve conter um cabeçalho dos dados do autor e  revisões/ atualizações com
datas e hora

*/

// try placing all the subfunctions in another file later

char *Invert(char string[50]) {
  int encontrado = 0;
  char *stringNew = (char *)malloc(sizeof(char[50]));

  while (string[encontrado] != '\0') { // find end of array
    encontrado++;
  }
  int i = 0;
  // invert array
  for (encontrado = encontrado - 1; encontrado >= 0; encontrado--) {
    stringNew[i] = string[encontrado];
    i++;
  }

  return stringNew;
}

void calculandoBase2(float paraConverter, char answer[50]) {
  char myNewString[50];
  int intParaConverter =
      (int)paraConverter; // delete decimals from the equation
  int i = 0;
  while (intParaConverter != 0) {
    // myNewString[i] = 1; // guarantee casting. check this again
    myNewString[i] = (intParaConverter % 2) ? '1' : '0';
    printf("%d %% 2 = %d\n", intParaConverter, intParaConverter % 2);
    intParaConverter = intParaConverter / 2;
    i++;
  }
  myNewString[i] = '\0';
  strcpy(answer, myNewString);
  // Invert(answer);

  printf("Resposta é: %s", Invert(answer));
}

void calculandoBase8(float paraConverter, char answer[50]) {
  char myNewString[50];
  int intParaConverter = (int)paraConverter;
  int i = 0;
  while (intParaConverter != 0) {
    myNewString[i] = (intParaConverter % 8) + '0';
    printf("%d %% 8 = %d\n", intParaConverter, intParaConverter % 8);
    intParaConverter = intParaConverter / 8;
    i++;
  }
  myNewString[i] = '\0';
  strcpy(answer, myNewString);
  printf("Resposta é: %s\n", Invert(answer));
}

//  BC
void calculandoBase16(float paraConverter, char answer[50]) {
  char myNewString[50];
  int intParaConverter = (int)paraConverter;
  int i = 0;
  while (intParaConverter != 0) {
    int restante = intParaConverter % 16;

    myNewString[i] = (restante < 10)
                         ? (restante + '0')
                         : (restante - 10 + 'A'); // lets use ASCII to our
                                                  // advantage 3 3 + '0'
    printf("%d %% 16 = %d\n", intParaConverter, restante);

    intParaConverter = intParaConverter / 16;
    i++;
  }
  myNewString[i] = '\0';
  strcpy(answer, myNewString);
  printf("Resposta é: %s\n", Invert(answer));
}

// binary coded decimal! like 0 = 0000, 2 = 0010, 3 = 0011, 16 = 00010000
void calculandoBCD(float paraConverter, char answer[50]) {
  char myNewString[50];
  int intParaConverter = (int)paraConverter;
  int i = 0;

  while (intParaConverter != 0) {
    int digito = intParaConverter % 10; 
    intParaConverter = intParaConverter / 10; // removes processed digit

    for (int j = 3; j >= 0; j--) {
      myNewString[i++] = (digito & (1 << j)) ? '1' : '0';
    }
  }

  myNewString[i] = '\0'; 
  strcpy(
      answer,
      Invert(
          myNewString)); 
  printf("Resposta em BCD é: %s\n", Invert(answer));
}


void calculandoComplementoA2(int numero) {
    char binario[17];
    int i;

    // Inicializa a string binário com zeros
    for (i = 0; i < 16; i++) {
        binario[i] = '0';
    }
    binario[16] = '\0';

    // Converte o número para binário
    for (i = 15; i >= 0; i--) {
        binario[i] = (numero & 1) ? '1' : '0';
        numero >>= 1;
    }

    // Exibe o binário no formato complemento a 2
    printf("Complemento a 2 com 16 bits: %s\n", binario);
}

// Função para converter um número decimal em ponto flutuante para representação em float e double
void conversaoFloatDouble(float numero) {
  // unions 
    union {
        float f;
        unsigned int i;
    } floatConverter;

    union {
        double d;
        unsigned long long l;
    } doubleConverter;

    floatConverter.f = numero;
    doubleConverter.d = (double)numero;

    printf("Representação em float:\n");
    printf("Sinal: %d\n", (floatConverter.i >> 31) & 1);
    printf("Expoente: %d\n", ((floatConverter.i >> 23) & 0xFF) - 127);
    printf("Mantissa: 0x%06X\n", floatConverter.i & 0x7FFFFF);

    printf("Representação em double:\n");
    printf("Sinal: %lld\n", (doubleConverter.l >> 63) & 1);
    printf("Expoente: %lld\n", ((doubleConverter.l >> 52) & 0x7FF) - 1023);
    printf("Mantissa: 0x%013llX\n", doubleConverter.l & 0xFFFFFFFFFFFFF);
}




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
    printf("Escolha a opção: \n 1-Para binário\n 2-Para base octo\n 3-Para "
           "base 16\n 4- Para BCD \n 5-Para complemento a 2 (16 bits)\n 6-Para float e double\n \n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1: // binary
      calculandoBase2(numeroParaCalcular, answer);
      break;
    case 2:
      calculandoBase8(numeroParaCalcular, answer);
      break;
    case 3:
      calculandoBase16(numeroParaCalcular, answer);
      break;
    case 4:
      calculandoBCD(numeroParaCalcular, answer);
      break;
    case 5:
          calculandoComplementoA2((int)numeroParaCalcular);
          break;
    case 6:
          conversaoFloatDouble(numeroParaCalcular);
          break;
    default:
          printf("Input inválido\n");
          break;
    }
  }

  return 0;
}
