#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());
    int mx = v.back();
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += mx - v[i];
    }

    for(int i=n-1;i>=0;i--){
        if(v[i] == mx) continue;
        long long dif = mx - v[i];
        if(dif *(i+1) > (n-(i+1)) * dif){
            sum -= dif * (i+1);
            sum += (n-(i+1)) * dif;
        }
        else break;
        mx = v[i];
    }

    cout << sum << endl;

    return 0;
}
