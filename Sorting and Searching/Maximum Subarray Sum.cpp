#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    long long int mx = INT_MIN;
    long long int sum = 0;
    long long int ans = 0;

    while(n--){
        long long int in; cin >> in;
        mx = max(mx, in);
        sum = max(0ll, sum + in);
        ans = max(ans, sum);
    }

    cout << (ans == 0 ? mx : ans) << endl;

    return 0;
}
