#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int n;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];

int parameter = 0;
int farthest;

void dfs(int node, int p) {
    visited[node] = true;

    if (parameter < p) {
        parameter = p;
        farthest = node;
    }

    int next, w;

    for (int i = 0; i < tree[node].size(); i++) {
        next = tree[node][i].first;
        w = tree[node][i].second;

        if (!visited[next]) {
            dfs(next, p + w);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int u, v, weight;

    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v >> weight;
        tree[u].push_back({v, weight});
        tree[v].push_back({u, weight});
    }

    int root = 1;

    dfs(root, 0);

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    dfs(farthest, 0);

    cout << parameter << '\n';
}