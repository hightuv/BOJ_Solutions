#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#define TIME 0
#define PREV 1
#define MAX 100001
using namespace std;

int dp[MAX][2]; // 0 - TIME, 1 - PREV
bool visited[MAX];

int N, K;

void init() {
    for (int i = 0; i < MAX; i++) {
        dp[i][TIME] = INT_MAX;
        dp[i][PREV] = -1;
    }
}

void printPath() {
    stack<int> s;
    s.push(K);

    int v = dp[K][PREV];

    while (v != -1) {
        s.push(v);
        v = dp[v][PREV];
    }

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    
    cout << '\n';
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dp[start][TIME] = 0;
    dp[start][PREV] = -1;
    visited[start] = true;

    int v;

    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (v == K) {
            break;
        }

        int nv[] = {v * 2, v - 1, v + 1};

        for (int i = 0; i < 3; i++) {
            if (nv[i] >= MAX) {
                continue;
            }
            
            if (!visited[nv[i]]) {
                if (i != 0) {
                    if (dp[v][TIME] + 1 < dp[nv[i]][TIME]) {
                        visited[nv[i]] = true;
                        dp[nv[i]][TIME] = dp[v][TIME] + 1;
                        dp[nv[i]][PREV] = v;
                        q.push(nv[i]);
                    }
                }
                else {
                    if (dp[v][TIME] <= dp[nv[i]][TIME]) {
                        visited[nv[i]] = true;
                        dp[nv[i]][TIME] = dp[v][TIME];
                        dp[nv[i]][PREV] = v;
                        q.push(nv[i]);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    init();

    bfs(N);

    cout << dp[K][TIME] << '\n';

    // printPath();
}