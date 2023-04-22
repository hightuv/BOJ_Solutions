#include <iostream>
#include <queue>
#include <climits>
#define MAX 101
#define EMPTY '0'
#define WALL '1'
using namespace std;

int M, N;
char board[MAX][MAX];
int count[MAX][MAX];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

void init() {
    char s[MAX];
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j + 1] = s[j];
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            count[i][j] = INT_MAX;
        }
    }
}

void bfs(int sr, int sc) {
    queue<pair<int, int>> q;

    count[sr][sc] = 0;
    q.push({sr, sc});

    int r, c, nr, nc;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
                if (board[nr][nc] == WALL) {
                    if (count[r][c] + 1 < count[nr][nc]) {
                        count[nr][nc] = count[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
                else {
                    if (count[r][c] < count[nr][nc]) {
                        count[nr][nc] = count[r][c];
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    init();

    bfs(1, 1);

    cout << count[N][M] << '\n';
}