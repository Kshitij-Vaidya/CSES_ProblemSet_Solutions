#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    // Contains a frequency map of the tickets
    map<int, int> hash;

    while(n--){
        ll i; cin >> i;
        hash[i] += 1;
    }

    while(m--){
        auto upper = hash.upper_bound()
    }
    
}