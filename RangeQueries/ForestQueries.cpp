#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
# define Loop(i, a, b) for (int i = a; i < b; i++)
# define Loopr(i, a, b) for (int i = a; i >= b; i--)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q; cin >> n >> q;
    vector<vector<ll>> forest(n + 1, vector<ll>(n + 1, 0));
    Loop(i, 1, n + 1) {
        Loop(j, 1, n + 1) {
            char c; cin >> c;
            forest[i][j] = (c == '*');
        }
    }

    // Updating the forest in-place to a Prefix Sum array
    Loop(i, 1, n + 1) {
        Loop(j, 1, n + 1) {
            forest[i][j] += forest[i - 1][j] + forest[i][j - 1] - forest[i - 1][j - 1];
        }
    }

    while (q--) {
        ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << forest[y2][x2] - forest[y1 - 1][x2] - forest[y2][x1 - 1] + forest[y1 - 1][x1 - 1] << '\n';
    }
    return 0;
}