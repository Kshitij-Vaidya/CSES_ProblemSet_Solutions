#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopEqual(i, a, b) for (int i = a; i <= b; i++)

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
    // Processing Dynamic Queries by building a Binary Indexed Tree
    ll binaryIndexTree[n + 1] = {0};
    LoopEqual(i, 1, n) {
        ll val; cin >> val;
        update(binaryIndexTree, n, i, val);
    }

    // Processing the queries
    while (q--) {
        ll type, a, b; cin >> type >> a >> b;
        // Update Query
        if (type == 1) update(binaryIndexTree, n, a, b - getSum(binaryIndexTree, a) + getSum(binaryIndexTree, a - 1));
        else cout << getSum(binaryIndexTree, b) - getSum(binaryIndexTree, a - 1) << '\n';
    }
    return 0;
}