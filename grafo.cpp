// Felipe Homrich Melchior

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct node {
	int index;
	bool visited;
	vector <struct node*> *adj;
};
typedef struct node Node;

struct grafo {
	int m;
	vector <Node*> vertices;
};
typedef struct 	grafo Grafo;

Grafo add_aresta(Grafo* g, int index){
	return Grafo;
}

int main(int argc, char **argv) {
	
	if(argc < 2) {
		cout << "Faltam argumentos!" << endl << "Uso: " << argv[0] << "<ArquivoGrafo.txt>"
	}


}