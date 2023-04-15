#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;
vector<int> graph[MAX];
bool visited[MAX];
int inputOrder[MAX];
int visitOrder[MAX];

bool compare(int i, int j) {
    return visitOrder[i] < visitOrder[j];
}

bool bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    int idx = 2;

    int x, next;

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (int i = 0; i < graph[x].size(); i++) {
            next = graph[x][i];
            if (!visited[next]) {
                if (inputOrder[idx] != next) {
                    return false;
                }
                visited[next] = true;
                q.push(next);
                idx += 1;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int u, v;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int t;
    for (int i = 1; i <= N; i++) {
        cin >> t;
        visitOrder[t] = i;
        inputOrder[i] = t;
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }    

    cout << bfs(1) << '\n';    
}