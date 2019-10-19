#include <iostream>
#include <list>

using namespace std;

int relogio;

struct Vertice
{
    string cor;
    int vertice_pai;
    int inicio;
    int fim;

    Vertice(string c = "branco", int vp = {}, int s = 0, int f = 0)
    {
        cor = c;
        vertice_pai = vp;
        inicio = s;
        fim = f;
    }
};

class Grafo{
    int V;
    list<int> *adjacencia;
    Vertice *v;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void buscaEmProfundidade();
    void buscaEmProfundidadeRecursivo(int w);
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
    v = new Vertice[V];
}

void Grafo::adicionarAresta(int v1, int v2){

    adjacencia[v1].push_back(v2);

}

void Grafo::buscaEmProfundidadeRecursivo(int w){

    relogio = relogio + 1;
    v[w].inicio = relogio;
    v[w].cor = "cinza";

    cout << "Visitando Vertice " << w <<endl;

    list<int>::iterator i;
    for(i = adjacencia[w].begin(); i != adjacencia[w].end(); i++){
        if(v[*i].cor == "branco"){
            v[*i].vertice_pai = w;
            buscaEmProfundidadeRecursivo(*i);
        }
    }

    v[w].cor = "preto";
    relogio = relogio + 1;
    v[w].fim = relogio;
    
}

void Grafo::buscaEmProfundidade(){

    relogio = 0;
    for(int i = 0; i < V; i++){
        if(v[i].cor == "branco"){
            buscaEmProfundidadeRecursivo(i);
        }
    }

    cout<<"\nDados finais de todos os vértices: \n" << endl;
    for(int j=0; j < V; j++){
        cout<<"vertice <" << j << "> cor: "<< v[j].cor << " relogio: " << v[j].inicio <<"/"<< v[j].fim << " v_pai: " << v[j].vertice_pai <<endl;
    }

}

int main(){
    Grafo g(6);

    g.adicionarAresta(0,1);
    g.adicionarAresta(0,3);
    g.adicionarAresta(1,4);
    g.adicionarAresta(2,4);
    g.adicionarAresta(2,5);
    g.adicionarAresta(3,1);
    g.adicionarAresta(4,3);
    g.adicionarAresta(5,5);

    g.buscaEmProfundidade();

    return 0;
}