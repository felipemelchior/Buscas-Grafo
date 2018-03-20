#ifndef GRAFOS_H
#define GRAFOS_H

#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct nodo {
	int index;
	int visited;
};
typedef struct nodo Node;

class Grafo {
	public:
		Grafo();
		~Grafo();
		int existeNode(int node_v1);
		int verificaTamanho(int node_v1);	
		void adicionaNode(int node_v1, int aux);
		void adicionaAresta(int node_v1, int node_v2);
		void leitor(string Nome);
	private: 
		vector < vector<Node> > adj;
};

Grafo::Grafo(){
}

Grafo::~Grafo(){
}

int Grafo::existeNode(int node_v1) {
	int i, flag = 0;

	for(i = 0; i < adj.size(); i++){
		if(adj.at(i).at(0).index == node_v1) {
			flag = 1;
			break; 
		}
	}

	if(flag == 0) {
		adicionaNode(node_v1, i);
	}

	return i;
}

void Grafo::adicionaNode(int node_v1, int aux) {
	vector <Node> node_adj;
	adj.push_back(node_adj);
	Node nodo;
	nodo.index = node_v1;
	nodo.visited = 0;
	adj.at(aux).push_back(nodo);
}

void Grafo::adicionaAresta(int node_v1, int node_v2) {
	int aux, flag = 0;

	aux = existeNode(node_v1);
	
	for(int i = 0; i < adj.at(aux).size(); i++) {
		if(adj.at(aux).at(i).index == node_v2) {
			flag = 1;
		}
	}

	if(flag != 1) {
		Node nodo;
		nodo.index = node_v2;
		nodo.visited = 0;
		adj.at(aux).push_back(nodo);
	}
}

void Grafo::leitor(string Nome) {
	ifstream iFile;
	iFile.open(Nome.c_str());

	int node_v1, node_v2;

	if(!iFile.is_open()){
		cout << "Failed to open the file!" << endl;
		exit(1);
	}

	while(!iFile.eof()){
		iFile >> node_v1;
		iFile >> node_v2;
	
		adicionaAresta(node_v1, node_v2);
	} 

	cout << "all nodes added" << endl;
}

#endif