# EP2

Estrutura do programa:
Criei uma estrutura de nó que é compartilhada entre os dois tipos de árvores, em seguida criei as funções para inserir, calcular altura e fator de balanceamento e por fim criei a função que gera o vetor de números aleatórios.
Criei nessa ordem pois era o que fazia sentido na minha cabeça.

Garanti que os elementos gerados são distintos multiplicando a possibilidade de números por 3 (poderia ser qualquer valor no lugar do 3), e a cada número gerado verificando se ele já existe no vetor.

Apesar de teoricamente a árvore de busca binária ser mais rápida para inserir, a diferença de velocidade entre as duas nem é tão grande no caso geral, e pra mim isso é uma vantagem para usar as árvores AVL, porque ela mantém uma altura média bem menor se comparada com a BST (depende da "sorte" também, já que os números são aleatórios no caso), o que faz com que seja interessante implementar a árvore AVL pelo benefício da velocidade de busca (por ter a altura menor).
Achei um estudo interessante.
