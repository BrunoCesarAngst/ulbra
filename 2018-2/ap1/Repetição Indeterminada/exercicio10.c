#include <stdio.h>

/*Faça um programa que receba a idade e a altura de várias pessoas. A cada nova
leitura, deve perguntar ao usuário se ele deseja informar mais dados. O programa
só encerra a leitura de dados quando o usuário responder “NÃO”. Calcule e
imprima a média das alturas das pessoas com mais de 30 anos.*/

int main(){
  float idade, altura, media, cont;
   media = 0.0;
   cont = 0.0;

   do{
     printf ("Digite sua idade:");
     scanf ("%f", &idade);

     printf ("Digite sua altura:");
     scanf ("%f", &altura);
      if (idade > 30){
        media = media + altura;
        cont++;
      }
   }while (idade >0);
   media = media/cont;
   printf ("A media de altura das pessoas com mais de 30 anos é: %.2f", media);
 }
