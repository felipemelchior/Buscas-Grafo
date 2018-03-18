#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <fstream>

using namespace std;

class Grafo {
	public:
		Grafo();
		~Grafo();
		Grafo(int v);
		void criaGrafo(int vertices);
		void leitor(string Nome);
		void adicionaAresta(int v1, int v2);
		void imprimeArquivo(int v1, int v2);
	private:
		int v;
		list<int> *adj;

};	

Grafo::Grafo(){
}

Grafo::~Grafo(){
}

Grafo::Grafo(int v) {
	this->v = v;
	adj = new list<int>[v];
}

void Grafo::criaGrafo(int vertices) {
	this->v = vertices;
	adj = new list<int>[vertices];
}

void Grafo::leitor(string Nome) {
	ifstream iFile;
	iFile.open(Nome.c_str());

	int v1, v2, numeroVertices=0;

	if(!iFile.is_open()) {
		cout << "Erro ao abrir o arquivo" << endl;
		exit(1);
	}

	while(!iFile.eof()) {
		iFile >> v1;
		iFile >> v2;

		if(v1 > numeroVertices) numeroVertices = v1;

		/*if(v1 > numeroVertices) {
			numeroVertices = v1;
			criaGrafo(numeroVertices);	
		}*/

		//adicionaAresta(v1, v2);

		//imprimeArquivo(v1, v2); // Funcao usada para testar o leitor
	}

	criaGrafo(numeroVertices);

	/*iFile.close();
	iFile.open(Nome.c_str());

	while(!iFile.eof()) {
		iFile >> v1;
		iFile >> v2;
		
		adicionaAresta(v1, v2);

		//imprimeArquivo(v1, v2); // Funcao usada para testar o leitor
	}*/

}

void Grafo::adicionaAresta(int v1, int v2) {
	adj[v1].push_back(v2);
}

void Grafo::imprimeArquivo(int v1, int v2) { // Funcao usada para testar o leitor
	cout << v1 << " -> " << v2 << endl;
}

#endif