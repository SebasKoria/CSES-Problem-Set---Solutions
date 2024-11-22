#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    set<int> nums;

    for(int i=0;i<n;i++){
        int in; cin >> in;
        if(nums.find(in) == nums.end()) nums.insert(in+1);
        else{
            nums.erase(in);
            nums.insert(in+1);
        }
    }

    cout << nums.size() << endl;


    return 0;
}
