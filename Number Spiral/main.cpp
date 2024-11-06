#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--){
        long long a, b; cin >> a >> b;
        if(max(a, b) % 2 != 0){
            if(b < a) cout << (a-1)*(a-1) + b << endl;
            else cout << b*b - a + 1 << endl;
        }
        else{
            if(a >= b) cout << a*a - b + 1 << endl;
            else cout << (b-1)*(b-1) + a << endl;
        }
    }
    return 0;
}
