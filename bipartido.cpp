#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    bool detectaBiparidade(int v);
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);

}

bool Grafo::detectaBiparidade(int v){
    int grafo[V][V];
    int color[V];

    list<int>::iterator j;
    for(int i = 0; i < V; i++)
        for(j = adjacencia[i].begin(); j != adjacencia[i].end(); j++)
            grafo[i][*j] = 1;
        
    for(int i = 0; i < V; i++)
        color[i] = -1;
    
    color[v] = 1;

    for(int u = 0; u < V; u++){

        if(grafo[u][u] == 1)
            return false;
        
        for(int w = 0; w < V; w++){
            if(grafo[u][w] == 1 && color[w] == -1)
                color[w] = 1 - color[u];
            
            else if(grafo[u][w] == 1 && color[w] == color[u])
                return false;
        }
    }

    return true;
}

int main(){
    Grafo g(6);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,3);
    //g.adicionarAresta(0,2);
    g.adicionarAresta(2,3);
    g.adicionarAresta(4,3);
    g.adicionarAresta(4,5);
    g.adicionarAresta(1,0);
    g.adicionarAresta(3,0);
    g.adicionarAresta(3,2);
    g.adicionarAresta(3,4);
    g.adicionarAresta(4,5);
    g.adicionarAresta(5,4);

    if(g.detectaBiparidade(0))
        cout<<"Grafo bipartido"<<endl;
    else
        cout<<"Grafo não é bipartido"<<endl;

    return 0;

}
