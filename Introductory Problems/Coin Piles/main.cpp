#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if((a+b) % 3 == 0){
            if(a == 0 && b == 0) cout << "YES\n";
            else if(a == 0 || b == 0) cout << "NO\n";
            else {
                if(min(a,b) >= max(a,b)/2) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        else cout << "NO\n";
    }
    return 0;
}
