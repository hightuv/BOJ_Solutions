#include <iostream>
#include <queue>
#include <climits>
#define MAX 101
#define OCEAN 0
#define LAND -1
using namespace std;

int N;
int graph[MAX][MAX];
bool visited[MAX][MAX];


int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs(int r, int c, int continent) {
    visited[r][c] = true;
    graph[r][c] = continent;

    int nr, nc;
    for (int i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];

        if (nr > 0 && nr <= N && nc > 0 && nc <= N) {
            if (graph[nr][nc] == LAND && !visited[nr][nc]) {
                dfs(nr, nc, continent);
            }
        }
    }
}

int bfs(int continent) {
    queue<pair<int, int>> q;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == continent) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int length = 0;
    int r, c;
    int nr, nc;

    int s;

    while (!q.empty()) {
        s = q.size();

        for (int i = 0; i < s; i++) {
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                nr = r + dr[j];
                nc = c + dc[j];

                if (nr > 0 && nr <= N && nc > 0 && nc <= N) {
                    if (graph[nr][nc] != OCEAN && graph[nr][nc] != continent) {
                        return length;
                    }
                    if (graph[nr][nc] == OCEAN && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        length += 1;
    }

    return INT_MAX; // If bfs worked well, it's not going to come to this line
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 1) {
                graph[i][j] = LAND;
            }
        }
    }

    int continent = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j] == LAND && !visited[i][j]) {
                dfs(i, j, continent);
                continent += 1;
            }
        }
    }

    int minimum = INT_MAX;

    for (int i = 1; i < continent; i++) {
        init();
        minimum = min(minimum, bfs(i));
    }

    cout << minimum << '\n';    
}