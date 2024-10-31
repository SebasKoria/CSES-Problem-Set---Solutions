#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    set<int> nums;
    while(n--){
        int in; cin >> in;
        nums.insert(in);
    }
    cout << nums.size() << endl;

    return 0;
}
