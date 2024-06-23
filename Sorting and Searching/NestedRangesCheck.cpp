#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Data
{
    ll start, end, index;
    bool operator<(const Data &a) const
    {
        if (start == a.start)
            return end > a.end;
        return start < a.start;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<Data> v(n);
    // Read in the values
    for(ll i = 0; i < n; i++){
        cin >> v[i].start >> v[i].end;
        v[i].index = i;
    }
    sort(v.begin(), v.end());

    vector<int> contains(n, 0); vector<int> contained(n, 0);
    ll max_right = 1e18;
    for (ll i = n - 1; i >= 0; i--){
        if (v[i].end >= max_right){
            contains[v[i].index] = 1;
        }
        max_right = min(max_right, v[i].end);
    }

    ll min_right = 0;
    for (ll i = 0; i < n; i++){
        if (v[i].end <= min_right){
            contained[v[i].index] = 1;
        }
        min_right = max(min_right, v[i].end);
    }

    for (ll i = 0; i < n; i++){
        cout << contains[i] << " ";
    }
    cout << '\n';
    for (ll i = 0; i < n; i++){
        cout << contained[i] << " ";
    }
    return 0;
}