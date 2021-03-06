#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

//Funcao do Bublesort --------------------------------------------------------------------------------------------------
int bubble_sort(int vetor[], const int MAX ) {

	int contador_de_operacoes = 0;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				int aux = vetor[j + 1];
				vetor[j + 1] = vetor[j];
				vetor[j] = aux;
				++contador_de_operacoes;
			}
			++contador_de_operacoes;
		}
		++contador_de_operacoes;
	}
	return contador_de_operacoes;
}

//Funcao de Selection Sort ---------------------------------------------------------------------------------------------
int selection_sort(int vetor[], const int MAX) {
	int contador_de_operacoes = 0;
	for (int i = 0; i < MAX; i++) {
		int memoria = i;
		int aux = 0;
		for (int j = i; j < MAX; j++) {
			if (vetor[j] < vetor[memoria]) {
				memoria = j;
				++contador_de_operacoes;
			}
			++contador_de_operacoes;
		}
		aux = vetor[i];
		vetor[i] = vetor[memoria];
		vetor[memoria] = aux;
		++contador_de_operacoes;
	}
	return contador_de_operacoes;
}

//Funcao de Insertion Sort ---------------------------------------------------------------------------------------------
int insertion_sort(int vetor[], const int MAX) {
	int contador_de_operacoes = 0;
	int temp = 0;
	for (int i = 1; i < MAX; i++) {
		int temp = vetor[i];
		int j = i - 1;

		while ((j >= 0) && (vetor[j] > temp)) {
			vetor[j + 1] = vetor[j];
			j--;
			++contador_de_operacoes;
		}

		vetor[j + 1] = temp;
		++contador_de_operacoes;
	}

	return contador_de_operacoes;
}

//Funcao de Quick Sort -------------------------------------------------------------------------------------------------
int quick_sort(int vetor[], int inicio, int fim) {

	int contador_de_operacoes = 0;
	int i, j, pivo, aux;
	i = inicio;
	j = fim - 1;
	pivo = vetor[(inicio + fim) / 2];
	while (i <= j)
	{
		while (vetor[i] < pivo && i < fim)
		{
			i++;
			contador_de_operacoes++;
		}
		while (vetor[j] > pivo && j > inicio)
		{
			j--;
			contador_de_operacoes++;
		}
		if (i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
			contador_de_operacoes++;
		}
	}
	if (j > inicio) {
		quick_sort(vetor, inicio, j + 1);
		contador_de_operacoes++;
	}
	if (i < fim) {
		quick_sort(vetor, i, fim);
		contador_de_operacoes++;
	}

	contador_de_operacoes++;

	return contador_de_operacoes;
}

//Funcao de Merge Sort ------------------------------------------------------------------------------------------------

//Juncao da funcao de Merge Sort
void juntar(int vetor[], int inicio, int meio, int fim, int vetor_aux[], unsigned long long int &contador_de_operacoes) {
	int esquerda = inicio;
	int direita = meio;
	for (int i = inicio; i < fim; ++i) {
		if ((esquerda < meio) and ((direita >= fim) or (vetor[esquerda] < vetor[direita]))) {
			vetor_aux[i] = vetor[esquerda];
			++esquerda;
		}
		else {
			vetor_aux[i] = vetor[direita];
			++direita;
		}
	}
	//copiando o vetor de volta
	for (int i = inicio; i < fim; ++i) {
		vetor[i] = vetor_aux[i];
	}
}

//Entrada da funcao de Merge Sort
void merge_sort(int vetor[], int inicio, int fim, int vetor_aux[], unsigned long long int &contador_de_operacoes) {
	if ((fim - inicio) < 2) return;

	int meio = ((inicio + fim) / 2);
	merge_sort(vetor, inicio, meio, vetor_aux, contador_de_operacoes);
	merge_sort(vetor, meio, fim, vetor_aux, contador_de_operacoes);
	juntar(vetor, inicio, meio, fim, vetor_aux, contador_de_operacoes);

	contador_de_operacoes++;
}

//Operacao responsavel pela criacao do vetor e ordenacao
void ordenacao(int metodo_de_ordenacao, int selecao_tamanho) {

	unsigned long long int contador_de_operacoes = 0;
	//Volume de dados pequeno -----------------------------------------------------------------------------------------
	if (selecao_tamanho == 1) {

		const int MAX = 10;
		int* vetor = new int[MAX];
		int* vetor_aux = new int[MAX];
		int maior = MAX;
		int menor = 1;

		srand((unsigned)time(0)); //para gerar numeros aleatorios reais

		//Preenchimento do vetor

		system("cls");

		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
			//cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i]; <------- Habilitar para visualizacao do vetor
		}

		//cout << endl; <----quebra de linha para melhor visualizacao
		//system("pause"); <----pausa para conseguri visualizar o vetor

		//Bubble Sort -------------------------------------------------------------------------------------------------
		if (metodo_de_ordenacao == 1) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Bubble Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = bubble_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Selection Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 2) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Selection Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = selection_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Insertion Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 3) {
			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Insertion Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = insertion_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Quick Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 4) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Quick Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = quick_sort(vetor, 0, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS ------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS---------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

		//Merge Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 5) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Merge Sort
			cout << "Processando os dados..." << endl;
			merge_sort(vetor, 0, MAX, vetor_aux, contador_de_operacoes);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

	}
	//Volume de dados medio -------------------------------------------------------------------------------------------
	else if (selecao_tamanho == 2) {

		const int MAX = 1000;
		int* vetor = new int[MAX];
		int* vetor_aux = new int[MAX];
		int maior = MAX;
		int menor = 1;

		srand((unsigned)time(0)); //para gerar numeros aleatorios reais

		//Preenchimento do vetor

		system("cls");

		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
			//cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i]; <------- Habilitar para visualizacao do vetor
		}

		//cout << endl; <----quebra de linha para melhor visualizacao
		//system("pause"); <----pausa para conseguri visualizar o vetor

		//Bubble Sort -------------------------------------------------------------------------------------------------
		if (metodo_de_ordenacao == 1) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Bubble Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = bubble_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Selection Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 2) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Selection Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = selection_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Insertion Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 3) {
			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Insertion Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = insertion_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Quick Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 4) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Quick Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = quick_sort(vetor, 0, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS ------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS---------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

		//Merge Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 5) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Merge Sort
			cout << "Processando os dados..." << endl;
			merge_sort(vetor, 0, MAX, vetor_aux, contador_de_operacoes);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

	}
	//Volume de dados grande -------------------------------------------------------------------------------------------
	else if (selecao_tamanho == 3) {

		const int MAX = 100000;
		int* vetor = new int[MAX];
		int* vetor_aux = new int[MAX];
		int maior = MAX;
		int menor = 1;

		srand((unsigned)time(0)); //para gerar numeros aleatorios reais

		//Preenchimento do vetor

		system("cls");

		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
			//cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i]; <------- Habilitar para visualizacao do vetor
		}

		//cout << endl; <----quebra de linha para melhor visualizacao
		//system("pause"); <----pausa para conseguri visualizar o vetor

		//Bubble Sort -------------------------------------------------------------------------------------------------
		if (metodo_de_ordenacao == 1) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Bubble Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = bubble_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//--------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Selection Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 2) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Selection Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = selection_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Insertion Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 3) {
			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Insertion Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = insertion_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			//-------------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Quick Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 4) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Quick Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = quick_sort(vetor, 0, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//-----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS ------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//----------------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS---------------------------
			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

		//Merge Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 5) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Merge Sort
			cout << "Processando os dados..." << endl;
			merge_sort(vetor, 0, MAX, vetor_aux, contador_de_operacoes);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			//------------------------HABILITAR PARA VISUALIZAR OS DADOS ORDENADOS-------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

	}
	//Volume de dados massivo -------------------------------------------------------------------------------------------
	else if (selecao_tamanho == 4) {

		const int MAX = 10000000;
		int* vetor = new int[MAX];
		int* vetor_aux = new int[MAX];
		int maior = MAX;
		int menor = 1;

		srand((unsigned)time(0)); //para gerar numeros aleatorios reais

		//Preenchimento do vetor

		system("cls");

		for (int i = 0; i < MAX; i++) {
			vetor[i] = rand() % (maior - menor + 1) + menor;
			//cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i]; < ----- Habilitar para visualiza??o
		}

		//cout << endl; < ---- Separar por linhas a visualiza??o
		//system("pause"); < ------- Pausar ao final da visualiza??o

		//Bubble Sort -------------------------------------------------------------------------------------------------
		if (metodo_de_ordenacao == 1) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Bubble Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = bubble_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Selection Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 2) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Selection Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = selection_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i+1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Insertion Sort ----------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 3) {
			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Insertion Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = insertion_sort(vetor, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {
			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];
			//}
			//cout << endl;
			//system("pause");
			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");
		}

		//Quick Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 4) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Quick Sort
			cout << "Processando os dados..." << endl;
			contador_de_operacoes = quick_sort(vetor, 0, MAX);
			delete vetor;
			delete vetor_aux;
			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

		//Merge Sort --------------------------------------------------------------------------------------------------
		else if (metodo_de_ordenacao == 5) {

			auto start = std::chrono::high_resolution_clock::now();
			//Mecanismo do Merge Sort
			cout << "Processando os dados..." << endl;
			merge_sort(vetor, 0, MAX, vetor_aux, contador_de_operacoes);
			delete vetor;
			delete vetor_aux;

			//Contagem do tempo e do numero de operacoes
			auto end = std::chrono::high_resolution_clock::now();
			system("cls");

			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------
			//system("cls");
			//for (int i = 0; i < MAX; i++) {

			//	cout << endl << "Posicao: " << i + 1 << " | Valor: " << vetor[i];

			//}
			//cout << endl;
			//system("pause");
			// ------------------ Habilitar visualiza??o do vetor ordenado --------------------------------------

			std::chrono::duration<double, std::milli> float_ms = end - start;
			system("cls");
			std::cout << endl << "A ordenacao foi executada em: " << float_ms.count() << " milissegundos" << std::endl;
			cout << "Numero de Operacoes realizadas: " << contador_de_operacoes << endl;
			system("pause");

		}

	}

}