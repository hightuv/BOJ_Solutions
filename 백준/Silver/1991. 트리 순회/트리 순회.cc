#include <iostream>
#define MAX 27
#define LEFT 0
#define RIGHT 1
using namespace std;

int tree[MAX][2];

void preorder(int n) {
    if (n == -1) {
        return;
    }
    cout << (char)(n + 'A');
    preorder(tree[n][LEFT]);
    preorder(tree[n][RIGHT]);
}

void inorder(int n) {
    if (n == -1) {
        return;
    }
    inorder(tree[n][LEFT]);
    cout << (char)(n + 'A');
    inorder(tree[n][RIGHT]);
}

void postorder(int n) {
    if (n == -1) {
        return;
    }
    postorder(tree[n][LEFT]);
    postorder(tree[n][RIGHT]);
    cout << (char)(n + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    char node, left, right;

    for (int i = 0; i < N; i++) {
        cin >> node >> left >> right;
        node -= 'A';

        if (left == '.') {
            tree[node][LEFT] = -1;
        }
        else {
            left -= 'A';
            tree[node][LEFT] = left;
        }

        if (right == '.') {
            tree[node][RIGHT] = -1;
        }
        else {
            right -= 'A';
            tree[node][RIGHT] = right;
        }
    }

    // 0 -> 'A'
    preorder(0);
    cout << '\n';

    inorder(0);
    cout << '\n';

    postorder(0);
    cout << '\n';
}