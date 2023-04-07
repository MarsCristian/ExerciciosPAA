/*
    Cristian Cesar Martins - 799714
    Vitor Gabriel Orsin    - 801575

    Exercicio Emtrenos
*/
//////////////////////////////////////////////////////////////////////////////////
//libs
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef pair<int, double> pii;

const int MAXN = 105;
const int INF = 1e9;

vector<pii> adj[MAXN];
bool vis[MAXN];

//////////////////////////////////////////////////////////////////////////////////
//GRAFO
// define o tipo Graph como uma lista de adjacências
typedef vector< list<int> > Graph;

void EncheGrafo(Graph g)
{

}

//dijkstra
void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int v = pq.top().second;
        double d = pq.top().first;
        pq.pop();

        if (vis[v]) continue;
        vis[v] = true;

        for (pii u : adj[v]) {
            int to = u.first;
            double len = u.second;
            if (d + len < pq.top().first) continue;
            pq.push({d + len, to});
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//main
int main() {
    int m, e, n, c;
    cin >> m >> e >> n >> c;

    for (int i = 0; i < e; i++) {
        int u, v;
        double d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    while (c--) {
        int impostor;
        cin >> impostor;

        // Reseta o vetor de visitados
        memset(vis, false, sizeof(vis));

        // Executa Dijkstra a partir do impostor
        dijkstra(impostor);

        if (vis[0]) {
            cout << "defeat\n";
        } else {
            cout << "victory\n";
        }
    }

    return 0;
}
