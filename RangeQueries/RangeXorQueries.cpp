#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopEqual(i, a, b) for (int i = a; i <= b; i++)
# define LoopReverse(i, a, b) for (int i = a; i >= b; i--)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    ll maxN = pow(2, ceil(log2(n)));
    ll segmentTree[2 * maxN] = {0};
    Loop(i, 0, n) cin >> segmentTree[maxN + i];

    // Build the Segment Tree
    LoopReverse(i, maxN - 1, 1) segmentTree[i] = segmentTree[2 * i] ^ segmentTree[2 * i + 1];

    // Processing the Queries
    while (q--) {
        ll a, b; cin >> a >> b;

        a += maxN - 1;
        b += maxN - 1;
        ll res = 0;

        while (a <= b) {
            if (a % 2 == 1) res ^= segmentTree[a++];
            if (b % 2 == 0) res ^= segmentTree[b--];
            a /= 2;
            b /= 2;
        }

        cout << res << '\n';
    }
    return 0;
}