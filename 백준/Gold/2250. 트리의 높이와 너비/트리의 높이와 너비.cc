#include <iostream>
#include <vector>
#define LEFT 0
#define RIGHT 1
#define MAX 10001
using namespace std;

int N;
int tree[MAX][2];
int column[MAX];
int parent[MAX];
int totalLevel = 0;
int col = 1;
vector<vector<int>> level;

void init() {
    for (int i = 0; i < MAX; i++) {
        parent[i] = -1;
        level.push_back(vector<int> ());
    }

    int node, left, right;

    for (int i = 0; i < N; i++) {
        cin >> node >> left >> right;
        tree[node][0] = left;
        tree[node][1] = right;

        if (left != -1) {
            parent[left] = node;
        }
        
        if (right != -1) {
            parent[right] = node;
        }
    }    
}

void inorder(int root, int l) {
    if (root == -1) {
        return;
    }

    int left = tree[root][LEFT];
    int right = tree[root][RIGHT];

    inorder(left, l + 1);

    level[l].push_back(root);
    totalLevel = max(totalLevel, l);
    column[root] = col++;

    inorder(right, l + 1);
}

int findRoot() {
    int root;

    for (int i = 1; i <= N; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    return root;
}

int getWidth(int l) {

    return column[level[l].back()] - column[level[l].front()] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    init();
    
    int root = findRoot();
    inorder(root, 0);

    int maxWidth = 1;
    int maxLevel = 0;

    int w;
    for (int i = 1; i <= totalLevel; i++) {
        w = getWidth(i);
        if (maxWidth < w) {
            maxWidth = w;
            maxLevel = i;
        }
    }

    cout << maxLevel + 1 << ' ' << maxWidth << '\n';
}