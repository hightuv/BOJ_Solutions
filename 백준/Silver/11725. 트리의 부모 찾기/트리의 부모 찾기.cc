#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N;
vector<int> tree[MAX];
int p[MAX];

void dfs(int node) {
    int next;
    for (int i = 0; i < tree[node].size(); i++) {
        next = tree[node][i];
        if (p[next] == 0) {
            p[next] = node;
            dfs(next);
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
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << p[i] << '\n';
    }
}