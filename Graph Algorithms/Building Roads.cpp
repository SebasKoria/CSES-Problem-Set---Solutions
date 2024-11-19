#include <bits/stdc++.h>

#define VISITADO 1
#define NOVISITADO -1

using namespace std;

vector<vector<int>> AL;
vector<int> visitados;

void dfs(int u){
    if(visitados[u] == VISITADO) return;

    visitados[u] = VISITADO;
    for(const auto& v : AL[u]){
        dfs(v);
    }
}

int main()
{
    int n, m; cin >> n >> m;

    AL.resize(n+1);
    visitados.assign(n+1, NOVISITADO);

    for(int i=0;i<m;i++){
        int a, b; cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    int cc = 0;
    vector<int> cities;
    for(int i=1;i<=n;i++){
        if(visitados[i] == NOVISITADO){
            cities.push_back(i);
            cc++;
            dfs(i);
        }
    }

    cout << cc-1 << endl;
    for(int i=1;i<cities.size();i++) cout << cities[0] << " " << cities[i] << endl;

    return 0;
}
