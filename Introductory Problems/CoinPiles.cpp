#include<iostream>
#include<vector>

typedef long long ll;
#define Loop(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

int main(){
    // If the total number of coins is a multiple of 3, then the answer is YES

    ll t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        if ((a+b)%3 == 0 && 2*a >= b && 2*b >= a){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}