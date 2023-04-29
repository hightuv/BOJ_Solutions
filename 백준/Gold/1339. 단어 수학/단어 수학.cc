#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int alphabet[26]; // Number of Alphabet

bool compare(int i, int j) {
    return i > j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    string word;

    while (N--) {
        cin >> word;
        int p = 1;
        for (int i = word.length() -1; i >= 0; i--) {
            alphabet[word[i] - 'A'] += p;
            p *= 10;
        }
    }

    int num = 9;
    int result = 0;

    sort(alphabet, alphabet + 26, compare);

    for (int i = 0; i < 10; i++) { // 10 alphabets maximum in each word
        result += alphabet[i] * num;
        num -= 1;
    }

    cout << result << '\n';
}