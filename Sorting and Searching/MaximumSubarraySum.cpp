#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;

    ll max_sum = 0, current_sum = 0;
    while(n--){
        ll i; cin >> i;
        current_sum = max(i, current_sum + i);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << '\n';
    return 0;
}