#include "arvore.h"

int Max(int a, int b)
{
	return a >  b ? a : b;
}

Node *NewNode(int chave)
{
	Node *new = malloc(sizeof(Node));
	new->altura = 1;
	new->chave = chave;
	new->esq = NULL;
	new->dir = NULL;

	return new;
}

Node *bstInsert(Node *raiz, int chave)
{
	if (!raiz)
	{
		return NewNode(chave);
	}

	if (chave > raiz->chave)
	{
		raiz->dir = bstInsert(raiz->dir, chave);
	}
	else
	{
		raiz->esq = bstInsert(raiz->esq, chave);
	}

	raiz->altura = CalculaAltura(raiz);
	return raiz;
}

int CalculaAltura(Node *raiz)
{
	if (!raiz)
	{
		return 0;
	}
	else
	{
		return Max(CalculaAltura(raiz->esq), CalculaAltura(raiz->dir)) + 1;
	}
}

int GetAltura(Node *raiz)
{
	if (!raiz) 
	{
		return 0;
	}

  	return raiz->altura;
}

int CalculaFatorBalanceamento(Node *raiz)
{
	return GetAltura(raiz->esq) - GetAltura(raiz->dir);
}

Node *avlRotL(Node *raiz)
{
	if (!raiz)
	{
		return raiz;
	}

	Node *newRoot = raiz->dir;
	raiz->dir = newRoot->esq;
	newRoot->esq = raiz;

	raiz->altura = CalculaAltura(raiz);
	newRoot->altura = CalculaAltura(newRoot);

	return newRoot;
}

Node *avlRotR(Node *raiz)
{
	if (!raiz)
	{
		return raiz;
	}

	Node *newRoot = raiz->esq;
	raiz->esq = newRoot->dir;
	newRoot->dir = raiz;

	raiz->altura = CalculaAltura(raiz);
	newRoot->altura = CalculaAltura(newRoot);

	return newRoot;
}

Node *avlInsert(Node *raiz, int chave)
{
	if (!raiz)
	{
		return NewNode(chave);
	}

	if (raiz->chave < chave)
	{
		raiz->dir = avlInsert(raiz->dir, chave);
	}
	else
	{
		raiz->esq = avlInsert(raiz->esq, chave);
	}

	raiz->altura = CalculaAltura(raiz);
	int fb = CalculaFatorBalanceamento(raiz);

	if (fb == 2)
	{
		if (CalculaFatorBalanceamento(raiz->esq) < 0)
		{
			raiz->esq = avlRotL(raiz->esq);
		}
		raiz = avlRotR(raiz);
	}
	else if (fb == -2)
	{
		if (CalculaFatorBalanceamento(raiz->dir) > 0)
		{
			raiz->dir = avlRotR(raiz->dir);
		}
		raiz = avlRotL(raiz);
	}

	return raiz;
}

void Destroy(Node *raiz)
{
	if (!raiz)
	{
		return;
	}

	if (raiz->esq != NULL)
	{
		Destroy(raiz->esq);
	}
	if (raiz->dir != NULL)
	{
		Destroy(raiz->dir);
	}

	free(raiz);
}

int *GeraNumeros(int n)
{
	int *numeros = malloc(sizeof(int) * n);
	srand(time(NULL));
	int flag;

	for (int i = 0; i < n; ++i)
	{
		int temp = rand() % (n*3) + 1;

		for (int j = 0; j < i; ++j)
		{
			if (temp == numeros[j])
			{
				flag = 1;
			}
		}
		if (flag != 1)
		{
			numeros[i] = temp;
		}
		else
			i--;
		flag = 0;
	}

	return numeros;
}