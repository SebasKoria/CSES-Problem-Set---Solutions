#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    if(n >= 2 && n <= 3) cout << "NO SOLUTION\n";
    else{
        for(int i=(n%2==0?n-1:n);i>=1;i-=2) cout << i << " ";
        for(int i=(n%2==0?n:n-1);i>=2;i-=2) cout << i << " ";
        cout << endl;
    }

    return 0;
}
