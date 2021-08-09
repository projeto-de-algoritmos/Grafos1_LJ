#include <iostream>
#include <vector>
using namespace std;
// exercicio resolvido utilizando o algoritmo kruskal
// criar tipos pros pares e vetor dos pares de nos
typedef pair<int, int> pr;
typedef vector<pair<int, pr> > vecpr;

// estrutura do grafo
struct Graph {
    int v, e;
    vecpr edges;
    int kruskal();

    Graph(int v, int e) {
        this->v = v;
        this->e = e;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(make_pair(w, make_pair(u, v)));
        edges.push_back(make_pair(w, make_pair(v, u)));
    }
};

struct DisjointSet {
    int *rank, *parent;
    int n;

    DisjointSet(int n) {
        this->n = n;
        rank = new int[n + 1];
        parent = new int[n + 1];

        for(int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if(rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
        if(rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

int Graph::kruskal() {
    int weight = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds(v);

    for(auto i = edges.begin(); i != edges.end(); i++) {
        int u = i->second.first;
        int v = i->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            weight += i->first;
            ds.merge(set_u, set_v);
        }
    }
    return weight;
}

int main() {

    return 0;
}
