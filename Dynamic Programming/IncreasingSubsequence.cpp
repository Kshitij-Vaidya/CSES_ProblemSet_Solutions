#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
# define Loop(i, a, b) for (ll i = a; i < b; i++)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> nums;

    Loop(i, 0, n) {
        ll num; cin >> num;
        auto it = lower_bound(nums.begin(), nums.end(), num);
        if (it == nums.end()) nums.push_back(num);
        // Otherwise, we replace the number at that position
        else *it = num;
    }
    cout << '\n' << nums.size() << '\n';
    return 0;
}