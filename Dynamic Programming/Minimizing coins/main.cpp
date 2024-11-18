#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> coins;
vector<ll> dp;

ll minCoins(ll n){
    if(n == 0) return 0;

    ll &ans = dp[n];
    for(int i=0;i<coins.size() && coins[i] <= n; i++){
        ans = min(ans, 1 + dp[n - coins[i]]);
    }

    return ans;
}

int main()
{
    ll n, x; cin >> n >> x;
    coins.resize(n);
    dp.assign(1000005, INT_MAX);
    dp[0] = 0;

    for(ll i=0;i<n;i++) cin >> coins[i];
    sort(coins.begin(), coins.end());


    for(int i=1;i<=x;i++) minCoins(i);
    cout << (dp[x] != INT_MAX ? dp[x] : -1) << endl;

    return 0;
}
