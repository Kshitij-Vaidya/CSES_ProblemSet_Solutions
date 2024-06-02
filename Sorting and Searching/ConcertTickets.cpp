#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    // Contains a frequency map of the tickets
    multiset<int> hash;

    while(n--){
        ll i; cin >> i;
        hash.insert(i);
    }

    while(m--){
        ll i; cin >> i;
        auto upper = hash.upper_bound(i);
        if (upper == hash.begin()){
            cout << -1 << '\n';
        } else {
            upper--;
            cout << *upper << '\n';
            hash.erase(upper);
        }
    }
    return 0;
}