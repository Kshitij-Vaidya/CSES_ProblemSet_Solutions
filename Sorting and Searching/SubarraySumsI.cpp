#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll left = 0, right = 1, sum = a[0], count = 0;
    while (right <= n){
        if (sum == x) count++;
        if (sum < x){
            if (right == n) break;
            sum += a[right];
            right++;
        }
        else{
            sum -= a[left];
            left++;
        }
    }
    cout << count << endl;
}