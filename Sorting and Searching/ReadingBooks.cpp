#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

int main(){
    ll n; cin >> n;
    vector<ll> times(n);
    for (ll i = 0; i < n; i++) cin >> times[i];

    sort(times.begin(), times.end());
    ll smallerSum = accumulate(times.begin(), times.end() - 1, 0LL);
    ll largest = times.back();

    if (smallerSum <= largest) cout << 2 * largest << endl;
    else cout << smallerSum + largest << endl;
    return 0;
}