#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0}; //orden RDLU
int dir[] = {'R', 'D', 'L', 'U'};

int n, m;
vector<string> grid;
vector<vector<int>> bfs_num;
vector<vector<pair<int,int>>> bfs_parent;
vector<vector<char>> direction;
queue<pair<pair<int, int>,char>> q;

void bfs(){
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        char ch = q.front().second;
        q.pop();

        bfs_num[r][c] = VISITED;

        for(int i=0;i<4;i++){
            int ri = r+dr[i], ci = c+dc[i];
            if(ri < 0 || ri >= n) continue;
            if(ci < 0 || ci >= m) continue;
            if(grid[ri][ci] == '#') continue;
            if(ch == 'A' && grid[ri][ci] != '.') continue;

            if(bfs_num[ri][ci] == UNVISITED){
                //cout << ch << " goes to " << ri << ", " << ci << endl;
                bfs_num[ri][ci] = VISITED;
                if(ch == 'A'){
                    direction[ri][ci] = dir[i];
                    bfs_parent[ri][ci] = {r, c};
                }
                q.push({{ri,ci}, ch});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    grid.resize(n);
    bfs_num.assign(n, vector<int>(m, UNVISITED));\
    bfs_parent.assign(n, vector<pair<int,int>>(m));
    direction.assign(n, vector<char>(m, '-'));

    int starti, startj;
    for(int i=0;i<n;i++){
        cin >> grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A'){
                starti = i;
                startj = j;
            }
            else if(grid[i][j] == 'M'){
                q.push({{i,j}, 'M'});
            }
        }
    }
    q.push({{starti, startj}, 'A'});
    bfs();

    int ansi=-1, ansj=-1;
    for(int j=0;j<m;j++){
        if(direction[0][j] != '-' || grid[0][j] == 'A'){
            ansi = 0;
            ansj = j;
            break;
        }
        else if(direction[n-1][j] != '-'  || grid[n-1][j] == 'A'){
            ansi = n-1;
            ansj = j;
            break;
        }
    }

    for(int i=1;i<n-1;i++){
        if(direction[i][0] != '-' || grid[i][0] == 'A'){
            ansi = i;
            ansj = 0;
            break;
        }
        else if(direction[i][m-1] != '-' || grid[i][m-1] == 'A'){
            ansi = i;
            ansj = m-1;
            break;
        }
    }

    if(ansi != -1 && ansj != -1){
        cout << "YES\n";
        if(!(ansi == starti && ansj == startj)){
            stack<char> s;
            s.push(direction[ansi][ansj]);
            pair<int,int> p = bfs_parent[ansi][ansj];
            while(!(p.first == starti && p.second == startj)){
                s.push(direction[p.first][p.second]);
                p = bfs_parent[p.first][p.second];
            }
            cout << s.size() << endl;
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << endl;
        }
        else cout << 0 << endl;
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
