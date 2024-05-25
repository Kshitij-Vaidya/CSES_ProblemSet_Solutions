#include<iostream>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    else if (n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    else {
        for (ll i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (ll i =1; i <= n; i += 2) {
            cout << i << " ";
        }
    }
}