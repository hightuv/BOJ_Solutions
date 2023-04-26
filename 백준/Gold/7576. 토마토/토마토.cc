#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int N, M;
int storage[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init() {
    cin >> M >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> storage[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (storage[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
}

void bfs() {
    int r, c, nr, nc;

    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr > 0 && nr <= N && nc > 0 && nc <= M) {
                if (!visited[nr][nc] && storage[nr][nc] == 0) {
                    visited[nr][nc] = true; 
                    storage[nr][nc] = storage[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (storage[i][j] == 0) {
                return false;
            }
        }
    }
    
    return true;
}

int countDays() {
    int days = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (days < storage[i][j]) {
                days = storage[i][j];
            }
        }
    }

    return days;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    bfs();

    if (!check()) {
        cout << -1 << '\n';
        return 0;
    }

    int result = countDays();

    cout << result - 1 << '\n';    
}