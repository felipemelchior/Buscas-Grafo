/*
 *
 * FELIPE HOMRICH MELCHIOR
 *	161150758 - UNIPAMPA
 *
 */

#include <iostream>

#include "grafos.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 4) {
		cout << "Missing arguments! Usage: " << argv[0] << "<Graphs_file.txt> <initial_node> <final_node>" << endl; 
	}

	Grafo* gr = new Grafo();

	gr->leitor(argv[1]);

	return 0;

}