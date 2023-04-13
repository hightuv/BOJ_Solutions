#include <iostream>
#include <vector>
#define MAX 20001
#define UNVISITED 0
#define RED 1
#define BLUE 2
using namespace std;

int K;
int V, E;

vector<int> graph[MAX];
int visited[MAX];

void init() {
    for (int i = 1; i <= V; i++) {
        graph[i].clear();
        visited[i] = UNVISITED;
    }
}

void dfs(int start) {
    if (!visited[start]) {
        visited[start] = RED;
    }

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            if (visited[start] == RED) {
                visited[next] = BLUE;
            }
            else {
                visited[next] = RED;
            }
            dfs(next);
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) { // Adjacent nodes exist in the same set
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int u, v;
    
    cin >> K;

    while (K--) {
        cin >> V >> E;

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            dfs(i);
        }

        if (isBipartiteGraph()) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

        init();
    }
}