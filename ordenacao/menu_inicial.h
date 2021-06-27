#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "segundo_menu.h"

using namespace std;


//Menu inicial e escolha do tamanho do array que sera ordenado
void menu_inicial() {
	
	int escolha_menu = 0;

	//Exibicao do menu inicial
	do {
		system("cls");
		cout << endl << "Escolha o tamanho do volume de dados desejado." << endl
			<< "1 - Volume pequeno (10 itens)" << endl
			<< "2 - Volume medio (1.000 itens)" << endl
			<< "3 - Volume grande (100.000 itens)" << endl
			<< "4 - Volume massivo (10.000.000 itens)" << endl
			<< "0 - Sair do programa" << endl
			<< "Sua opcao: ";
		cin >> escolha_menu;

		//Mecanismo do menu inicial
		switch (escolha_menu){
		case 0:

			system("cls");
			break;

		case 1:

			system("cls");
			segundo_menu(escolha_menu);
			break;

		case 2:

			system("cls");
			segundo_menu(escolha_menu);
			break;

		case 3:

			system("cls");
			segundo_menu(escolha_menu);
			break;

		case 4:

			system("cls");
			segundo_menu(escolha_menu);
			break;

		default:

			system("cls");
			cout << endl << "Opcao invalida!" << endl;
			system("pause");
			break;
		}
	} while (escolha_menu != 0);
}