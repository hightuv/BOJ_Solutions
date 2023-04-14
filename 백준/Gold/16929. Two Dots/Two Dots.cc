#include <iostream>
#define MAX 51
using namespace std;

int N, M;
int sr, sc; // Start Row, Start Column

char table[MAX][MAX];
bool visited[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int count) {
    if (visited[r][c]) {
        if (r == sr && c == sc && count > 4) {
            cout << "Yes" << '\n';
            exit(0);
        }
        return;
    }
    
    visited[r][c] = true;

    int nr, nc;

    for (int i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            continue;
        }
        else if (table[r][c] != table[nr][nc]) {
            continue;
        }
        
        dfs(nr, nc, count + 1);
    }

    visited[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> table[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sr = i;
            sc = j;
            dfs(sr, sc, 1);
        }
    }

    cout << "No" << '\n';
}