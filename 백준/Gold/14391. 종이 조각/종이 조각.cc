#include <iostream>
#include <climits>
#define MAX 5
using namespace std;

int N, M;
int table[MAX][MAX];
bool visited[MAX][MAX]; // true - horizontal, false - perpendicular

int maximum = INT_MIN;

int sum() {
    int result = 0;
    int tmp;

    // Add Horizontal Elements
    for (int r = 0; r < N; r++) {
        tmp = 0;
        for (int c = 0; c < M; c++) {
            if (visited[r][c]) {
                tmp *= 10;
                tmp += table[r][c];
            }
            else {
                result += tmp;
                tmp = 0;
            }
        }
        result += tmp;
    }

    // Add Perpendicular Elements
    for (int c = 0; c < M; c++) {
        tmp = 0;
        for (int r = 0; r < N; r++) {
            if (!visited[r][c]) {
                tmp *= 10;
                tmp += table[r][c];
            }
            else {
                result += tmp;
                tmp = 0;
            }
        }
        result += tmp;
    }

    return result;
}

void dfs(int row, int col) {
    if (row == N) { // reached to the end of the table
        maximum = max(maximum, sum());
        return;
    }
    
    else if (col == M) {
        dfs(row + 1, 0); // start dfs from next row
        return;
    }

    visited[row][col] = true;
    dfs(row, col + 1);
    
    visited[row][col] = false;
    dfs(row, col + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    char s[MAX];

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            table[i][j] = s[j] - '0';
        }
    }

    dfs(0, 0);

    cout << maximum << '\n';
}