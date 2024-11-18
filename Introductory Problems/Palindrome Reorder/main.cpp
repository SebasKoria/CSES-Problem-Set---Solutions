#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin >> s;
    map<char, int> freq;

    for(int i=0;i<s.length();i++){
        freq[s[i]]++;
    }

    string ans1 = "", ans2 = "";
    char midLetter;
    bool hasMidLetter = false;
    for(const auto& [l, f] : freq){
        if(f % 2 == 0){
            string rpt = string(f/2, l);
            ans1 += rpt;
            ans2 = rpt + ans2;
        }
        else{
            if(!hasMidLetter){
                midLetter = l;
                hasMidLetter = true;
                string rpt = string(f/2, l);
                ans1 += rpt;
                ans2 = rpt + ans2;
            }
            else{
                cout << "NO SOLUTION\n";
                return 0;
            }

        }
    }

    cout << ans1;
    if(hasMidLetter) cout << midLetter;
    cout << ans2 << endl;

    return 0;
}
