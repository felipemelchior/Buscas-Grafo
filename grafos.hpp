#ifndef GRAFOS_H
#define GRAFOS_H

#include <iostream>
#include <deque> //biblioteca Fila
#include <stack> //biblioteca Pilha
#include <vector> //biblioteca Vecotr
#include <string>
#include <fstream>
#include <omp.h> //biblioteca usada para calcular o tempo passado, nao foi utilizado nenhuma thread da omp

using namespace std;

struct nodo { //struct que contem o indice do nodo e se ele ja foi visitado
	int index;
	int visited;
};
typedef struct nodo Node; //struct renomeada

class Grafo { //Escopo da classe
	public:
		Grafo(); //Construtor padrao
		~Grafo(); //Destrutor padrao
		int existeNode(int node_v1); //Funcao que verfica se existe um nodo com base no indice passado
		int buscaLargura(int node); //Funcao da busca, retorna 1 para sucesso e 0 para fracasso
		int buscaProfundidade(int node); //Funcao da busca, retorna 1 para sucesso e 0 para fracasso
		void zeraVisited(); //zera os campos visitados da struct 
		void adicionaNode(int node_v1, int aux); //adiciona o nodo 
		void adicionaAresta(int node_v1, int node_v2); //adiciona a aresta com base em dois indices
		void leitor(string Nome, int node_procurado); //leitor do arquivo
	private: 
		vector < vector<Node> > adj; //lista de adjacencia
};

Grafo::Grafo(){ //construtor
}

Grafo::~Grafo(){ //destrutor
}

int Grafo::existeNode(int node_v1) {
	int i, flag = 0;

	for(i = 0; i < adj.size(); i++){ //percorre o grafo
		if(adj.at(i).at(0).index == node_v1) { //se achou o indice, seta a flag 1
			flag = 1;
			break; 
		}
	}

	if(flag == 0) {
		adicionaNode(node_v1, i); //se nao achou o indice, entra neste if e acaba gerando um nodo
	}

	return i;
}

int Grafo::buscaLargura(int node) {
	zeraVisited();

	deque <int> Fila; //fila com a biblioteca deque
	int aux;

	Fila.push_back(adj.at(0).at(0).index); //adiciona o nodo inicial na fila

	while(!Fila.empty()) { //enquanto a fila nao estiver vazia
		aux = Fila.front();
		Fila.pop_front();

		if(aux == node) return 1; //encontrou

		for(int i = 0; i < adj.size(); i++) { //percorre o grafo procurando o indice
			if(adj.at(i).at(0).visited == 0) {
				for(int j = 0; j < adj.at(i).size(); j++) {
					Fila.push_back(adj.at(i).at(j).index);
					adj.at(i).at(j).visited = 1; //seta os visitados para 1
				}
			}
		}
	}

	return 0;
}

int Grafo::buscaProfundidade(int node) { //mesmo principio da outra busca
	zeraVisited();

	stack <int> Pilha; //usando pilha da biblioteca stack
	int aux;

	Pilha.push(adj.at(0).at(0).index);

	while(!Pilha.empty()) {
		aux = Pilha.top();
		Pilha.pop();

		if(aux == node) return 1;

		for(int i = 0; i < adj.size(); i++) {
			if(adj.at(i).at(0).visited == 0) {
				for(int j = 0; j < adj.at(i).size(); j++) {
					Pilha.push(adj.at(i).at(j).index);
					adj.at(i).at(j).visited = 1;
				}
			}
		}
	}

	return 0;
}

void Grafo::zeraVisited() {
	for(int i = 0; i < adj.size(); i++) { //percorre todo o grafo setando os visitados como 0
		for(int j = 0; j < adj.at(i).size(); j++) {
			adj.at(i).at(j).visited = 0;
		}
	}
}

void Grafo::adicionaNode(int node_v1, int aux) { //cria um vector e adiciona na lista de adjacencia
	vector <Node> node_adj;
	adj.push_back(node_adj);
	Node nodo;
	nodo.index = node_v1;
	nodo.visited = 0;
	adj.at(aux).push_back(nodo);
}

void Grafo::adicionaAresta(int node_v1, int node_v2) { //adiciona a aresta
	int aux, flag = 0;

	aux = existeNode(node_v1); //teste se existe o nodo, se nao, o nodo eh criado
	
	for(int i = 0; i < adj.at(aux).size(); i++) { //percorre pra verificar se nn existe a aresta
		if(adj.at(aux).at(i).index == node_v2) {
			flag = 1; //se existir, flag recebe 1
		}
	}

	if(flag != 1) { //se nn existir, a aresta eh criada
		Node nodo;
		nodo.index = node_v2;
		nodo.visited = 0;
		adj.at(aux).push_back(nodo);
	}
}

void Grafo::leitor(string Nome, int node_procurado) {
	ifstream iFile; //arquivo de entrada
	iFile.open(Nome.c_str()); //conversao da string no nome para o arquivo

	int node_v1, node_v2, resultado;
	double start, final, elapsed; //variaveis usadas no tempo

	if(!iFile.is_open()){ //teste de abertura do arquivo
		cout << "Failed to open the file!" << endl;
		exit(1);
	}

	start = omp_get_wtime(); //inicio do tempo de adicao das arestas
	while(!iFile.eof()){ //enquanto nao chegar no fim do aquivo
		iFile >> node_v1;
		iFile >> node_v2;
	
		adicionaAresta(node_v1, node_v2); //fica adicionando as arestas de 2 a 2
	} 
	final = omp_get_wtime(); //final do tempo de adicao das arestas

	elapsed = final - start; 

	cout << "All edges added sucessfully with " << elapsed << "s" << endl << endl;

	start = omp_get_wtime(); //inicio tempo da busca em largura
	resultado = buscaLargura(node_procurado);
	final = omp_get_wtime(); //fim tempo da busca em largura

	elapsed = final - start;

	if(resultado == 1)
		cout << "Node " << node_procurado << " found through BFS with " << elapsed << "s" << endl << endl; 
	else
		cout << "Node " << node_procurado << " not found through BFS with " << elapsed << "s" << endl << endl;

	start = omp_get_wtime(); //inicio tempo da busca em profundidade
	resultado = buscaProfundidade(node_procurado);
	final = omp_get_wtime(); //fim tempo da busca em profundidade

	elapsed = final - start;

	if(resultado == 1)
		cout << "Node " << node_procurado << " found through DFS with " << elapsed << "s" << endl << endl; 
	else
		cout << "Node " << node_procurado << " not found through DFS with " << elapsed << "s" << endl << endl;  
}

#endif //fim