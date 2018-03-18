/*
 *	Felipe Homrich Melchior
 *   161150758 - UNIPAMPA
 *
 */

#include <iostream>

#include "grafos.hpp"

using namespace std;

int main(int argc, char *argv[]) {

	Grafo* gr = new Grafo();

	if(argc < 2) {
		cout << "Faltam argumentos!" << endl << "Uso: " << argv[0] << " <Arquivo_Grafo>" << endl;
		exit(1);
	}

	gr->leitor(argv[1]);

	return 0;
}