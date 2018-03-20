// Felipe Homrich Melchior

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

struct node {
	int index;
	int visited = 0;
	vector<struct node*> *adj;
};
typedef struct node Node;

struct grafo {
	int m;
	vector<Node*> vertices;
};
typedef struct grafo Grafo;

Grafo* criaGrafo() {
	Grafo *gr = (Grafo*)malloc(sizeof(Grafo));
	gr->m = 0;

	return gr;
}

int existeNode(Grafo *gr, int index) {
	for(int i = 0; i < gr->vertices.size(); i++)	{
		if(gr->vertices[i]->index == index) return 1;
	}
	
	return 0;
}

Node* addNode(Grafo *gr, int index) {
	if(!existeNode(gr, index)) {
		Node *n = (Node*)malloc(sizeof(Node));
		n->index = index;
		n->adj = new vector<Node*>;
		gr->vertices.push_back(n);
		return n;
	}

	return NULL;
}

Node* buscaNode(Grafo *gr, int index) {
	for(int i = 0; i < gr->vertices.size(); i++) {
		if(gr->vertices[i]->index = index) {
			cout << gr->vertices[i]->index << endl;
			return gr->vertices[i];
		}
	}

	return NULL;
}

vector<Node*>* vertcesAdj(Grafo *gr, int i) {
	Node* node = buscaNode(gr, i);
	
	if(node != NULL) {
		return node->adj;
	}else{
		return NULL;
	}
}

void addArco(Grafo *gr, int i, int j) {
	Node *node_i = buscaNode(gr, i);
	Node *node_j = buscaNode(gr, j);

	if(node_i == NULL) {
		node_i = addNode(gr, i );
	}
	if(node_j == NULL){
		node_j = addNode(gr, j );
	}

	node_i->adj->push_back(node_j);

	gr->m += 1;
}

void addAresta(Grafo *gr, int i, int j) {
	addArco(gr, i, j);
	addArco(gr, j, i);
	
}

int bfs(Grafo* gr, int s, int t) {
	for(int i = 0; i < gr->vertices.size(); i++) {
		gr->vertices.at(i)->visited = 0;
	}

	deque<Node*> queue;
	Node* aux;
	int i;
	aux = buscaNode(gr, s);

	if(aux == NULL) return 0;
	queue.push_back(aux);

	while(!queue.empty()) {
		aux = queue.front();
		queue.pop_front();
		aux->visited = 1;

		if(aux->index == t) {
			cout << "Encontrado com sucesso" << endl;
			return 1;
		}

		for(i = 0; i < aux->adj->size(); i++) {
			if(aux->adj->at(i)->visited == 0) {
				queue.push_back(aux->adj->at(i));
			}
		}
	}

	return 0;
}

int buscaProfundidade(Grafo* gr, int ini, int fim) {
	vector <Node*> Pilha;
	Node* aux;

	//Limpando as flags de visitados dos nodos
	for(int i = 0; i < gr->vertices.size(); i++) { 
		gr->vertices[i]->visited = 0;
	}

	aux = buscaNode(gr, ini);

	if(aux == NULL) return 0;
	Pilha.push_back(aux);

	while(!Pilha.empty()) {
		aux = Pilha.back();
		Pilha.pop_back();
		aux->visited = 1;

		if(aux->index == fim) {
			cout << endl << fim << " <- Encontrado com sucesso" << endl;
			return 1;
		}

		for(int i = 0; i < aux->adj->size(); i++) {
			cout << aux->adj->at(i)->index << endl;
			if(aux->adj->at(i)->visited == 0) Pilha.push_back(aux->adj->at(i));
		}
	}

	return 0;
}

int main(int argc, char *argv[]) {
	int node_v1, node_v2;
	ifstream iFile;

	int resultado = 0;
	
	if(argc < 4) {
		cout << "Faltam argumentos!" << endl << "Uso: " << argv[0] << " <Arquivo_grafos_txt>" << endl;
		exit(1);
	}

	iFile.open(argv[1]);

	if(!iFile.is_open()) {
		cout << "Falha ao abrir o arquivo!" << endl;
		exit(1);
	}

	Grafo* gr = criaGrafo();

	while(!iFile.eof()) {
		iFile >> node_v1;
		iFile >> node_v2;
		
		addAresta(gr, node_v1, node_v2);
	}
	
	cout << "Todas as arestas adicionadas com sucesso" << endl;

	//resultado = buscaProfundidade(gr, atoi(argv[2]), atoi(argv[3]) );

	resultado = bfs(gr, atoi(argv[2]), atoi(argv[3]));

	cout << resultado << endl;

	return 0;
}