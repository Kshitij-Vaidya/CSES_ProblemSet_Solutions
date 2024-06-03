#include<iostream>
#include<vector>
#include<climits>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;

    ll max_sum = LLONG_MIN, current_sum = 0;
    while(n--){
        ll i; cin >> i;
        current_sum += i;
        max_sum = max(max_sum, current_sum);
        if(current_sum < 0) current_sum = 0;
    }
    cout <<  max_sum << endl;
    return 0;
}