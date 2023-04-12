#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int arr[MAX];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}