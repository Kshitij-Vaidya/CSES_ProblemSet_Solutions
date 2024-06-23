#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <cmath>
#include <climits>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;

    ordered_set<ll> s;
    for(ll i = 1; i <= n; i++){
        s.insert(i);
    }
    ll curr = 0;
    while (s.size() > 0){
        curr = (curr + k) % s.size();
        auto it = s.find_by_order(curr);
        cout << *it << " ";
        s.erase(it);
    }   
    return 0;
}