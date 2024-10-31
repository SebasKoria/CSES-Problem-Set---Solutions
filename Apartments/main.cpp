#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    multiset<int> desired, sizes;
    //vector<bool> used(m, false);

    for(int i=0;i<n;i++){int in; cin >> in; desired.insert(in);}
    for(int i=0;i<m;i++){int in; cin >> in; sizes.insert(in);}

    int ans = 0;
    for(auto elem : desired){
        auto it = sizes.lower_bound(elem - k);
        if(it != sizes.end() && *it <= elem + k){
            ans ++;
            sizes.erase(it);
        }
    }

    cout << ans << endl;

    return 0;
}
