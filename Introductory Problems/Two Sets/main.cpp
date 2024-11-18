#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n; cin >> n;
    long long temp = (n * (n+1ll))/2ll;
    if(temp % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    temp /= 2ll;
    long long curr = 0;
    long long last = 0;
    vector<long long> nums;

    for(int i=n;i>0;i--){
        if(curr + i <= temp){
            nums.push_back(i);
            curr += i;
        }
        else{
            last = i+1;
            if(temp != curr) nums.push_back(temp-curr);
            break;
        }
    }

    cout << nums.size() << endl;
    for(int i=0;i<nums.size();i++) cout << nums[i] << " ";
    cout << endl;

    cout << n-nums.size() << endl;
    for(int i=1;i<last;i++){
        if(i != temp-curr) cout << i << " ";
    }
    cout << endl;

    return 0;
}
