#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define MOD 1000000007

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >>  coins[i];
    vector<ll> ways(x + 1, 0);
    ways[0] = 1;

    for (ll i = 1; i<= x; i++){
        for(ll j = 0; j < n; j++){
            if (i - coins[j] >= 0) ways[i] = (ways[i] + ways[i - coins[j]]) % MOD;
        }
    }
    cout << ways[x] << endl;
    return 0;
}