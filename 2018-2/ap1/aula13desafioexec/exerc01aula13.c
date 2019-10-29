#include <stdio.h>

main() {
  int idade, temServ, disc, entrevistados = 0, faixaIdade = 0, maisDeDez = 0, totalDisc = 0;
  char resp;
  float porcFaixa, medDisc;
  do {
    printf("A sua idade: ");
    scanf("%i", &idade);
      if (idade >= 30 && idade <= 50) {
        faixaIdade++;
      }
    printf("Quanto tempo de serviço: ");
    scanf("%i", &temServ);
      if (temServ > 10) {
        maisDeDez++;
      }
    printf("Quantas disciplinas exerce: ");
    scanf("%i", &disc);
    totalDisc += disc;
    do {
      printf("\nTem mais alguém para ser entrevistado?(S-N): ");
      scanf(" %c", &resp);
    } while ((resp != 'S') && (resp != 's') && (resp != 'N') && (resp != 'n'));
    entrevistados++;
  } while((resp != 'N') && (resp != 'n'));
  printf("\n\nForam %i professores entrevistado.\n", entrevistados);
  porcFaixa = (100 * faixaIdade) / entrevistados;
  printf("São %.2f%% de professores entre 30 e 50 anos.\n", porcFaixa);
  printf("%i professores ensinam a mais de 10 anos.\n", maisDeDez);
  medDisc = totalDisc / entrevistados;
  printf("São %.1f disciplinas por professor.\n", medDisc);
  return 0;
}
