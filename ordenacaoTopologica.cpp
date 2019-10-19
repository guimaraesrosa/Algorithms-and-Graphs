#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
    deque<int> pilha;

public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void ordenacaoTopologica();
    void ordenacaoTopologicaRec(int v, string visited[]);
    void imprimeGrafo();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
}

void Grafo::ordenacaoTopologicaRec(int v, string visited[]){
    
    list<int>::iterator i;
    for(i = adjacencia[v].begin(); i != adjacencia[v].end(); i++){
        if(visited[*i] == "branco"){
            visited[*i] = "cinza";
            ordenacaoTopologicaRec(*i, visited);
        }
    }
    visited[v] = "preto";
    deque<int>::iterator it = find(pilha.begin(), pilha.end(), v);
    if(it == pilha.end())
        pilha.push_back(v);

}

void Grafo::ordenacaoTopologica(){
    string visited[V];

    for(int i = 0; i < V; i++)
        visited[i] = "branco";
    
    for(int i = 0; i < V; i++){
        visited[i] = "cinza";
        ordenacaoTopologicaRec(i, visited);
    }

    while(!pilha.empty()){
        imprimeGrafo();
    }

}
void Grafo::imprimeGrafo(){

    if(pilha.back() == 0)
        cout<<"cueca"<<endl;
    else if(pilha.back() == 1)
        cout<<"calca"<<endl;
    else if(pilha.back() == 2)
        cout<<"sapato"<<endl;
    else if(pilha.back() == 3)
        cout<<"meia"<<endl;
    else if(pilha.back() == 4)
        cout<<"cinto"<<endl;
    else if(pilha.back() == 5)
        cout<<"camisa"<<endl;
    else if(pilha.back() == 6)
        cout<<"gravata"<<endl;
    else if(pilha.back() == 7)
        cout<<"terno"<<endl;
    else if(pilha.back() == 8)
        cout<<"relogio"<<endl;
    else if(pilha.back() == 9)
        cout<<""<<endl;

    pilha.pop_back();

}

int main(){
    
    Grafo g(10);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,2);
    g.adicionarAresta(3,2);
    g.adicionarAresta(1,4);
    g.adicionarAresta(1,2);
    g.adicionarAresta(4,7);
    g.adicionarAresta(5,4);
    g.adicionarAresta(5,6);
    g.adicionarAresta(6,7);
    g.adicionarAresta(8,9);

    g.ordenacaoTopologica();

    return 0;
}