#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//Funcao para o menu de escolha do metodo de ordenacao
void segundo_menu(int selecao_tamanho) {

	int escolha_menu = 0;

	//Exibicao do menu de selecao do metodo de ordenacao
	do {
		system("cls");
		cout << endl << "Escolha o metodo de ordenacao" << endl
			<< "1 - Bubble sort" << endl
			<< "2 - Segundo metodo" << endl
			<< "3 - Terceiro metodo" << endl
			<< "0 - Para voltar" << endl
			<< "Sua opcao: ";
		cin >> escolha_menu;

		switch (escolha_menu) {
		case 0:
			system("cls");
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			system("cls");
			cout << endl << "Opcao invalida!" << endl;
			system("pause");
			break;
		}
	} while (escolha_menu != 0);

}