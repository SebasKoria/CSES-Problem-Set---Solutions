#include <bits/stdc++.h>

using namespace std;

int dr[] = { 1, 0,-1, 0};
int dc[] = { 0, 1, 0,-1};
int n, m;
vector<string> grid;

int floodfill(int r, int c, char c1, char c2) {
	if ((r < 0) || (r >= n)) return 0;
	if ((c < 0) || (c >= m)) return 0;
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0; d < 4; ++d)
		ans += floodfill(r+dr[d], c+dc[d], c1, c2);
	return ans;
}

int main()
{
    cin >> n >> m;
    grid.resize(n);

    for(int i=0;i<n;i++) cin >> grid[i];

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.'){
                floodfill(i, j, '.', 'W');
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
