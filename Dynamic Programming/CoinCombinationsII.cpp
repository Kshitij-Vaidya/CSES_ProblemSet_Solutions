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

    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for(ll i = 0; i < n; i++) cin >> coins[i];

    vector<ll> ways(x+1, 0);
    ways[0] = 1; // 1 way to make 0 - select no coins

    for (ll i = 0; i < n; i++){
        // Select the ith coin and calculate the ways to make the sum
        for (ll j = coins[i]; j <= x; j++){
            ways[j] = (ways[j] + ways[j - coins[i]]) % MOD;
        }
    }
    cout << ways[x] << endl;
    return 0;
}