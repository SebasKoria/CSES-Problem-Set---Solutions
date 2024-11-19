#include <bits/stdc++.h>

#define INF (long long)1e15
#define VISITED 1
#define UNVISITED -1

using namespace std;

class cmp{
    public:
    bool operator()(pair<int, long long> n1, pair<int, long long> n2){
        return (n1.second>n2.second);
    }
};

int v, e;

vector<vector<pair<int, long long>>> AL;
vector<long long> dist;
vector<int> visited;

void dijkstra(int s){
    dist.assign(v+1, INF);
    visited.assign(v+1, UNVISITED);
    dist[s] = 0;

    priority_queue<pair<int,long long>, vector<pair<int, long long>>, cmp> pq;
    pq.push(pair<int, long long>(s, 0ll));

    while(!pq.empty()){
        pair<int, long long> p = pq.top();
        pq.pop();

        if(visited[p.first] == VISITED) continue;
        visited[p.first] = VISITED;

        for(const auto& [v, w] : AL[p.first]){
            if(visited[v] == VISITED) continue;
            if(dist[p.first] + w < dist[v]) dist[v] = dist[p.first] + w;
            pq.push({v, dist[v]});
        }
    }
}

int main()
{
    cin >> v >> e;
    AL.resize(v+1);

    for(int i=0;i<e;i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        AL[a].push_back({b, c});
    }

    dijkstra(1);
    for(int i=1;i<=v;i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}
