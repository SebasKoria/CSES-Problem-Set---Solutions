#include <bits/stdc++.h>

using namespace std;

vector<string> chessboard(8);
vector<bool> occupiedColumn(8, false);
vector<bool> occupiedMainDiagonal(15, false);
vector<bool> occupiedSecondaryDiagonal(15, false);

int placeQueens(int row){
    int ans = 0;

    for(int i=0;i<8;i++){
        if(chessboard[row][i] == '*') continue;
        if(!occupiedColumn[i] && !occupiedMainDiagonal[row+i] && !occupiedSecondaryDiagonal[row-i+7]){
            if(row == 7) ans+= 1;
            else{
                occupiedColumn[i] = true;
                occupiedMainDiagonal[row+i] = true;
                occupiedSecondaryDiagonal[row-i+7] = true;
                ans += placeQueens(row+1);
                occupiedColumn[i] = false;
                occupiedMainDiagonal[row+i] = false;
                occupiedSecondaryDiagonal[row-i+7] = false;
            }
        }
    }

    return ans;
}

int main()
{
    for(int i=0;i<8;i++){
        cin >> chessboard[i];
    }

    cout << placeQueens(0) << endl;
    return 0;
}
