#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> ways(n + 1, 1e9);
    ways[0] = 0;
    for (int i = 1; i <= n; i++){
        ll temp = i;
        while (temp){
            ways[i] = min(ways[i], ways[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }
    cout << ways[n] << endl;
    return 0;
}