#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//Operacao responsavel pela criacao do vetor e ordenacao
void ordenacao(int metodo_de_ordenacao, int selecao_tamanho) {

	if (selecao_tamanho == 1) {

		const int MAX = 10;
		int vetor[MAX];
		int maior = MAX;
		int menor = 1;
		srand((unsigned)time(0)); //para gerar numeros aleatorios reais

		//Preenchimento do vetor
		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
		}

		if (metodo_de_ordenacao == 1) {

		}
	}
}