#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define MOD 1000000007

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];
    vector<vector<ll>> ways(n + 1, vector<ll>(n + 1, 0));
    ways[1][1] = (grid[0][0] == '.');
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            if (grid[i - 1][j - 1] == '*') continue;
            else ways[i][j] = (ways[i][j] + ways[i - 1][j] + ways[i][j - 1]) % MOD;
        }
    }
    cout << ways[n][n] << endl;
    return 0;
}