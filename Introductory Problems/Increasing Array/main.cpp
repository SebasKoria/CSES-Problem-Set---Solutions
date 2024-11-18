#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int mx = 1, in;
    long long ans = 0;
    while(n--){
        cin >> in;
        mx = max(mx, in);
        if(in < mx) ans += mx - in;
    }
    cout << ans << endl;
    return 0;
}
