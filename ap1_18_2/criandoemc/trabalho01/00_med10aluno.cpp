#include <stdio.h>
#include <conio.h>

// Fa�a um algoritmo para calcular a m�dia de 10 alunos considera que para cada aluno ser�o lidas duas notas e que a m�dia ser� a utilizada na ULBRA e que as notas que ser�o lidas s�o G1 e G2. Fa�a uma varia��o para o algoritmo anterior: calculando a m�dia de notas finais dos alunos(media da turma) contando quantos alunos tem a m�dia maior ou igual a 6,0.

main(){
	int x, cont=0;
	float g1, g2, med, smed=0, medt;
	
	//comando de loop
	//x var de controle,x=1 valor inicial da var,
	//x<=10 valor final da var,x++ incrementa somando mais 1 em cada repeticao
	for (x=1; x<=3; x++){
		printf("\n Digiti as notas de G1 e G2 respectivamente");
		printf("\n Digiti a nota de G1: ");
		scanf("%f", &g1);
		printf("\n Digiti a nota de G2: ");
		scanf("%f", &g2);
		med = (g1+(g2*2))/3;
		printf("Com sua nota de G1 = %.2f e G2 = %.2f sua media e igual: %.2f \n", g1, g2, med);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		smed = smed+med;
	if (med>=6)
		cont = cont + 1;
	}
		medt = smed/3;
		printf("\n E a media da turma e de: %.2f ", medt);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n Tivemos %d alunos com media acima de 6.\n",cont);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	getche();
}
