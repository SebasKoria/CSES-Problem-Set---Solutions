#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> nums;
    nums.push_back(string(n, '0'));
    string initial1 = string(n, '0');
    initial1[n-1] = '1';
    nums.push_back(initial1);

    n-=1;
    int idx = n;
    while(n--){
        int sz = nums.size();
        for(int i=sz-1;i>=0;i--){
            string nw = nums[i];
            nw[idx-1] = '1';
            nums.push_back(nw);
        }
        idx--;
    }

    for(int i=0;i<nums.size();i++) cout << nums[i] << "\n";

    return 0;
}
