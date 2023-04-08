#include <iostream>
using namespace std;

char S[11][11];
char input[101];

int A[11];

int n;

bool found = false;

bool check(int idx) {
    int tmp;
    char sign;

    for (int i = 0; i < idx; i++) {
        tmp = 0;
        
        for (int j = i; j < idx; j++) {
            tmp += A[j];
        
            if (tmp < 0) {
                sign = '-';
            }
            else if (tmp == 0) {
                sign = '0';
            }
            else  {
                sign = '+';
            }

            if (S[i][j] != sign) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int count) {
    if (count == n) {
        for (int i = 0; i < n; i++) {
            cout << A[i] << ' ';
        }
        cout << '\n';
        exit(0);
    }

    for (int i = -10; i <= 10; i++) {
        A[count] = i;
        if (check(count + 1)) {
            dfs(count + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cin >> input;

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            S[i][j] = input[k++];
        }
    }

    dfs(0);   
}