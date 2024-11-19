#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> AL(n+1);
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

	vector<int> color(n+1, INT_MAX);
	bool isBipartite = true;
	for(int i=1;i<=n && isBipartite;i++){
        if(color[i] == INT_MAX){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty() && isBipartite) {
                int u = q.front(); q.pop();
                for (auto &v : AL[u]) {
                    if (color[v] == INT_MAX) {
                        color[v] = 1-color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }
	}


	if(isBipartite){
        for(int i=1;i<=n;i++) cout << color[i] + 1 << " ";
        cout << endl;
	}
	else cout << "IMPOSSIBLE\n" << endl;

    return 0;
}
