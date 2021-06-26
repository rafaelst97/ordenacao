#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

//Operacao responsavel pela criacao do vetor e ordenacao
void ordenacao(int metodo_de_ordenacao, int selecao_tamanho) {

	int contador_de_operacoes = 0;
	//Volume de Dados pequeno
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

		//Bubble Sort
		if (metodo_de_ordenacao == 1) {

			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX-1; j++) {
					if (vetor[j] > vetor[j + 1]) {
						int aux = vetor[j + 1];
						vetor[j + 1] = vetor[j];
						vetor[j] = aux;
						++contador_de_operacoes;
					}
				}
			}
		}
	}

	system("cls");
	cout << endl << "Numero de Operaçoes realizadas: " << contador_de_operacoes << endl;
	system("pause");
}