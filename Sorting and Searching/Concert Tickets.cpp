#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    multiset<int> prices;
    for(int i=0;i<n;i++){
        int in; cin >> in;
        prices.insert(in);
    }

    while(m--){
        int in; cin >> in;
        auto it = prices.upper_bound(in);
        if(it == prices.begin()) cout << -1 << endl;
        else{
            cout << *(--it) << endl;
            prices.erase(it);
        }
    }

    return 0;
}
