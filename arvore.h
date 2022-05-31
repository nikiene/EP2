#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int chave;
	int altura;
	struct node *esq;
	struct node *dir;
} Node;

int Max(int a, int b);

Node *NewNode(int chave);

Node *bstInsert(Node *raiz, int chave);

int CalculaAltura(Node *raiz);

int GetAltura(Node *raiz);

int CalculaFatorBalanceamento(Node *raiz);

Node *avlRotL(Node *raiz);

Node *avlRotR(Node *raiz);

Node *avlInsert(Node *raiz, int chave);

void Destroy(Node *raiz);

int *GeraNumeros(int n);