#include <iostream>
#include <string>
#define MAX 101
using namespace std;

int N;
char picture[MAX][MAX];
bool visited[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs(int r, int c) {
    visited[r][c] = true;

    int nr, nc;

    for (int i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (!visited[nr][nc]) {
                if (picture[nr][nc] == picture[r][c]) {
                    dfs(nr, nc);
                }
            }
        }
    }
}

int main() {
    cin >> N;

    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            picture[i][j] = s[j];
        }
    }

    int nonWeak = 0;
    int weak = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                nonWeak += 1;
            }
        }
    }

    init();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (picture[i][j] == 'G') {
                picture[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                weak += 1;
            }
        }
    }

    cout << nonWeak << ' ' << weak << '\n';
}