#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> prefixSum;
    ll sum = 0, count = 0;

    for (ll i = 0; i < n; i++){
        sum += a[i];
        if (prefixSum.find(sum - x) != prefixSum.end()) count += prefixSum[sum - x];
        if (sum == x) count++;
        prefixSum[sum]++;
    }
    cout << count << endl;
    return 0;
}