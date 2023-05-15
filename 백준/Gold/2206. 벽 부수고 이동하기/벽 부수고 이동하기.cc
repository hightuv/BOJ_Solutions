#include <iostream>
#include <string>
#include <queue>
#define MAX 1001
#define WALL '1'
#define EMPTY '0'
using namespace std;

int N, M;

char board[MAX][MAX];
bool visited[MAX][MAX][2];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(int sr, int sc) {
    visited[sr][sc][0] = true;

    queue<pair<pair<int, int>, pair<int, int>>> q; // row, column, broken wall, distance
    q.push({{sr, sc}, {0, 1}});

    int r, c, nr, nc;
    int b, d;

    while (!q.empty()) {
        r = q.front().first.first;
        c = q.front().first.second;
        b = q.front().second.first;
        d = q.front().second.second;
        q.pop();

        if (r == N && c == M) {
            return d;
        }

        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M) {
                if (board[nr][nc] == WALL && b == 0) {
                    visited[nr][nc][b + 1] = true;
                    q.push({{nr, nc}, {b + 1, d + 1}});
                }

                else if (board[nr][nc] == EMPTY && !visited[nr][nc][b]) {
                    visited[nr][nc][b] = true;
                    q.push({{nr, nc}, {b, d + 1}});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j + 1] = s[j];
        }
    }   

    cout << bfs(1, 1) << '\n';
}