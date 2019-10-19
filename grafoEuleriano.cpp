#include <iostream>
#include <list>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
    int *in;

public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void buscaEmProfundidade(int v, bool visited[]);
    bool conexaoEntreVertices();
    bool grafoEuleriano();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
    in = new int[V];

    for(int i = 0; i < V; i++)
        in[i] = 0;

}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);

    (in[v2])++;

}

void Grafo::buscaEmProfundidade(int v, bool visited[]){

    visited[v] = true;

    list<int>::iterator it;
    for(it = adjacencia[v].begin(); it != adjacencia[v].end(); it++)
        if(!visited[*it])
            buscaEmProfundidade(*it, visited);

}

bool Grafo::conexaoEntreVertices(){
    bool visited[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    //Encontra primeiro vértice com grau maior que 0
    int n;
    for(int i = 0; i < V; i++)
        if(adjacencia[i].size() > 0){
            n = i;
            break;
        }
            
    buscaEmProfundidade(n, visited);

    //Se a busca em profundidade não visitou todos os vertices
    //e grau de adjacencia for maior que 0
    for(int i = 0; i < V; i++)
        if(adjacencia[i].size() > 0 && visited[i] == false)
            return false;
    
    return true;

}

bool Grafo::grafoEuleriano(){

    if(conexaoEntreVertices() == false)
        return false;
    
    //verifica grau de adjacencia
    for(int i = 0; i < V; i++)
        if(adjacencia[i].size() != in[i])
            return false;
    
    return true;
    
}

int main(){
    Grafo g(5);
    g.adicionarAresta(1,0);
    g.adicionarAresta(0,2);
    g.adicionarAresta(2,1);
    g.adicionarAresta(0,3);
    g.adicionarAresta(3,4);
    g.adicionarAresta(4,0);

    if(g.grafoEuleriano())
        cout << "O grafo direcionado é Euleriano\n";
    else
        cout << "O grafo direcionado não é Euleriano\n";

    return 0;
}

