#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll coins;
vll dp;

ll combinations(ll n){
    if(dp[n] != 0) return dp[n];

    ll &ans = dp[n];
    for(ll i=0;i<(ll)coins.size();i++){
        if(coins[i] > n) continue;
        ans += dp[n - coins[i]] % (ll)(1e9 + 7);
    }

    return ans %= (ll)(1e9 + 7);
}

int main()
{
    ll n, x; cin >> n >> x;
    coins.resize(n);
    dp.assign(1000005, 0);
    dp[0] = 1;

    for(ll i=0;i<n;i++) cin >> coins[i];
    for(int i=1;i<=x;i++) combinations(i);

    cout << dp[x] << endl;
    return 0;
}
