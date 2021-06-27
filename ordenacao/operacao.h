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

		system("cls");

		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
			cout << endl << "Posicao: " << i << " | Valor: " << vetor[i];
		}

		cout << endl;
		system("pause");

		//Bubble Sort
		if (metodo_de_ordenacao == 1) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Bubble Sort
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
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();

			system("cls");
			for (int i = 0; i < MAX; i++) {
				cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			}
			cout << endl;
			system("pause");

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Selection Sort
		else if (metodo_de_ordenacao == 2) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Selection Sort
			for (int i = 0; i < MAX; i++) {
				int memoria = i;
				int aux = 0;
				for (int j = i; j < MAX; j++) {
					if (vetor[j] < vetor[memoria]) {
						memoria = j;
					}
				}
				aux = vetor[i];
				vetor[i] = vetor[memoria];
				vetor[memoria] = aux;
				++contador_de_operacoes;
			}
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();

			system("cls");
			for (int i = 0; i < MAX; i++) {
				cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			}
			cout << endl;
			system("pause");

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

	}
}