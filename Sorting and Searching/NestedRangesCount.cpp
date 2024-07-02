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

    vector<int> contains(n); vector<int> contained(n);
    ordered_set<pair<ll, ll>> s;

    sort(v.begin(), v.end());

    for (ll i = 0; i < n; i++){
        s.insert({v[i].end, -1 * i});
        contained[v[i].index] = s.size() - 1 - s.order_of_key({v[i].end, -1 * i});
    }

    s.clear();

    for (ll i = n - 1; i >= 0; i--){
        s.insert({v[i].end, -1 * i});
        contains[v[i].index] = s.order_of_key({v[i].end, -1 * i});
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