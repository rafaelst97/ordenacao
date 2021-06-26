#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void ordenacao(int metodo_de_ordenacao, int selecao_tamanho) {

	if (selecao_tamanho == 1)

	srand((unsigned)time(0)); //para gerar números aleatórios reais.

	//Preenchimento do vetor
	for (int i = 0; i < 100; i++) {
		teste[i] = rand() % (maior - menor + 1) + menor;
	}
}