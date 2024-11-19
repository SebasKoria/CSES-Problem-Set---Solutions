#include <bits/stdc++.h>

using namespace std;

vector<int> apples;
long long totalSum = 0;

int main()
{
    int n; cin >> n;
    apples.resize(n);
    for(int i=0;i<n;i++){
        cin >> apples[i];
        totalSum += apples[i];
    }

    int i=0;
    long long ans = 1e12;
    while(i < pow(2, n)){
        int shft = 0;
        long long sum = 0;
        while(1<<shft <= i){
            if((i & (1<<shft)) != 0){
                sum += apples[shft];
            }
            shft++;
        }
        ans = min(ans, abs(totalSum - 2 * sum));
        i++;
    }

    cout << ans << endl;

    return 0;
}
