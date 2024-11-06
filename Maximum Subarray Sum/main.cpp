#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    long long int sum = 0;
    long long int ans = 0;

    while(n--){
        long long int in; cin >> in;
        sum = max(0ll, sum + in);
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
