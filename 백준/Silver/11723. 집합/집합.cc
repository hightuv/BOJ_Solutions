#include <iostream>
#include <string>
using namespace std;

// int -> 4 Bytes = 32 Bits

int M, S;
string cmd;
int x; // 1 <= x <= 20 (Can represent using 32 bits)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;

    while (M--) {
        cin >> cmd;

        if (cmd == "all") {
            S = (1 << 21) - 1;
        }
        else if (cmd == "empty") {
            S = 0;
        }
        else {
            cin >> x;

            if (cmd == "add") {
                S |= (1 << x);
            }
            else if (cmd == "remove") {
                S &= ~(1 << x);
            }
            else if (cmd == "check") {
                cout << ((S & (1 << x)) > 0) << '\n';
            }
            else if (cmd == "toggle") {
                S ^= (1 << x);
            }
        }
    }
}