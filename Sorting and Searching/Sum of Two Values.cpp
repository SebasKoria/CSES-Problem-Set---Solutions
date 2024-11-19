#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    multimap<int,int> nums;
    for(int i=1;i<=n;i++){
        int in; cin >> in;
        nums.insert(make_pair(in, i));
    }

    auto a = nums.begin();
    while(a != nums.end()){
        auto b = nums.find(x-(a->first));
        if(b != nums.end()){
            if(b != a || (b->first == (++b)->first && b != nums.end())){
                cout << a->second << " " << b->second << endl;
                return 0;
            }
        }
        a++;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
