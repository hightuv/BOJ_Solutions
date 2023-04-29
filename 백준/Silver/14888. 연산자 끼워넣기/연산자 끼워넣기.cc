#include <iostream>
#include <climits>
#define MAX 12
using namespace std;

int N;
int maximum = INT_MIN;
int minimum = INT_MAX;

int operators[4]; // 0 - add, 1 - substract, 2 - multiply, 3 - divide
int operands[MAX];

void dfs(int result, int usedOperands) {
    if (usedOperands == N) {
        if (maximum < result) {
            maximum = result;
        }
        if (minimum > result) {
            minimum = result;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operators[i] > 0) {
            operators[i] -= 1;

            if (i == 0) {
                dfs(result + operands[usedOperands], usedOperands + 1);
            }
            else if (i == 1) {
                dfs(result - operands[usedOperands], usedOperands + 1);
            }
            else if (i == 2) {
                dfs(result * operands[usedOperands], usedOperands + 1);
            }
            else if (i == 3) {
                dfs(result / operands[usedOperands], usedOperands + 1);
            }
            
            operators[i] += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> operands[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    dfs(operands[0], 1);

    cout << maximum << '\n';
    cout << minimum << '\n';
}