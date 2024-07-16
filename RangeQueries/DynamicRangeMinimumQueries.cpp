#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopEqual(i, a, b) for (int i = a; i <= b; i++)
# define LoopReverse(i, a, b) for (int i = a; i >= b; i--)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    // Processing Dynamic Queries by building a Segment Tree
    ll maxN = pow(2, ceil(log2(n)));
    ll segmentTree[2 * maxN] = {0};
    // Input the original array
    Loop(i, 0, n) cin >> segmentTree[maxN + i];

    // Build the Segment Tree
    LoopReverse(i, maxN - 1, 1) segmentTree[i] = min(segmentTree[2 * i], segmentTree[2 * i + 1]);

    // Processing the queries
    while (q--) {
        ll type, a, b; cin >> type >> a >> b;
        // Update Query
        if (type == 1) {
            a += maxN - 1;
            segmentTree[a] = b;
            while (a > 1) {
                a /= 2;
                segmentTree[a] = min(segmentTree[2 * a], segmentTree[2 * a + 1]);
            }
        }
        // Query
        else {
            a += maxN - 1;
            b += maxN - 1;
            ll res = INT_MAX;
            while (a <= b) {
                if (a % 2 == 1) res = min(res, segmentTree[a++]); // Right Child
                if (b % 2 == 0) res = min(res, segmentTree[b--]); // Left Child
                a /= 2;
                b /= 2;
            }
            cout << res << '\n';
        }
    }
}