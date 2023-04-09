#include <iostream>
#define MAX 21
using namespace std;

int N, S;
int countSub = 0;

int arr[MAX];

void dfs(int depth, int sum) {
    if (depth == N) {
        if (sum == S) {
            countSub += 1;
        }
        return;
    }
    
    dfs(depth + 1, sum); // Exclude arr[depth]
    dfs(depth + 1, sum + arr[depth]); // Include arr[depth]
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    // Since the subarray must have at least 1 element
    if (S == 0) { // Exclude a subarray with 0 elements (When S is 0)
        countSub -= 1;
    }

    cout << countSub << '\n';
}