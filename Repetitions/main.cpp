#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a; cin >> a;
    int ans = 1, cnt = 1;

    for(int i=1;i<(int)a.length();i++){
        if(a[i] == a[i-1]){
            cnt++;
        }
        else cnt = 1;
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
