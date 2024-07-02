#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];
    vector<ll> ways(x+1, 1e9);
    ways[0] = 0;
    for (ll i = 1; i <= x; i++){
        for (ll j = 0; j < n; j++){
            if(i - coins[j] >= 0) ways[i] = min(ways[i], ways[i - coins[j]] + 1);
        }
    }
    // If the value is 1e9 that means that the cell is never visited i.e the value is not possible
    cout << (ways[x] == 1e9 ? -1 : ways[x]) << endl;
    return 0;
}