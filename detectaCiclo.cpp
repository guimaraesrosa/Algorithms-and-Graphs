#include <iostream>
#include <list>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;

public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    bool detectaCicloRec(int v, bool visited[], bool pilha[]);
    bool detectaCiclo();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
}

bool Grafo::detectaCicloRec(int v, bool visited[], bool pilha[]){

    if(visited[v]==false){
        visited[v] = true;
        pilha[v] = true;
        
        list<int>::iterator it;
        for(it = adjacencia[v].begin(); it != adjacencia[v].end(); it++){
            if(!visited[*it] && detectaCicloRec(*it, visited, pilha)){
                cout << "Vertice "<<*it<<endl;
                return true;
            }
            else if(pilha[*it]){
                cout << "Vertice "<<*it<<endl;
                return true;
            }
        }

    }
    pilha[v] = false;
    return false;
    
}

bool Grafo::detectaCiclo(){
    bool *visited = new bool[V];
    bool *pilha = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = pilha[i] = false;
    
    for(int i = 0; i < V; i++){
        if(detectaCicloRec(i, visited, pilha))
            return true;
    }
    return false;
}

int main(){
    Grafo g(4);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,2);
    g.adicionarAresta(1,3);
    g.adicionarAresta(3,0);

    if(g.detectaCiclo())
        cout<<"Um ciclo foi encontrado"<<endl;
    else
        cout<<"Não há ciclos"<<endl;

    return 0;
}