#include<iostream>
#include<algorithm>
#include<set>
#include<climits>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, n;
    cin >> x >> n;
    set<ll> s{0, x}; // Set to keep track of the placed traffic lights
    multiset<ll> d{x}; // Multiset to keep track of the distances between the traffic lights


    for(ll i = 0; i < n; i++){
        ll p; cin >> p;
        auto it = s.upper_bound(p);
        auto it2 = it; it2--;

        d.erase(d.find(*it - *it2));
        d.insert(p - *it2);
        d.insert(*it - p);
        s.insert(p);

        cout << *d.rbegin() << " ";
    }
    return 0;
}

