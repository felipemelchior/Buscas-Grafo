#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <ifstream>

using namespace std;

class Grafo {
	public:
		Grafo();
		~Grafo();
		Grafo(int v);
		//void criaGrafo();
		void leitor(string Nome);
		void adicionaAresta(int vert1, vert2);
	private:
		int v;
		list<int> *adj;

}	

Grafo::Grafo(){
}

Grafo::~Grafo(){
}

Grafo::Grafo(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Grafo::leitor(string Nome) {
	ifstream iFile;
	iFile.open(Nome.c_str());

	int v1, v2;

	if(!iFile.is_open()) {
		cout << "Erro ao abrir o arquivo" << endl;
		exit(1);
	}

	while(!iFile.eof()) {
		iFile >> v1;
		iFile >> v2;

		cout << v1 << " -> " << v2 << endl;
	}
}

#endif