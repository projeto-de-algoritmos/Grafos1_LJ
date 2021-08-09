#include <iostream>
#include <vector>
using namespace std;
// exercicio resolvido utilizando o algoritmo kruskal
// criar tipos pros pares e vetor dos pares de nos
typedef pair<int, int> pr;
typedef vector<pair<int, pr> > vecpr;

// estrutura do grafo
struct Graph{
    int v, e;
    vecpr edges;
    int kruskal();
    
    Graph(int v, int e){
        this->v = v;
        this->e = e;
    }

    void addEdge(int u, int v, int w){
        edges.push_back(make_pair(w, make_pair(u, v)));
        edges.push_back(make_pair(w, make_pair(v, u)));
    }
};

int main() {

    return 0;
}
