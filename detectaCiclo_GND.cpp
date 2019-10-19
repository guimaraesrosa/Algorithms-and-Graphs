#include <iostream>
#include <list>
#include <deque>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    bool buscaEmProfundidade(int v, bool visited[], int pai[]);
    bool detectaCiclo();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}
void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
    adjacencia[v2].push_back(v1);
}
bool Grafo::buscaEmProfundidade(int v, bool visited[], int pai[]){

    visited[v] = true;
    list<int>::iterator i;
    for(i = adjacencia[v].begin(); i != adjacencia[v].end(); i++){
        if(!visited[*i]){
            pai[*i] = v;
            buscaEmProfundidade(*i, visited, pai);
        }
        else if(*i != pai[v]){
                return true;
        }
    }
    return false;

}
bool Grafo::detectaCiclo(){
    bool visited[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    int pai[V];
    for(int i = 0; i < V; i++){
        if(buscaEmProfundidade(i, visited, pai))
            return true;
        
    }

    return false;

}

int main(){
    Grafo g(3);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,2);
    g.adicionarAresta(1,2);

    if(g.detectaCiclo())
        cout<<"Ciclo detectado no grafo não direcionado"<<endl;
    else
        cout<<"Não há ciclo no grafo não direcionado"<<endl;
    
    return 0;
}