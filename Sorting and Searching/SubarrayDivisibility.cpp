#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    map<ll, ll> remainders;
    remainders[0] = 1; 
    ll remainder = 0, count = 0;
    for (ll i = 0; i < n; i++){
        // N added to avoid negative remainders
        remainder = ((remainder + a[i]) % n + n) % n;
        count += remainders[remainder]; // Look for smaller subarrays that are divisible by n
        // If such subarrays are found, then the subarray between them is divisible by n
        remainders[remainder]++;
    }
    cout << count << '\n';
    return 0;
}