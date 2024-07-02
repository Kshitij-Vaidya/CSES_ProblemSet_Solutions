#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // Sort the machines from the fastest to the slowest
    // Upper limit on the time taken will be fastest machine * no of products
    ll l = 1, r = (*min_element(a.begin(), a.end())) * t;
    ll ans;

    while (l <= r){
        ll mid = (l + r) / 2;
        ll products = 0;
        for (ll i = 0; i < n; i++) products += (mid / a[i]);
        if (products >= t){
            ans = mid;
            // If the no of products is greater than or equal to t, then we can try to reduce the time taken
            r = mid - 1;    
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
