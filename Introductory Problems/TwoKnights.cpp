#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++){
        ll total_ways = i*i*(i*i-1)/2;
        ll attack_ways = 4*(i-1)*(i-2);
        cout << total_ways - attack_ways << endl;
    }
    return 0;
}