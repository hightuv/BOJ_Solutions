#include <iostream>
#include <climits>
#define MAX 21
using namespace std;

int N;

int S[MAX][MAX];

bool visited[MAX];

int minimum = INT_MAX;

int calculateDiff() {
    int startTotal = 0;
    int linkTotal = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (visited[i] == true && visited[j] == true) {
                startTotal += S[i][j];
            }
            else if (visited[i] == false && visited[j] == false) {
                linkTotal += S[i][j];
            }
        }
    }

    int diff = abs(startTotal - linkTotal);

    return diff;
}

void dfs(int count, int next) {
    int diff = calculateDiff();

    if (minimum > diff) {
        minimum = diff;
    }

    if (count == N / 2) {
        return;
    }

    for (int i = next; i <= N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(count + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 1);

    cout << minimum << '\n';
}