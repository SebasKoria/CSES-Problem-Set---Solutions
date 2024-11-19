#include <bits/stdc++.h>

using namespace std;

vector<string> combinations;

void allCombinations(string prev, string curr){
    if(curr.size() == 1){
        combinations.push_back(prev + curr);
        return;
    }

    set<char> used;

    for(int i=0;i<curr.size();i++){
        char newChar = curr.back();
        curr.pop_back();
        if(used.find(newChar) == used.end()){
            allCombinations(prev + newChar, curr);
            used.insert(newChar);
        }
        curr = newChar + curr;
    }
}

int main()
{
    string s; cin >> s;
    allCombinations("", s);

    sort(combinations.begin(), combinations.end());
    cout << combinations.size() << endl;
    for(int i=0;i<combinations.size();i++) cout << combinations[i] << endl;

    return 0;
}
