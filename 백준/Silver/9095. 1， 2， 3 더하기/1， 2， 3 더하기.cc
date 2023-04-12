#include <iostream>
using namespace std;

int dp[12] = {0, 1, 2, 4};

int f(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }

    return dp[n] = f(n - 1) + f(n - 2) + f(n - 3);
}

int main() {
    int t;
    
    cin >> t;

    int n;

    while (t--) {
        cin >> n;

        cout << f(n) << '\n';
    }
}
