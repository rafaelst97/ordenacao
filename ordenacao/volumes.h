#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void tamanho_volume() {

	int teste[100];

	srand((unsigned)time(0)); //para gerar números aleatórios reais.
	int maior = 100;
	int menor = 1;

	for (int i = 0; i < 100; i++) {
		teste[i] = rand() % (maior - menor + 1) + menor;
	}

	for (int j = 0; j < 100; j++) {
		cout << j+1 << ": " << teste[j] << endl;
	}

}