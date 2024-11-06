#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int, int>> movies(n);
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b;
        movies[i] = make_pair(b, a);
    }
    sort(movies.begin(), movies.end());

    auto it = movies.begin();
    int ans = 1;
    int currentFinishTime = (it++)->first;

    while(it != movies.end()){
        if(it->second < currentFinishTime)
            it++;
        else{
            ans++;
            currentFinishTime = (it++)->first;
        }
    }

    cout << ans << endl;

    return 0;
}
