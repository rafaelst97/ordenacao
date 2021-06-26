#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;


//Menu inicial
void menu_inicial() {
	
	int escolha_menu = 0;

	//Exibicao do menu inicial
	do {
		cout << endl << "Escolha o tamanho do volume de dados desejado." << endl
			<< "1 - Volume pequeno (10 itens)" << endl
			<< "2 - Volume medio (1.000 itens)" << endl
			<< "3 - Volume grande (100.000 itens)" << endl
			<< "4 - Volume massivo (10.000.000 itens)" << endl
			<< "0 - Sair do programa" << endl;
		cin >> escolha_menu;

		switch (escolha_menu){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:

			system("cls");
			cout << endl << "Opcao invalida!" << endl;
			break;
		}
	} while (escolha_menu != 0);
}


//Funcao referente a escolhe de volume
/*void tamanho_volume() {

	//Variaveis utilizadas
	int volume = 0;
	int maior = 0;
	int menor = 0;

	//Exibicao do menu da escolha do tamanho do volume
	cout << "Escolha o tamanho do volume a ser utilizado." << endl
		<< "1 - Pequeno: Vetor de 10 itens." << endl
		<< "2 - Medio: Vetor de 1.000 itens." << endl
		<< "3 - Grande: Vetor de 10.000 itens." << endl
		<< "4 - Massivo: Vetor de 10.000.000 itens." << endl;
	cin >> volume;

	switch (volume) {
	case 1:
		maior = 10;
		menor = 1;
		break;
	case 2:
		maior = 1000;
		menor = 1;
		break;
	case 3:
		maior = 10000;
		menor = 1;
		break;
	case 4:
		maior = 10000000;
		menor = 1;
		break;
	default:
		cout << "Opcao invalida!";
	}

	srand((unsigned)time(0)); //para gerar números aleatórios reais.

	//Preenchimento do vetor
	for (int i = 0; i < 100; i++) {
		teste[i] = rand() % (maior - menor + 1) + menor;
	}

	for (int j = 0; j < 100; j++) {
		cout << j+1 << ": " << teste[j] << endl;
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 99; j++) {
			if (teste[j] > teste[j + 1]) {
				int aux = teste[j + 1];
				teste[j + 1] = teste[j];
				teste[j] = aux;
			}
		}
	}

	for (int j = 0; j < 100; j++) {
		cout << j + 1 << ": " << teste[j] << endl;
	}

}*/