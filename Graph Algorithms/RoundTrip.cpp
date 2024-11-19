#include <bits/stdc++.h>

#define UNVISITED -1
#define EXPLORED 0
#define VISITED 1

using namespace std;

vector<int> dfs_num;
vector<int> dfs_parent;
vector<vector<int>> AL;
int ansNode;

bool cycleCheck(int u) {
	dfs_num[u] = VISITED;

	bool hasCycle = false;
	for(const auto& v : AL[u]){
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            hasCycle |= cycleCheck(v);
        }
        else if(dfs_parent[u] != v){
            dfs_parent[v] = u;
            ansNode = u;
            hasCycle = true;
        }
        if(hasCycle) break;
	}
	return hasCycle;
}

int main()
{
    int v, e; cin >> v >> e;

    AL.resize(v+1);
    dfs_num.assign(v+1, UNVISITED);
    dfs_parent.assign(v+1, 0);

    for(int i=0;i<e;i++){
        int a, b; cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    vector<int> ans;
    for(int i=1;i<=v;i++){
        if(dfs_num[i] == UNVISITED){
            if(cycleCheck(i)){
                ans.push_back(ansNode);
                int j = ansNode;
                do{
                    j = dfs_parent[j];
                    ans.push_back(j);
                }while(j != ansNode);
                cout << ans.size() << endl;
                for(int k=0;k<ans.size();k++) cout << ans[k] << " ";
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";



    return 0;
}
