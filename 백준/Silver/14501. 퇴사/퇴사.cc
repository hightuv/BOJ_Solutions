#include <iostream>
#define MAX 16
using namespace std;

int T[MAX];
int P[MAX];

int dp[MAX] = {0};

int N;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    int maximum = 0;

    for (int i = 0; i <= N; i++) {
        dp[i] = max(dp[i], maximum);

        if (T[i] + i <= N) {
            dp[T[i] + i] = max(dp[T[i] + i], dp[i] + P[i]);
        }

        maximum = max(maximum, dp[i]);
    }

    cout << maximum << '\n';

}