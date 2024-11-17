#include <iostream>

using namespace std;

long long binaryExponentiation(long long a, long long b, long long c){
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long temp = binaryExponentiation(a, b/2, c);
        return (temp * temp) % c;
    }
    else {
        long long temp = binaryExponentiation(a, b-1, c);
        return (temp * a) % c;
    }
}

int main()
{
    int n; cin >> n;
    cout << binaryExponentiation(2, n, (int)1e9+7) << endl;
    return 0;
}
