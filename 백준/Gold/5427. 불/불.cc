#include <iostream>
#include <climits>
#include <string>
#include <queue>
#define MAX 1001
#define WALL '#'
#define SPACE '.'
#define FIRE '*'
#define START '@'
using namespace std;

int t;
int w, h;
char board[MAX][MAX];
bool visited[MAX][MAX];
int fireTime[MAX][MAX];
int time[MAX][MAX];
int minimum = INT_MAX;

queue<pair<int, int>> qFire;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            visited[i][j] = false;
        }
    }
}

void bfs() {
    int r, c, nr, nc;
    
    while (!qFire.empty()) {
        r = qFire.front().first;
        c = qFire.front().second;
        qFire.pop();
        
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                if (!visited[nr][nc] && board[nr][nc] == SPACE) {
                    visited[nr][nc] = true;
                    fireTime[nr][nc] = min(fireTime[nr][nc], fireTime[r][c] + 1);
                    qFire.push({nr, nc});
                }
            }
        }
    }
}

bool isExit(int r, int c) {
    if (r == 0 && board[r][c] == SPACE) {
        return true;
    }
    else if (r == h - 1 && board[r][c] == SPACE) {
        return true;
    }

    if (c == 0 && board[r][c] == SPACE) {
        return true;
    }
    else if (c == w - 1 && board[r][c] == SPACE) {
        return true;
    }

    return false;
}

void findPath(int sr, int sc) {
    
    queue<pair<int, int>> q;
    q.push({sr, sc});

    int r, c, nr, nc;

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        if (isExit(r, c)) {
            minimum = min(minimum, time[r][c] + 1);
        }
        
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                if (!visited[nr][nc] && board[nr][nc] == SPACE) {
                    if (time[r][c] + 1 < fireTime[nr][nc]) {
                        if (time[nr][nc] <= time[r][c] + 1) {
                            continue;
                        }
                        time[nr][nc] = time[r][c] + 1;
                        visited[nr][nc] = true;
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

    cin >> t;

    string s;

    while (t--) {
        
        cin >> w >> h;

        int sr, sc;

        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                fireTime[i][j] = INT_MAX;
                time[i][j] = INT_MAX;
                
                board[i][j] = s[j];

                if (board[i][j] == START) {
                    sr = i;
                    sc = j;
                    time[i][j] = 0;
                    board[i][j] = SPACE;
                }
                
                if (board[i][j] == FIRE) {
                    fireTime[i][j] = 0;
                    visited[i][j] = true;
                    qFire.push({i, j});
                }
            }
        }

        bfs();

        init();

        visited[sr][sc] = true;
        findPath(sr, sc);

        init();

        if (minimum == INT_MAX) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            cout << minimum << '\n';
        }

        minimum = INT_MAX;
    }
}