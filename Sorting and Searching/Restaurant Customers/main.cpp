#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n);

    for(int i=0;i<n;i++) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0, j=0;
    int ans = 0;
    int mx = ans;
    while(i < n && j < n){
        if(a[i] < b[j]) {
            ans++;
            i++;
        }
        else{
            j++;
            ans--;
        }
        mx = max(mx, ans);
    }

    cout << mx << endl;

    return 0;
}
