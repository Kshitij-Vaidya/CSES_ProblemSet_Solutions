#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> coins(n);
    Loop(i, 0, n) cin >> coins[i];
    // The maximum sum of coins is the sum of all coins
    ll sum = accumulate(coins.begin(), coins.end(), 0LL);
    vector<vector<bool>> sums(n + 1, vector<bool>(sum + 1, false));
    sums[0][0] = true;
    Loop(i, 1, n + 1){
        Loop(j, 0, sum + 1){
            sums[i][j] = sums[i - 1][j];
            if (j >= coins[i - 1]) sums[i][j] = sums[i][j] || sums[i - 1][j - coins[i - 1]];
        }
    } 
    vector<ll> possible;
    Loop(i, 1, sum + 1) if (sums[n][i]) possible.push_back(i);
    cout << possible.size() << '\n';
    for (ll i : possible) cout << i << ' ';
    return 0;
}