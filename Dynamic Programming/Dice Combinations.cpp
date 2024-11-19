#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp(1000005, 0);

ll diceCombinations(ll n){
    if(dp[n] != 0) return dp[n];

    ll &ans = dp[n];
    for(ll i=1;i<=6 && i <= n;i++){
        ans += diceCombinations(n - i) % (ll)(1e9 + 7);
    }
    return ans;
}

int main()
{
    dp[0] = 1;
    ll n; cin >> n;
    cout << diceCombinations(n)  % (ll)(1e9 + 7) << endl;
    return 0;
}
