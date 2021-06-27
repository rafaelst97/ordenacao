#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "operacao.h"

using namespace std;

//Funcao para o menu de escolha do metodo de ordenacao
void segundo_menu(int selecao_tamanho) {

	int escolha_menu = 0;

	//Exibicao do menu de selecao do metodo de ordenacao
	do {
		system("cls");
		cout << endl << "Escolha o metodo de ordenacao" << endl
			<< "1 - Bubble sort" << endl
			<< "2 - Selection Sort" << endl
			<< "3 - Insertion Sort" << endl
			<< "4 - Quick Sort" << endl
			<< "5 - Merge Sort" << endl
			<< "0 - Para voltar" << endl
			<< "Sua opcao: ";
		cin >> escolha_menu;

		switch (escolha_menu) {
		case 0:
			system("cls");
			break;
		case 1:
			ordenacao(escolha_menu, selecao_tamanho);
			escolha_menu = 0;
			break;
		case 2:
			ordenacao(escolha_menu, selecao_tamanho);
			escolha_menu = 0;
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			system("cls");
			cout << endl << "Opcao invalida!" << endl;
			system("pause");
			break;
		}
	} while (escolha_menu != 0);

}