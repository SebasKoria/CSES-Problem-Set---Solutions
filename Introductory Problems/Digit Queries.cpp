#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        long long k; cin >> k;
        long long idx = 0;
        long long current = 0;

        if(k <= 9){
            cout << k << endl;
            continue;
        }

        while(current < k){
            current += (idx+1ll) * 9ll * pow(10L, (long double)idx);
            idx++;
        }

        idx--;
        current -= (idx+1ll) * 9ll * pow(10L, (long double)idx);

        long long l = k;
        l -= current;
        k -= current;
        l /= (idx+1ll);
        long long initial_num = pow(10ll, idx);
        initial_num += l - 1ll;

        if(k % (idx+1ll) == 0ll) cout << initial_num % 10ll << endl;
        else{
            string ans = to_string(initial_num+1ll);
            cout << ans[(k % (idx+1ll)) - 1ll] << endl;
        }
    }

    return 0;
}
