#include <bits/stdc++.h>

#define VISITADO 1
#define NOVISITADO 0

using namespace std;

vector<vector<int>> AL;
vector<int> padres;
vector<int> visitados;
vector<int> distancia;

void bfs(int s){
    queue<int> q;
    q.push(s);

    visitados[s] = VISITADO;
    distancia[s] = 1;
    padres[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(const auto& v : AL[u]){
            if(visitados[v] == NOVISITADO){
                q.push(v);
                visitados[v] = VISITADO;
                if(distancia[v] == -1) distancia[v] = distancia[u] + 1;
                padres[v] = u;
            }
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;

    AL.resize(v+1);
    padres.assign(v+1, -1);
    visitados.assign(v+1, NOVISITADO);
    distancia.assign(v+1, -1);

    for(int i=0;i<e;i++){
        int a, b; cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    bfs(1);
    if(distancia[v] == -1) cout << "IMPOSSIBLE\n";
    else{
        cout << distancia[v] << endl;
        stack<int> camino;
        camino.push(v);
        int i = v;
        while(padres[i] != 0){
            camino.push(padres[i]);
            i = padres[i];
        }
        while(!camino.empty()){
            cout << camino.top() << " ";
            camino.pop();
        }
        cout << endl;
    }

    return 0;
}
