#include <iostream>
#include <list>
#include <queue>
#include <limits>

using namespace std;

struct Vertice
{
	string cor;
	int dist;
	int vertice_pai;

	Vertice(string c = "branco", int d = 1000000, int vp = {} )
	{	
        cor = c;
		dist = d;
		vertice_pai = vp;
	}

};

class Grafo{
    int V;
    list<int> *adjacencia;
    Vertice *v;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void buscaEmLargura(int s);
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
    v = new Vertice[V];
    
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
}

void Grafo::buscaEmLargura(int s){
    
    v[s].cor = "cinza";
    v[s].dist = 0;
    v[s].vertice_pai = {};

    queue<int> fila;
    fila.push(s);
    
    int u;
    list<int>::iterator i;

    while(!fila.empty()){
        u = fila.front();
        cout << "Visitando Vertice " << u <<endl;
        fila.pop();

        for(i = adjacencia[u].begin(); i != adjacencia[u].end(); ++i){
            if(v[*i].cor == "branco"){
                v[*i].cor = "cinza";
                v[*i].dist = v[u].dist + 1;
                v[*i].vertice_pai = u;
                fila.push(*i);
            }
        }
        v[u].cor = "preto";
        
    }

    cout<<"\nDados finais de todos os vértices: \n" << endl;
    for(int j=0; j < V; j++){
        cout<<"vertice <" << j << "> cor: "<< v[j].cor << " dist: " << v[j].dist << " v_pai: " << v[j].vertice_pai <<endl;
    }


}

int main(){
    
    Grafo g(4);
    
    g.adicionarAresta(0, 1); 
    g.adicionarAresta(0, 2); 
    g.adicionarAresta(1, 2); 
    g.adicionarAresta(2, 0); 
    g.adicionarAresta(2, 3); 
    g.adicionarAresta(3, 3); 
    
    g.buscaEmLargura(2);
    

    return 0;   
}
