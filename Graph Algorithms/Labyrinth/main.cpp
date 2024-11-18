#include <bits/stdc++.h>

using namespace std;

int dr[] = { 1, 0,-1, 0};
int dc[] = { 0, 1, 0,-1};
char dir[] = {'D', 'R', 'U', 'L'};
int n, m;
bool pathFound = false;
char path = '.', block = '#', goal = 'B';
string ansPath = "";
vector<string> grid;
vector<vector<int>> distancia;
vector<vector<pair<int, int>>> parents;
vector<vector<char>> direction;

bool isThereAPath(int i, int j){
    bool found = false;
    grid[i][j] = block;

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while(!q.empty() && !found){
        pair<int,int> p = q.front();
        q.pop();

        for(int d=0; d<4; d++){
            int r = p.first+dr[d], c = p.second+dc[d];
            if(r < 0 || r >= n) continue;
            if(c < 0 || c >= m) continue;
            if(grid[r][c] == '#') continue;

            found = grid[r][c] == goal;
            grid[r][c] = block;
            distancia[r][c] = distancia[p.first][p.second]+1;
            parents[r][c] = p;
            direction[r][c] = dir[d];

            if(found) break;
            q.push(make_pair(r, c));
        }
    }
    return found;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    distancia.resize(n);
    parents.resize(n);
    direction.resize(n);

    int starti = 0, startj = 0, endi = 0, endj = 0;
    for(int i=0;i<n;i++){
        parents[i].resize(m);
        direction[i].resize(m);
        distancia[i].assign(m, -1);

        cin >> grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A'){
                starti = i;
                startj = j;
            }
            if(grid[i][j] == 'B'){
                endi = i;
                endj = j;
            }
        }
    }

    distancia[starti][startj] = 0;

    if(isThereAPath(starti, startj)){
        cout << "YES" << endl;
        cout << distancia[endi][endj] << endl;
        stack<char> shortest;
        pair<int,int> i = make_pair(endi, endj);
        while(!(i.first == starti && i.second == startj)){
            shortest.push(direction[i.first][i.second]);
            i = parents[i.first][i.second];
        }
        while(!shortest.empty()){
            cout << shortest.top();
            shortest.pop();
        }
        cout << endl;
    }
    else printf("NO\n");

    return 0;
}
