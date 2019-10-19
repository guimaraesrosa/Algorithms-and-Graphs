#include <iostream>
#include <list>
#include <deque>

using namespace std;

deque<int> ord = {2,0,1,3};

class Grafo{
    int V;
    list<int> *adjacencia;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void buscaEmProfundidade(int v, bool visited[]);
    bool detectaOrdenacao();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}
void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
}

void Grafo::buscaEmProfundidade(int v, bool visited[]){

    visited[v] = true;

    if(v == ord.front())
        ord.pop_front();

    list<int>::iterator i;
    for(i = adjacencia[v].begin(); i != adjacencia[v].end(); i++){
        if(!visited[*i]){
            buscaEmProfundidade(*i,visited);
        }
    }

}

bool Grafo::detectaOrdenacao(){

    bool visited[V];
    int u;
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    
    u = ord.front();
    cout << u << endl;
    buscaEmProfundidade(u, visited);
        
    if(ord.empty())
        return true;
    else
        return false;

}

int main(){
    Grafo g(4);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,2);
    g.adicionarAresta(1,2);
    g.adicionarAresta(2,3);


    if(g.detectaOrdenacao())
        cout << "É uma ordem topológica do grafo" << endl;
    else
        cout << "Não é uma ordem topológica do grafo" << endl;

    return 0;
}
