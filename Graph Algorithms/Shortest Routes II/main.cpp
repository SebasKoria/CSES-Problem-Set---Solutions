#include <bits/stdc++.h>

#define INF (long long)1e15

using namespace std;

int n, m, q;

vector<vector<pair<int,long long>>> AL;
vector<vector<long long>> dist;

void floyd_warshall(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int i=1;i<=n;i++){
        for(const auto& [v, w] : AL[i]){
            dist[i][v] = min(dist[i][v], w);
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> q;

    AL.resize(n+1);
    dist.assign(n+1, vector<long long>(n+1, INF));

    for(int i=1;i<=m;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        AL[a].push_back({b, c});
        AL[b].push_back({a, c});
    }

    floyd_warshall();
    for(int i=0;i<q;i++){
        int v1, v2; cin >> v1 >> v2;
        cout << (dist[v1][v2] == INF ? -1 : dist[v1][v2]) << endl;
    }

    return 0;
}
