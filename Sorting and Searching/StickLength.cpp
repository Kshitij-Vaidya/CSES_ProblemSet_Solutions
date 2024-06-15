#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    ll v[n];
    for (ll i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v, v+n);
    ll median = v[n/2];
    ll cost = 0;
    for(ll i : v){
        cost += abs(i - median);
    }
    cout << cost << '\n';
    return 0;
}