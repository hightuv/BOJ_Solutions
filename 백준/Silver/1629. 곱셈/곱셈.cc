#include <iostream>
using namespace std;

long long A, B, C;

long long power(long long base, long long exp) {
    if (exp == 0) {
        return 1;
    }
    
    if (exp == 1) {
        return base % C;
    }

    long long tmp = power(base, exp / 2) % C;

    if (exp % 2 == 0) {
        return tmp * tmp % C;
    }
    else {
        return tmp * tmp % C * base % C;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << power(A, B) << '\n';
}