#include "arvore.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int opc = 0, amostras = 0, elementos = 0;
	float avgBST = 0, avgAVL = 0, avg = 0;
	double avgTimeBST = 0, avgTimeAVL = 0, avgTime = 0;

	clock_t BSTStart, BSTEnd;
    double BSTTime;
    clock_t AVLStart, AVLEnd;
    double AVLTime;

	do
	{
		printf("---\n");
		printf("1 - Nova simulação\n0 - Sair\n");
		scanf("%d", &opc);
		printf("---\n");

		switch(opc)
		{
			case 1:
				printf("Digite a quantidade de amostras\n");
				scanf("%d", &amostras);
				printf("Digite a quantidade de elementos por amostra\n");
				scanf("%d", &elementos);
				printf("---\n");

				Node *raizBST[amostras], *raizAVL[amostras];

				for (int i = 0; i < amostras; ++i)
				{
					raizBST[i] = NULL;
					raizAVL[i] = NULL;
				}

				int temp[amostras][elementos];
				for(int i = 0; i < amostras; ++i)
				{
					temp[i][elementos] = *GeraNumeros(elementos);
				}

				for(int i = 0; i < amostras; ++i)
				{
					for(int j = 0; j < elementos; ++j)
					{
						BSTStart = clock();

						raizBST[i] = bstInsert(raizBST[i], temp[i][j]);

						BSTEnd = clock();
						BSTTime = (double) ((BSTEnd-BSTStart)/CLOCKS_PER_SEC);
						avgTimeBST += BSTTime;

						AVLStart = clock();

						raizAVL[i] = avlInsert(raizAVL[i], temp[i][j]);

						AVLEnd = clock();
						AVLTime = (double) ((AVLEnd-AVLStart)/CLOCKS_PER_SEC);
						avgTimeAVL += AVLTime;
					}

					avgBST += GetAltura(raizBST[i]);
					avgAVL += GetAltura(raizAVL[i]);
					avg = ((avgBST / amostras) + (avgAVL / amostras)) / 2;
					avgTime = ((avgTimeBST / amostras) + (avgTimeAVL / amostras)) / 2;

					Destroy(raizBST[i]);
					Destroy(raizAVL[i]);
					free(temp);
				}

				printf("---\n");
				printf("Experimento com %d amostras e %d elementos / amostra\n", amostras, elementos);
				
				printf("\nAltura média geral: %.2f\n", avg);
	            printf("Tempo médio geral de construção: %lf\n\n", avgTime);
	            
	            printf("Altura média BST comum: %.2f\n", avgBST / amostras);
	            printf("Tempo médio de construção BST comum: %lf\n\n", avgTimeBST / amostras);
	            
	            printf("Altura média AVL: %.2f\n", avgAVL / amostras);
	            printf("Tempo médio de construção AVL: %lf\n\n", avgTimeAVL / amostras);
				printf("---\n");

				break;
		}

	} while (opc != 0);

	return 0;
}