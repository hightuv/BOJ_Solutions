#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

int N, M;
vector<int> F[MAX];
bool visited[MAX];

void dfs(int depth, int next) {
    if (depth == 4) { // Condition : A-B, B-C, C-D, D-E -> Total 4 Friendships
        cout << 1 << '\n';
        exit(0);
    }
    
    for (int i = 0; i < F[next].size(); i++) {
        int tmp = F[next][i];
        if (!visited[tmp]) {
            visited[tmp] = true;
            dfs(depth + 1, tmp);
            visited[tmp] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int a, b;

    while (M--) {
        cin >> a >> b;
        F[a].push_back(b);
        F[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(0, i);
        visited[i] = false;
    }

    cout << 0 << '\n';
}