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
    ll missing = 1;
    for(ll i = 0; i < n; i++){
        if(v[i] > missing){
            break;
        }
        missing += v[i];
    }
    cout << missing << '\n';
    return 0;
}