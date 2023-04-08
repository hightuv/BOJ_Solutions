#include <iostream>
#include <climits>
#define MAX 10
#define INT long long int
using namespace std;

bool visited[MAX]; // 0 ~ 9

char comp[MAX]; // 2 <= k <= 9
int k;

int arr[MAX];

INT maximum = LONG_LONG_MIN;
INT minimum = LONG_LONG_MAX;

INT power(int base, int n) {
    INT x = 1;

    while (n--) {
        x *= base;
    }

    return x;
}

INT toLong() {
    int e = k;

    INT result = 0;
    for (int i = 0; i < k + 1; i++) {
        result += arr[i] * power(10, e--);
    }

    return result;
}

void dfs(int count) {
    if (count == k + 1) {
        INT tmp = toLong();
        if (maximum < tmp) {
            maximum = tmp;
        }
        if (minimum > tmp) {
            minimum = tmp;
        }
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            if (count != 0) {
                if (comp[count - 1] == '<') {
                    if (arr[count - 1] > i) {
                        continue;
                    }
                }
                else if (comp[count - 1] == '>') {
                    if (arr[count - 1] < i) {
                        continue;
                    }
                }
            }

            visited[i] = true;
            arr[count] = i;
            dfs(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> comp[i];
    }

    dfs(0);

    cout.width(k + 1);
    cout.fill('0');
    cout << maximum << '\n';

    cout.width(k + 1);
    cout.fill('0');
    cout << minimum << '\n';
}
