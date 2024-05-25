#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll a[n]; // Array of size n
    ll  moves = 0; // Counts the number of moves required to make the array sorted

    for (ll i = 0; i<n; i++){
        cin >> a[i];
        if (i>0 && a[i]<a[i-1])
        {
            moves += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }
    cout << moves << endl;
    return 0;
}