#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
public:
    Grafo(int V);
    void adicionarArestas(int v1, int v2);
    void mostrarBfs(int v, bool visited[]);
    void bfs();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarArestas(int v1, int v2){
    adjacencia[v1].push_back(v2);
    adjacencia[v2].push_back(v1);
}

void Grafo::mostrarBfs(int v, bool visited[]){

    visited[v] = true;
    int u;
    queue<int> fila;

    fila.push(v);

    while(!fila.empty()){
        u = fila.front();
        cout << "Visitando vértice " << u << endl;
        fila.pop();
        list<int>::iterator i;
        for(i = adjacencia[u].begin(); i != adjacencia[u].end(); i++){
            if(!visited[*i]){
                fila.push(*i);
                visited[*i] = true;
            }
        }
    }

}

void Grafo::bfs(){
    bool visited[V];
    
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    mostrarBfs(0, visited);

}

int main(){

    Grafo g(7);

    g.adicionarArestas(0,1);
    g.adicionarArestas(0,2);
    g.adicionarArestas(0,3);
    g.adicionarArestas(1,5);
    g.adicionarArestas(1,6);
    g.adicionarArestas(3,4);

    g.bfs();

    return 0;
}

