#include <iostream>
#include <vector>
#include <queue>
#define MAX 3001
using namespace std;

int N;
int start;

vector<int> graph[MAX];
bool visited[MAX];
bool isInCycle[MAX];

int dist[MAX]; // Distance

bool dfs(int x, int prev) { // Find Cycle
    if (visited[x]) {
        if (x == start) {
            return isInCycle[x] = true;
        }
        return false;
    }

    visited[x] = true;
    
    int next;

    for (int i = 0; i < graph[x].size(); i++) {
        next = graph[x][i];
        if (prev != next) { // Prevent going backwards (B->A - A->B)
            if (dfs(next, x)) {
                return isInCycle[x] = true;
            }
        }
    }

    visited[x] = false;

    return false;
}

void bfs() {
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++) {
        if (isInCycle[i]) {
            visited[i] = true;
            q.push({i, 0});
        }
        else {
            visited[i] = false;
        }
    }

    int x, d;
    int next;

    while (!q.empty()) {
        x = q.front().first;
        d = q.front().second;
        q.pop();
        
        visited[x] = true;

        for (int i = 0; i < graph[x].size(); i++) {
            next = graph[x][i];
            if (visited[next]) {
                continue;
            }
            dist[next] = d + 1;
            q.push({next, d + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int u, v;

    for (int i = 0; i < N; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        start = i;
        if (dfs(start, -1)) {
            break;
        }
    }

    bfs();

    for (int i = 1; i <= N; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}