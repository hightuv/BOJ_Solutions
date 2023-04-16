#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int N;

vector<int> graph[MAX];
bool visited[MAX];

vector<int> answer;
int order[MAX];

bool compare(int i, int j) {
    return order[i] < order[j];
}

void dfs(int v) {
    if (visited[v]) return;

    visited[v] = true;
    answer.push_back(v);

    for (auto i : graph[v]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
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
 
    vector<int> path(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> path[i];
        order[path[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }

    answer.push_back(0);

    if (path[1] == 1) {\
        dfs(1);
    }
    if (answer == path) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

}