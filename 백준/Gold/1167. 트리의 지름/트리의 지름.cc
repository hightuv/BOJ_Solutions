#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int V;
int start;
int parameter = 0;

vector<pair<int, int>> tree[MAX];

bool visited[MAX];

void dfs(int x, int p) {
    visited[x] = true;

    if (parameter < p) {
        parameter = p;
        start = x;
    }

    int next, d;

    for (int i = 0; i < tree[x].size(); i++) {
        next = tree[x][i].first;
        d = tree[x][i].second;
        if (!visited[next]) { 
            dfs(next, p + d);
        }
    }
}

void init() {
    cin >> V;

    int from, to;
    int d;

    for (int i = 1; i <= V; i++) {
        cin >> from >> to;
        while (to != -1) {
            cin >> d;
            tree[from].push_back({to, d});
            cin >> to;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    
    dfs(1, 0);

    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }

    dfs(start, 0);

    cout << parameter << '\n';
}