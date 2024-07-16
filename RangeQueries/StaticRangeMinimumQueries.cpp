#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <climits>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define LoopEqual(i, a, b) for (int i = a; i <= b; i++)
const int LOG = 20;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    ll sparseTable[n][LOG];
    Loop(i, 0, n) cin >> sparseTable[i][0];

    Loop(i, 1, LOG) {
        LoopEqual(j, 0, n - (1 << i)) {
            // j is the starting index of the range
            // i is the length of the range (2^i)
            sparseTable[j][i] = min(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
        }
    }

    while (q--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        ll k = log2(b - a + 1); 

        cout << min(sparseTable[a][k], sparseTable[b - (1 << k) + 1][k]) << '\n';
    }
    return 0;
}

