#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define Loopr(i, a, b) for (int i = a; i >= b; i--)

// Binary Indexed Tree -  Function returns the sum of the range [1, index]
ll getSum(ll binaryIndexTree[], ll index) {
    ll sum = 0;
    while (index > 0) {
        sum += binaryIndexTree[index];
        index -= index & -index; // Operation finds the LSB of index 
    }
    return sum;
}

// Binary Indexed Tree - Function updates the value at index to val
void update(ll binaryIndexTree[], ll n, ll index, ll val) {
    while (index <= n) {
        binaryIndexTree[index] += val;
        index += index & -index;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    ll binaryIndexTree[n + 1] = {0};
    pair<ll, ll> temp = {0, 0};
    Loop(i, 1, n + 1) {
        cin >> temp.first;
        update(binaryIndexTree, n, i, temp.first - temp.second);
        temp.second = temp.first;
    }

    Loop(i, 0, q) {
        ll type; cin >> type;
        if (type == 1) {
            ll l, r, val; cin >> l >> r >> val;
            update(binaryIndexTree, n, l, val);
            update(binaryIndexTree, n, r + 1, -val);
        } else {
            ll index; cin >> index;
            cout << getSum(binaryIndexTree, index) << '\n';
        }
    }
    return 0;
}