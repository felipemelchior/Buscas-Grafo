/* ****************************************** *
 *                                            *
 * 		FELIPE HOMRICH MELCHIOR               *
 *		 161150758 - UNIPAMPA                 *
 *  https://github.com/homdreen/Buscas-Grafo  *
 *                                            *
 *                                            *
 * ****************************************** */

#include <iostream>

#include "grafos.hpp" //Arquivo da classe incluido

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 3) { //Teste de quantidade de argumentos
		cout << "Missing arguments! Usage: " << argv[0] << "<Graphs_file.txt> <final_node>" << endl; 
	}

	Grafo* gr = new Grafo(); //Criacao do objeto da classe

	gr->leitor(argv[1], atoi(argv[2]) ); //Passado o arquivo para o leitor

	return 0;

}