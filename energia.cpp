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
    int buscaEmLargura(int v);
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
}
int Grafo::buscaEmLargura(int v){

    bool *visitado = new bool[V];
    for(int i = 0; i< V; i++)
        visitado[i] = false;

    queue<int> fila;
    fila.push(v);
    visitado[v] = true;
    int qt_visitas = 1;

    list<int>::iterator i;
    while(!fila.empty()){
        v = fila.front();
        cout << "Visitando estacao "<< v << endl;
        fila.pop();
        for(i = adjacencia[v].begin(); i != adjacencia[v].end(); i++){
            if(!visitado[*i]){
                visitado[*i] = true;
                qt_visitas++;
                fila.push(*i);
            }
        }
    } 
    return qt_visitas;

}

int main(){

    int teste = 0, estacao, linha, x, y, qt_visitas;

    while(true){
        cin>>estacao>>linha;
        //cout<<"E "<<estacao<<"L "<<linha<<"\n";
        teste++;
        
        if(estacao == 0 && linha == 0)
            break;

        Grafo g(estacao);
        for(int i = 0; i < linha; i++){
            cin>>x>>y;
            //cout<<"x:"<<x<<"y:"<<y<<"\n";
            g.adicionarAresta(x-1,y-1);
        }
        qt_visitas = g.buscaEmLargura(0);

        cout<<"Teste "<<teste<<endl;
        if(qt_visitas == estacao)
            cout<<"normal\n\n";
        else
            cout<<"falha\n\n";
        
    }


    /*Grafo g(4);
    g.adicionarAresta(0, 1); 
    g.adicionarAresta(0, 2); 
    g.adicionarAresta(1, 2); 
    g.adicionarAresta(2, 0); 
    g.adicionarAresta(2, 3); 
    g.adicionarAresta(3, 3); 

    g.buscaEmLargura(2);*/

    return 0;
}
