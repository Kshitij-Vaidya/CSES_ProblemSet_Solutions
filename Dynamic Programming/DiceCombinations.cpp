#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define MOD 1000000007

int main(){
    ll n; cin >> n;
    vector<ll> ways(n + 1, 0);

    ways[0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= 6; j++){
            if (i - j >= 0){
                ways[i] += ways[i - j];
                ways[i] %= MOD;
            }
        }
    }
    cout << ways[n] << endl;
    return 0;
}