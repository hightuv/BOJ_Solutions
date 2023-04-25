#include <iostream>
#define MAX 16
using namespace std;

int N;
int col[MAX];
int result = 0;

bool isValid(int row) {
    for (int i = 1; i < row; i++) {
        if (col[row] == col[i] || abs(col[row] - col[i]) == row - i) {
            return false;
        }
    }
    return true;
}

void nqueens(int row) {
    if (row == N + 1) {
        result += 1;
        return;
    }

    for (int i = 1; i <= N; i++) {
        col[row] = i;
        if (isValid(row)) {
            nqueens(row + 1);
        }
        col[row] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    nqueens(1);
    
    cout << result << '\n';
}